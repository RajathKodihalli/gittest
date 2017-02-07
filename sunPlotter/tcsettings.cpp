#include "tcsettings.h"
#include <QBoxLayout>
#include <QVBoxLayout>
TCSettings::TCSettings(QWidget *parent) :
    QWidget(parent)
{

   // setGeometry(0,0,qApp->desktop()->width()-100,qApp->desktop()->height()-100);

    QWidget *optionsTab = new QWidget;
    optionsTab->setFixedHeight(50);
    r_selectChannel = new QRadioButton("Channel");
    r_LineStyle = new QRadioButton("LineStyle");
    r_lineThinkness= new QRadioButton("Thinkness");
    r_lineColor= new QRadioButton("lineColor");
    r_showAll= new QRadioButton("ShowAll");

    QHBoxLayout *hBlayout = new QHBoxLayout;
    hBlayout->addWidget(r_selectChannel);
    hBlayout->addWidget(r_LineStyle);
    hBlayout->addWidget(r_lineThinkness);
    hBlayout->addWidget(r_lineColor);
    hBlayout->addWidget(r_showAll);
    optionsTab->setLayout(hBlayout);

    QVBoxLayout *vBLayout = new QVBoxLayout;
    tcSelector = new channelSelector();
    vBLayout->addWidget(optionsTab);
    vBLayout->addWidget(tcSelector);
    setLayout(vBLayout);

}

void TCSettings::resizeEvent( QResizeEvent *e )
{
    QWidget::resizeEvent(e);
    update();
 }
