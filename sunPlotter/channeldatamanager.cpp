#include "channeldatamanager.h"
#include <math.h>
#include "qcustomplot.h"
#define NO_OF_CHANNELS 576
channelDataManager * channelDataManager::self;

channelDataManager *channelDataManager::getInstance()
{
    if (!self)
    {
        self=new channelDataManager();
    }
    return self;
}

channelDataManager::channelDataManager(QObject *parent) :
    QObject(parent)
{

    //intialize
    chName = "";
    //dataDateTime="";
    chTmpVal=0.0;
    //timer for stimulation
    chDataTimer = new QTimer;
    connect(chDataTimer,SIGNAL(timeout()), this, SLOT(stimulatechannelData()));
    chDataTimer->start(100);
}
channelDataManager::~channelDataManager()
{

}

void channelDataManager::stimulatechannelData()
{
    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    double val=0.1000;
    //for (int chCount=0; chCount<NO_OF_CHANNELS; chCount++)
   // {
        QList <double> list;
        plotData = qCos(key)+qrand()/(double)RAND_MAX*100*qSin(key/(0.4364));
        //val+=0.0500;
    //  list.append(ch1);
        //onlyChannelData.append(QString::number(ch1));
      //  plotData.append(list);
    //}
         emit sendChannelVal(plotData);


}

//call the below to setdata
 void channelDataManager::setChannelData(QString chName,QDateTime dataDateTime, double chTemp)
 {
     QStringList t_list;
     t_list << chName << dataDateTime.toString() << QString::number(chTemp);
     channelDataList.append(t_list);

 }

 void channelDataManager::setChannelData(QStringList list)
 {
     channelDataList.append(list);
 }

 // it return the ch data of given channel
 QList <QString> channelDataManager::getChannelData(QString)
 {
     QList<QString> list;
    return list;
 }
