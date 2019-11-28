#ifndef MYPROFILE_H
#define MYPROFILE_H
#include"employe.h"
#include <QDialog>



namespace Ui {
class MyProfile;
}

class MyProfile : public QDialog
{
    Q_OBJECT

public:
    explicit MyProfile(QWidget *parent = nullptr);
    ~MyProfile();

private slots:
    void on_pb_ajouter_2_clicked();

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_pb_supp_clicked();

    void on_pb_tri_clicked();

    void on_tabWidget_3_destroyed();

    //void on_pushButton_rech2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_mod_clicked();

private:
    Ui::MyProfile *ui;
    employe e;


};

#endif // MYPROFILE_H
