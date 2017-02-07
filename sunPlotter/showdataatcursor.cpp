#include "showdataatcursor.h"
#define NO_OFCHANNELS 50

ShowDataAtCursor::ShowDataAtCursor(QDialog *parent) :
    QDialog(parent),m_mainLayout(this)
{
    setModal(true);
    m_mainLayout.addWidget(&m_area);
    cursorDataTable = new QTableWidget(this);
    cursorDataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    cursorDataTable->setRowCount(100);
    cursorDataTable->setGeometry(0,0,this->width(),this->height());
    cursorDataTable->setItem(0,1, new QTableWidgetItem(QString("HAI")));

    QVBoxLayout * layout = new QVBoxLayout(cursorDataTable);
    layout->setSizeConstraint(QLayout::SetMinimumSize);
    m_area.setWidget(cursorDataTable);
    //createtable data
    QStringList t_list;
    t_list << "Style" << "Ch Name" << "Description" << "Current Value" << "Value at Cursor" << "Time of Cursor";
    setHzHeaderData(t_list);
    setOneRowData(t_list);


}


void ShowDataAtCursor::setHzHeaderData(QStringList t_headerList)
{
    hzHeadercolList = t_headerList;
    cursorDataTable->setColumnCount(hzHeadercolList.count());
    cursorDataTable->setHorizontalHeaderLabels(hzHeadercolList);
}

void ShowDataAtCursor::setOneRowData(QStringList t_oneRowDataList)
{
    allRowDataList.append(t_oneRowDataList);
    addOneRowData();
}

void ShowDataAtCursor::setAllData(QList <QStringList> t_allDataList)
{
    allRowDataList = t_allDataList;
}

void ShowDataAtCursor::addOneRowData()
{
    cursorDataTable->setRowCount(allRowDataList.count()+1);
    cursorDataTable->insertRow(1);
    //cursorDataTable->setRowCount(oneRowDataList.count());
    for (int rowCount=0;rowCount<allRowDataList.count(); rowCount++)
    {
        QStringList t_rList(allRowDataList.at(rowCount));
        for (int cellCount=0; cellCount<t_rList.count(); cellCount++)
        {
            cursorDataTable->setItem(rowCount,cellCount, new QTableWidgetItem(t_rList.at(cellCount)));
        }
    }
   cursorDataTable->update();
}

void ShowDataAtCursor::addAllData()
{

}

void ShowDataAtCursor::closeEvent(QCloseEvent * e)
{
    emit ShowDataAtCursorClosed();
}
