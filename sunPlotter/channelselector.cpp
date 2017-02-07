#include "channelselector.h"
#include <QPainter>
#include <QDebug>

#define TOTAL_CHANNELS 60
channelSelector::channelSelector(QWidget *parent) :
    QWidget(parent)
{

   //paint = new QPainter;
    //setGeometry(0,0,qApp->desktop()->width()-100,qApp->desktop()->height()-100);
    //setFixedHeight((TOTAL_CHANNELS));
    totalWidth=this->width();
    totalHeight=this->height();
    createChannelsRects(TOTAL_CHANNELS);
    mPix = QPixmap(400,400);
    mPix.fill(Qt::white);
    //set everything to false as nothing has started yet
    mousePressed = false;
    drawStarted = false;
}

void channelSelector::paintEvent(QPaintEvent *e)
{
    QPainter paint(this);
    //paint.setBackground(QBrush(QColor(Qt::blue)));
    //paint->begin(this);
    QFont font("Arial",9,QFont::Bold);
    paint.setFont(font);
    //paint.setPen(QColor(255,255,255));
    for(int count=0; count<TOTAL_CHANNELS; count++)
    {

        if(listColor.at(count))
        {
             paint.fillRect(chRect.at(count),QColor(255,69,0));
        }
        else
        {
             paint.fillRect(chRect.at(count),QColor(Qt::gray));
        }
        paint.drawRect(chRect.at(count));
        paint.setPen(QColor(255,255,255));
        paint.drawText(chRect.at(count),Qt::AlignCenter,QString::number(count+1));
    }

    if(mousePressed){
            // we are taking QPixmap reference again and again
            //on mouse move and drawing a line again and again
            //hence the painter view has a feeling of dynamic drawing
            paint.setPen(Qt::PenStyle(Qt::DashLine));
            paint.drawRect(mRect);
            drawStarted = true;
    } else if (drawStarted){
       // QPainter tempPainter(&mPix);
        paint.setPen(Qt::PenStyle(Qt::DashLine));
        // paint.drawRect(mRect);
        // paint.fillRect(mRect,QBrush(QColor(128, 128, 255, 128)));
       //  paint.drawPixmap(0,0,mPix);
           //paint.fillRect(mRect,QColor(Qt::blue));
//           for(int count=0; count<50; count++)
//           {
//                //if(chRect.at(count).contains(mRect.intersected()))
//               if(mRect.intersects(chRect.at(count)))
//                {
//                       //paint.fillRect(chRect.at(count),QColor(Qt::red));
//                   listColor[count] = 1;
//                }
//               else
//               {
//                   listColor[count] = 0;
//               }

//           }

    }
    update();
 }

void channelSelector::createChannelsRects(int totalChannels)
{
    int chWidth=totalWidth/10;
    int chHeight=totalHeight/5;
    int chXpoint=0;
    int chYpoint=0;
    for(int count=0; count<totalChannels/5; count++)
    {
        chYpoint = chHeight*count;
        chXpoint = 0;
        for(int count=0; count<totalChannels/6; count++)
        {
            QRect rect(chXpoint,chYpoint,chWidth,chHeight);
            chXpoint+=chWidth;
            chRect.append(rect);
            listColor.append(0);

        }

    }
}

void channelSelector::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange)
    {
        // if (this->isMaximized() || !this->isVisible()) {
          totalWidth=this->width();
          totalHeight=this->height();
          createChannelsRects(TOTAL_CHANNELS);
          repaint();
          qDebug() << "Got max";
          return;
          //}
    }
}

void channelSelector::mousePressEvent(QMouseEvent *event)
{
    //Mouse is pressed for the first time
    mousePressed = true;

    //set the initial line points, both are same
    mRect.setTopLeft(event->pos());
    mRect.setBottomRight(event->pos());
    qDebug() << "Mouse pressed";
}

void channelSelector::mouseReleaseEvent(QMouseEvent *event)
{
    //When mouse is released update for the one last time
    mousePressed = false;

    for(int count=0; count<TOTAL_CHANNELS; count++)
    {
         //if(chRect.at(count).contains(mRect.intersected()))
        if(mRect.intersects(chRect.at(count)))
         {
                //paint.fillRect(chRect.at(count),QColor(Qt::red));
            if(listColor[count] == 1)
            {
                listColor[count] = 0;
            }
            else
                listColor[count] = 1;
         }
//        else
//        {
//            listColor[count] = 0;
//        }

    }
    update();
    qDebug() << "Mouse released";
}
void channelSelector::mouseMoveEvent(QMouseEvent *event)
{
    //As mouse is moving set the second point again and again
     // and update continuously
     if(event->type() == QEvent::MouseMove){
            mRect.setBottomRight(event->pos());
    }

     //it calls the paintEven() function continuously
     update();
}

void channelSelector::resizeEvent( QResizeEvent *e )
{
    QWidget::resizeEvent(e);
    update();
}
