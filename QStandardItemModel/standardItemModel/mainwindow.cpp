#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
   // ui(new Ui::MainWindow)
{
   // ui->setupUi(this);
    rf = new readFile(this);

    QStringList dataStr = rf->text.split(QRegExp("\\s+"));

    qDebug() << dataStr.count();
    qDebug() << "dataStr: " <<  dataStr.count();

    treeView = new QTreeView(this);
    this->setCentralWidget(treeView);
    model = new QStandardItemModel;

    QStringList header;
    header << "DB" << "BOA" << "CITI" << "ABN" << "JPM";
    model->setHorizontalHeaderLabels(header);
    item = model->invisibleRootItem();

    this->fillModel(dataStr);





    //Create Invisable root
    //The invisible root item provides access to the model's top-level items through the QStandardItem API,
    //making it possible to write functions that can treat top-level items and their children in a uniform way;
    //for example, recursive functions involving a tree model.


/*
    QList<QStandardItem*> row1 = prepareRow("25.25", "50.25", "500.11", "89.45", "45.74");

    item->appendRow(row1);

*/

    treeView->setModel(model);


}

MainWindow::~MainWindow()
{
    //  delete ui;
}

QList<QStandardItem*> MainWindow::prepareRow(const QString& db, const QString &boa, const QString& citi, const QString& abn, const QString& jpm)
{
    QList<QStandardItem*> row;
    row << new QStandardItem(db);
    row << new QStandardItem(boa);
    row << new QStandardItem(citi);
    row << new QStandardItem(abn);
    row << new QStandardItem(jpm);

    return row;
}

void MainWindow::fillModel(QStringList & dataStr)
{
    QString db, boa, citi, abn, jpm;

         int n = 0;
     while(n < dataStr.count())
          {
             qDebug() << dataStr[n];
             db = dataStr[n];
             boa = dataStr[n + 1];
             citi = dataStr[n + 2];
             abn = dataStr[n + 3];
             jpm = dataStr[n + 4];


             QList<QStandardItem*> row1 = prepareRow(db, boa, citi, abn, jpm);
             item->appendRow(row1);
             n += 5;
          }

}
