#include "myprofile.h"
#include "ui_myprofile.h"
#include "employe.h"
#include"mainwindow.h"
#include<QMessageBox>

MyProfile::MyProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyProfile)
{
    ui->setupUi(this);
    employe e;
    ui->tabEmploye_2->setModel(e.read());
   // ui->tabEmploye->setModel(e.afficher());
}

MyProfile::~MyProfile()
{
    delete ui;
}

void MyProfile::on_pb_ajouter_2_clicked()
{
    int id=ui->lineEdit_id_3->text().toInt();
    QString prenom=ui->lineEdit_prenom->text();
    QString nom=ui->lineEdit_2->text();
    QDate date2=ui->dateEdit->date();
    QString sexe=ui->lineEdit_sexe->text();
    QString cin=ui->lineEdit_cin->text();
    QString adr=ui->lineEdit_adr->text();
    QString tel=ui->lineEdit_tel->text();
    employe e(id,prenom,nom,date2,sexe,cin,adr,tel);
    bool test=e.ajouter();
    if(test)
    {
        ui->tabEmploye_2->setModel(e.afficher("select *from TABLE3"));
        //QMessageBox::information(nullptr,QObject::tr("Ajouter un employé"),QObject::tr("click cancel to exit."),QMessageBox::Cancel);

    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Ajouter un employé"),QObject::tr("Erreur !. \n" "Click Cancel to exit."),QMessageBox::Cancel);
    }

}



void MyProfile::on_lineEdit_rech_textChanged(const QString &arg1)
{
QString r;
r="select *from TABLE3 where ID like "+arg1;
ui->tabEmploye_2->setModel(e.afficher(r));
}

void MyProfile::on_pb_supp_clicked()
{
    int id=ui->lineEdit_rech->text().toInt();
        bool test=e.supprimer(id);
        if(test)
        {
            ui->tabEmploye_2->setModel(e.afficher("select *from TABLE3"));
            //QMessageBox::information(nullptr,QObject::tr("Supprimer un employé"),QObject::tr("Employé supprimé. \n" "Click cancel to exit."),QMessageBox::Cancel);

        }
        else {
            QMessageBox::critical(nullptr,QObject::tr("Supprimer un employé"),QObject::tr("Erreur! .\n" "Click Cancel to exit."),QMessageBox::Cancel);
        }
}


void MyProfile::on_pb_tri_clicked()
{
     ui->tabEmploye_2->setModel(e.trieID());
}




/*void MyProfile::on_pushButton_rech2_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("select *from TABLE2 where ID=:ID");

    int id=ui->lineEdit_rech->text().toInt();
    query.bindValue(":ID",id);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("TELEPHONE"));



        ui->tabEmploye_2->setModel(model);
}*/

void MyProfile::on_pushButton_clicked()
{


hide();

}



/*void MyProfile::on_pushButton_mod_clicked()
{
    if(ui->tabEmploye_2->currentIndex().row()!=-1)
    {
        if(ui->
    }
}*/

void MyProfile::on_pushButton_mod_clicked()
{

    int id=ui->lineEdit_id_3->text().toInt();
    QString prenom=ui->lineEdit_prenom->text();
    QString nom=ui->lineEdit_2->text();
    QDate date2=ui->dateEdit->date();
    QString sexe=ui->lineEdit_sexe->text();
    QString cin=ui->lineEdit_cin->text();
    QString adr=ui->lineEdit_adr->text();
    QString tel=ui->lineEdit_tel->text();
    employe e(id,prenom,nom,date2,sexe,cin,adr,tel);
    bool test=e.modifer();
    if(test)
    {
        ui->tabEmploye_2->setModel(e.afficher("select *from table3"));
        //QMessageBox::information(nullptr,QObject::tr("Modifier employé"),QObject::tr("Employé modifé \n""appuier cancel pour sortir"),QMessageBox::Cancel);

    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Modifier employé"),QObject::tr("Erreur\n""appuier cancel pour sortir"),QMessageBox::Cancel);
    }


}
