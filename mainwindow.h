#ifndef MAINWINDOW_H
#include <QDebug>
#include"service.h"
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "logindlg.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void getMusicTags();
    ~MainWindow();

private slots:
    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    LoginDlg *loginDlg;
    QStringListModel *Model;
    QStandardItemModel *ItemModel;
};
#endif // MAINWINDOW_H
