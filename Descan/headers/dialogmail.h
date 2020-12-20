#ifndef DIALOGMAIL_H
#define DIALOGMAIL_H

#include <QDialog>
#include <curl/curl.h>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <ctime>
#include <string>
#include <cstdio>
#include <cstring>
#include <QProgressDialog>
#include <QTimer>

namespace Ui {
class DialogMail;
}

class DialogMail : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMail(QWidget *parent = nullptr,QStringList filePathsPdf = {});
    ~DialogMail();
    QString fileName;
    QStringList m_filePathsPdf;

private slots:
    void on_pbExit_clicked();
    void on_pbBrowse_clicked();
    void on_pbSend_clicked();


private:
    Ui::DialogMail *ui;
};

#endif // DIALOGMAIL_H