#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QWidget>
#include "plotgraph.h"
#include <QPushButton>
#include <QTabWidget>
#include "tcsettings.h"
#include "histplotgraph.h"
class PlotWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWindow(QWidget *parent = 0);

private:
    QTabWidget *plot_TabWiget;
    plotGraph *t_Graph;
    HistPlotGraph *t_HistGraph;
    TCSettings *t_tcSettings;
    QPushButton *pb_setting;
    void resizeEvent( QResizeEvent *e );
signals:

public slots:

};

#endif // PLOTWINDOW_H
