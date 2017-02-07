#ifndef CHANNELSELECTOR_H
#define CHANNELSELECTOR_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QRect>
#include <QList>

class QPainter;

class channelSelector : public QWidget
{
    Q_OBJECT
public:
    explicit channelSelector(QWidget *parent = 0);

signals:

public slots:

private:
    void paintEvent(QPaintEvent *e);
    void changeEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void resizeEvent( QResizeEvent *e );
    void createChannelsRects(int);


    QList<QRect> chRect;
    QList<int> listColor;
    int totalWidth;
    int totalHeight;
    bool mousePressed;
    QPixmap mPix;
    QRect mRect;
   bool drawStarted;

};

#endif // CHANNELSELECTOR_H
