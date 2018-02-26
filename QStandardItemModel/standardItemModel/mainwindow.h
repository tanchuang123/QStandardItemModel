#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTreeView>
#include <QListView>
#include <QList>
#include <QDebug>
#include "readfile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QStandardItem数据组织的基本单位为数据项
    QList<QStandardItem*> prepareRow(const QString &db, const QString &boa, const QString &citi, const QString &abn, const QString &jpm);

private:
  //  Ui::MainWindow *ui;
    QTreeView *treeView;//通过Qt之QTreeView（一）即可正常加载数据，Qt之QTreeView（二）即可自定义图标、按钮，注册事件等
    QStandardItemModel *model;//类QStandardItemModel将类QStandardItem表示的数据项组织起来,形成列表、表格、树甚至更复杂的数据结构
    readFile *rf;
    void fillModel(QStringList & dataStr);
     QStandardItem *item;
};

#endif // MAINWINDOW_H
