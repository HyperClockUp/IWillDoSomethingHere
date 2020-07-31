#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();
    this->loginDlg = new LoginDlg(this);
    getMusicTags();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getMusicTags()
{
    Json::Value res = Service::getMusicTags();
    Json::Value tags = res["tags"];
    ItemModel = new QStandardItemModel(this);

    int nCount = tags.size();
    for(int i = 0; i < nCount; i++)
    {
        Json::Value playlistTag = tags[i]["playlistTag"];
        QString string = QString::fromStdString(playlistTag["name"].asString());
        QStandardItem *item = new QStandardItem(string);
        ItemModel->appendRow(item);
    }
   ui->listView->setModel(ItemModel);
   ui->listView->setFixedSize(200,300);
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{

}
