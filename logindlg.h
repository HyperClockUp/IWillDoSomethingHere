#ifndef LOGINDLG_H
#include "utils.h"
#include "service.h"
#define LOGINDLG_H

#include <QDebug>
#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = nullptr);
    ~LoginDlg();

private slots:
/*    void on_requestBtn_clicked();
    void slot_replayFinished(QNetworkReply *reply)*/;
    void on_commandLinkButton_clicked();

private:
    Ui::LoginDlg *ui;
    QWidget *parent = NULL;
};

#endif // LOGINDLG_H
