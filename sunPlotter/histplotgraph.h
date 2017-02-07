#ifndef HISTPLOTGRAPH_H
#define HISTPLOTGRAPH_H

#include <QWidget>
#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "channeldatamanager.h"
#include "showdataatcursor.h"

class HistPlotGraph : public QWidget
{
    Q_OBJECT
public:
    explicit HistPlotGraph(QWidget *parent = 0);
    void setupRealtimeData(QCustomPlot *customPlot);
    void setScreenSize(int,int);
    void resizeCustomplot();

private slots:
  void histDataPlotSlot();
  void bracketDataSlot();
  void getDataFromDM(double);
//  void screenShot();
//  void allScreenShots();

  void showCursorDataDialog(QMouseEvent *event);
  void resumePlotGraph();


private:
  QCustomPlot *customPlot;
  QString demoName;
  QTimer dataTimer;
  QCPItemTracer *itemDemoPhaseTracer;
  int currentDemoIndex;
  void resizeEvent( QResizeEvent *e );
  channelDataManager *chDataMan;
  //ch no and temp val
  double pStimulateData;
  ShowDataAtCursor *dataAtCursor;
 };
#endif // HISTPLOTGRAPH_H
