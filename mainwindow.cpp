#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/asus/Desktop/2eme annee/projet c++/qt pic/user7");
    int w= ui->label_pic->width();
    int h= ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Login_pushButton_clicked()
{
    QString username=ui->username_LineEdit->text();
    QString password=ui->password_LineEdit->text();
    if(username=="sonia farhat" && password=="14320120")
    {
        hide();
        mp=new MyProfile(this);
        mp->exec();
        show();
    }
    else {
        if (password!="14320120")
        {
          QMessageBox::warning(this,"Login","un nom d'utilisateur ou un mot de passe incorrect.");
        }
        else {
            {
                 QMessageBox::warning(this,"Login","un nom d'utilisateur ou un mot de passe incorrect.");
            }
        }
    }



}
