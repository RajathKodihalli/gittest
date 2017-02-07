#include "plotwindow.h"
#include <QHBoxLayout>
PlotWindow::PlotWindow(QWidget *parent) :
    QWidget(parent)
{
    plot_TabWiget = new QTabWidget(this);
    plot_TabWiget->setGeometry(0,0,1280,600);

    t_Graph = new plotGraph;
    t_tcSettings = new TCSettings;
    t_HistGraph = new HistPlotGraph;

    plot_TabWiget->addTab(t_Graph,"RealTime");
    plot_TabWiget->addTab(t_tcSettings,"Channel Settings");
    plot_TabWiget->addTab(t_HistGraph,"Historical");


//    pb_setting = new QPushButton;
    QHBoxLayout *hBox = new QHBoxLayout;
    hBox->addWidget(plot_TabWiget);
    setLayout(hBox);

}
void PlotWindow::resizeEvent( QResizeEvent *e )
{
    QWidget::resizeEvent(e);
   // t_Graph->setScreenSize(this->width(),this->height());
}
