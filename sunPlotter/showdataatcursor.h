#ifndef SHOWDATAATCURSOR_H
#define SHOWDATAATCURSOR_H

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QScrollArea>

class ShowDataAtCursor : public QDialog
{
    Q_OBJECT
public:
    explicit ShowDataAtCursor(QDialog *parent = 0);

    void setHzHeaderData(QStringList);
    void setOneRowData(QStringList);
    void setAllData(QList <QStringList>);
private:
    QTableWidget *cursorDataTable;
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
      void ShowDataAtCursorClosed();

public slots:

};

#endif // SHOWDATAATCURSOR_H
