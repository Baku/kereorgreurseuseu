#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QtGui>

class MyWindow : public QWidget
{
  Q_OBJECT


public:
 /*   MyWindow();
    ~MyWindow();*/
    void run();
    QPushButton         *add;
    QPushButton         *del;
    QPushButton         *edit;

    QStringList         feedlist;
    QStringListModel    *feedlistmodel;
    QListView           *feedview;

    QStringList         *itemlist;
    QStringListModel    *itemlistmodel;
    QListView           *itemview;

private:
    QStringList         flux;
public slots:
    void addRss();
    void delRss();
    void editRss();
};

#endif // MYWINDOW_H
