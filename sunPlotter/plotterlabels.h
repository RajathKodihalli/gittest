#ifndef PLOTTERLABELS_H
#define PLOTTERLABELS_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QScrollArea>
class PlotterLabels : public QWidget
{
    Q_OBJECT
public:
    explicit PlotterLabels(QWidget *parent = 0);
    void setHzHeaderData(QStringList);
    void setOneRowData(QStringList);
    void setAllData(QList <QStringList>);
private:
    QTableWidget *tb_histPlotLabels;
    QStringList hzHeadercolList;
    QStringList oneRowDataList;
    QList <QStringList> allRowDataList;

    void addOneRowData();
    void addAllData();

    int totalRows;
    int totalCols;
    void closeEvent(QCloseEvent *e);
    QVBoxLayout m_mainLayout;
    QScrollArea m_area;
signals:


public slots:

};

#endif // PLOTTERLABELS_H
