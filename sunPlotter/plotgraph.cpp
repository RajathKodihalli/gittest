#include "plotgraph.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>

plotGraph::plotGraph(QWidget *parent)
    : QWidget(parent)
{
   chDataMan = channelDataManager::getInstance();
    customPlot = new QCustomPlot(this);
    customPlot->xAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->setGeometry(0,0,this->width(),this->height());
    customPlot->setInteractions(QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iSelectAxes | QCP::iSelectPlottables);
    connect(chDataMan,SIGNAL(sendChannelVal(double)),this,SLOT(getDataFromDM(double)));
   // setupDemo(7);
    setupRealtimeData(this->customPlot);
    customPlot->replot();
    connect(customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(showCursorDataDialog(QMouseEvent*)));
    dataAtCursor = new ShowDataAtCursor;
    connect(dataAtCursor,SIGNAL(ShowDataAtCursorClosed()),this,SLOT(resumePlotGraph()));

}
void plotGraph::resizeCustomplot()
{
   customPlot->replot();
}

void plotGraph::setScreenSize(int w,int h)
{
  this->setGeometry(0,0,w,h);
  customPlot->setGeometry(0,0,w,h);
  customPlot->replot();
}

plotGraph::~plotGraph()
{

}


void plotGraph::getDataFromDM(double d)
{
    pStimulateData= d;
}
void plotGraph::stopRealtimeData()
{
    dataTimer.stop();
}

void plotGraph::resizeEvent( QResizeEvent *e )
{
    QWidget::resizeEvent(e);
    customPlot->setGeometry(0,0,this->width(),this->height());
    this->customPlot->replot();
}

void plotGraph::setupRealtimeData(QCustomPlot *customPlot)
{
  demoName = "Real Time Data Demo";

  // include this section to fully disable antialiasing for higher performance:
/*
  customPlot->setNotAntialiasedElements(QCP::aeAll);
  QFont font;
  font.setStyleStrategy(QFont::NoAntialias);
  customPlot->xAxis->setTickLabelFont(font);
  customPlot->yAxis->setTickLabelFont(font);
  customPlot->legend->setFont(font);
*/
  //for (int chCount=0; chCount< pStimulateData.count(); chCount++)
 // {
     customPlot->addGraph(); // blue line
      customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
//      customPlot->addGraph(); // red line
//      customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));
//      customPlot->addGraph(); // red line
//      customPlot->graph(2)->setPen(QPen(QColor(255, 110, 150)));
   // }
  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  customPlot->xAxis->setTicker(timeTicker);
  customPlot->axisRect()->setupFullAxesBox();
  //customPlot->yAxis->setRange(-1.2, 1.2);
  customPlot->yAxis->setRange(-200,200);
customPlot->yAxis2->setRange(-100,200);


  // make left and bottom axes transfer their ranges to right and top axes:
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  dataTimer.start(100); // Interval 0 means to refresh as fast as possible
}

void plotGraph::realtimeDataSlot()
{
  static QTime time(QTime::currentTime());
  // calculate two new data points:
  double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  //if (key-lastPointKey > 0.002) // at most add point every 2 ms
  if (key-lastPointKey > 002) // at most add point every 2 ms
  {

    // add data to lines:
   //   for (int chCount=0; chCount< pStimulateData.count(); chCount++)
   //  {
          //double val =pStimulateData.at(0);
        //customPlot->graph(chCount)->addData(key,pStimulateData.at(chCount));
          customPlot->graph(0)->addData(key,pStimulateData);
    //  }
    // rescale value (vertical) axis to fit the current data:
    //customPlot->graph(0)->rescaleValueAxis();
   // customPlot->graph(1)->rescaleValueAxis(true);
    //customPlot->graph(2)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  customPlot->replot();
}

void plotGraph::bracketDataSlot()
{
  double secs = QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime());

  // update data to make phase move:
  int n = 500;
  double phase = secs*5;
  double k = 3;
  QVector<double> x(n), y(n);
  for (int i=0; i<n; ++i)
  {
    x[i] = i/(double)(n-1)*34 - 17;
    y[i] = qExp(-x[i]*x[i]/20.0)*qSin(k*x[i]+phase);
  }
  customPlot->graph()->setData(x, y);

  itemDemoPhaseTracer->setGraphKey((8*M_PI+fmod(M_PI*1.5-phase, 6*M_PI))/k);

  customPlot->replot();

  // calculate frames per second:
  double key = secs;
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    //statusBar->showMessage(
      //    QString("%1 FPS, Total Data points: %2")
        //  .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          //.arg(ui->customPlot->graph(0)->data()->size())
          //, 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}

void plotGraph::showCursorDataDialog(QMouseEvent *event)
{
    // if an axis is selected, only allow the direction of that axis to be dragged
    // if no axis is selected, both directions may be dragged

      if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    {
        qDebug() << "1";
          customPlot->axisRect()->setRangeDrag(customPlot->xAxis->orientation());
          if(dataAtCursor->isVisible())
          {
              dataAtCursor->hide();
              dataTimer.start(100);
              customPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels);
              customPlot->replot();
            }
          else
          {
              dataAtCursor->show();
              dataTimer.stop();
          }
    }
}

void plotGraph::resumePlotGraph()
{
    dataTimer.start(100);
    qDebug() << "Timer Stop";
    customPlot->replot();
}

