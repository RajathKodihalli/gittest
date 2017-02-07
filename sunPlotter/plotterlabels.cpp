#include "plotterlabels.h"
#include <QTableWidget>
#include <QTableView>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QScrollArea>
PlotterLabels::PlotterLabels(QWidget *parent) :
    QWidget(parent)//,m_mainLayout(this)
{
    setFixedWidth(150);

   // m_mainLayout.addWidget(&m_area);
    tb_histPlotLabels = new QTableWidget(this);
    tb_histPlotLabels->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    tb_histPlotLabels->setRowCount(100);
    tb_histPlotLabels->setFixedWidth(150);
//    tb_histPlotLabels->setItem(0,1, new QTableWidgetItem(QString("HAI")));

 /*   QVBoxLayout * layout = new QVBoxLayout(tb_histPlotLabels);
    layout->setSizeConstraint(QLayout::SetMinimumSize);
    m_area.setWidget(tb_histPlotLabels)*/;
    //createtable data
    QStringList t_list;
    t_list << "Style" << "Color";
    setHzHeaderData(t_list);
    setOneRowData(t_list);
}


void PlotterLabels::setHzHeaderData(QStringList t_headerList)
{
    hzHeadercolList = t_headerList;
    tb_histPlotLabels->setColumnCount(hzHeadercolList.count());
    tb_histPlotLabels->setHorizontalHeaderLabels(hzHeadercolList);
}

void PlotterLabels::setOneRowData(QStringList t_oneRowDataList)
{
    allRowDataList.append(t_oneRowDataList);
    addOneRowData();
}

void PlotterLabels::setAllData(QList <QStringList> t_allDataList)
{
    allRowDataList = t_allDataList;
}

void PlotterLabels::addOneRowData()
{
    tb_histPlotLabels->setRowCount(allRowDataList.count()+1);
    tb_histPlotLabels->insertRow(1);
    //cursorDataTable->setRowCount(oneRowDataList.count());
    for (int rowCount=0;rowCount<allRowDataList.count(); rowCount++)
    {
        QStringList t_rList(allRowDataList.at(rowCount));
        for (int cellCount=0; cellCount<t_rList.count(); cellCount++)
        {
            tb_histPlotLabels->setItem(rowCount,cellCount, new QTableWidgetItem(t_rList.at(cellCount)));
        }
    }
   tb_histPlotLabels->update();
}

void PlotterLabels::addAllData()
{

}

void PlotterLabels::closeEvent(QCloseEvent * e)
{
}

