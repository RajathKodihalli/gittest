#ifndef PLOTGRAPH_H
#define PLOTGRAPH_H

#include <QWidget>
#include <QTimer>
#include "qcustomplot.h"
#include "channeldatamanager.h"
#include "showdataatcursor.h"
class plotGraph : public QWidget
{
    Q_OBJECT

public:
    plotGraph(QWidget *parent = 0);
    ~plotGraph();
    void setupRealtimeData(QCustomPlot *customPlot);
    void setScreenSize(int,int);
    void resizeCustomplot();
    //for historical plat stop the timer
    void stopRealtimeData();
private slots:
  void realtimeDataSlot();
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

#endif // PLOTGRAPH_H
