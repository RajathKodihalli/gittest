#ifndef CHANNELDATAMANAGER_H
#define CHANNELDATAMANAGER_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <QList>
#include <QTimer>
class channelDataManager : public QObject
{
    Q_OBJECT
public:
    virtual ~channelDataManager();
    static channelDataManager *getInstance();
private:
    explicit channelDataManager(QObject *parent = 0);
    static channelDataManager *self;

    QString chName;
    QDateTime dataDateTime;
    double chTmpVal;
    //channelDataList will have channel name,datetime and val
    QList <QStringList> channelDataList;
    //this is for only stimulation
    QStringList onlyChannelData;

   //call the below to setdata
    void setChannelData(QString chName,QDateTime dataDateTime, double chTemp);
    void setChannelData(QStringList list);
    // it return the ch data of given channel
    QList<QString> getChannelData(QString);

    //for simulation
    QTimer *chDataTimer;
    double plotData;
signals:
    void sendChannelVal(double);
public slots:
    void stimulatechannelData();
};

#endif // CHANNELDATAMANAGER_H
