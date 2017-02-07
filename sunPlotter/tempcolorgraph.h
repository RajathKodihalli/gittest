#ifndef TEMPCOLORGRAPH_H
#define TEMPCOLORGRAPH_H

#include <QWidget>
#include "qcustomplot.h"

class TempColorGraph : public QWidget
{
    Q_OBJECT
public:
    explicit TempColorGraph(QWidget *parent = 0);

    void setupDemo(int demoIndex);
    void setupColorMapDemo(QCustomPlot *customPlot);
private:
    QCustomPlot *customPlot;
    QString demoName;
    QTimer dataTimer;
    QCPItemTracer *itemDemoPhaseTracer;
    int currentDemoIndex;
signals:

public slots:

};

#endif // TEMPCOLORGRAPH_H
