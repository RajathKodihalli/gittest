#include "plotgraph.h"
#include "tempcolorgraph.h"
#include <QApplication>
#include "channelselector.h"
#include "plotwindow.h"
#include "tcsettings.h"
#include "showdataatcursor.h"
#include "plotterlabels.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    plotGraph w;
    //PlotWindow w;
    //w.showMaximized();
    w.show();

    //TempColorGraph t;
    //t.show();
    //channelSelector chsel;
    //chsel.show();
    //TCSettings tc;
    //tc.show();
    //ShowDataAtCursor cD;
    //cD.show();
//PlotterLabels pl;
//pl.show();
    return a.exec();
}
