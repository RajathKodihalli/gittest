#ifndef TCSETTINGS_H
#define TCSETTINGS_H

#include <QWidget>
#include "channelselector.h"
#include <QRadioButton>
#include <QVBoxLayout>
#include <QScrollArea>

class TCSettings : public QWidget
{
    Q_OBJECT
public:
    explicit TCSettings(QWidget *parent = 0);

private:
    channelSelector *tcSelector;
    QRadioButton *r_selectChannel;
    QRadioButton *r_LineStyle;
    QRadioButton *r_lineThinkness;
    QRadioButton *r_lineColor;
    QRadioButton *r_showAll;

    QVBoxLayout m_mainLayout;
    QScrollArea m_area;

    void resizeEvent( QResizeEvent *e );
signals:

public slots:

};

#endif // TCSETTINGS_H
