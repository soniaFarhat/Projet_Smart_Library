#include "employe.h"
#include<QtDebug>
#include <QSqlQueryModel>

employe::employe()
{
    id=0;
    nom=" ";
    prenom=" ";

}
employe::employe(int id,QString prenom,QString nom,QDate date,QString cin,QString adr,QString tel,QString sexe)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->date=date;
    this->cin=cin;
    this->adr=adr;
    this->tel=tel;
    this->sexe=sexe;
}
QString employe::get_nom(){return nom;}
QString employe::get_prenom(){return prenom;}
int employe::get_id(){return id;}
bool employe::modifer()
{
    QSqlQuery q;
    q.prepare("UPDATE TABLE3 SET ID= :id ,PRENOM= :prenom,NOM= :nom,DATE_NAISSANCE= :date,SEXE= :sexe,CIN= :cin,ADRESSE= :adr,TELEPHONE= :tel where ID= :id ");
    q.bindValue(":id",id);
    q.bindValue(":prenom",prenom);
    q.bindValue(":nom",nom);
    q.bindValue(":date",date);
    q.bindValue(":sexe",sexe);
    q.bindValue(":cin",cin);
    q.bindValue(":adr",adr);
    q.bindValue(":tel",tel);
    return(q.exec());
}
bool employe::ajouter()
{
   QSqlQuery query;
   QString res=QString::number(id);
   query.prepare("INSERT INTO table3(ID,PRENOM,NOM,DATE_NAISSANCE,SEXE,CIN,ADRESSE,TELEPHONE) " "VALUES(:id, :prenom, :nom, :date_naissance, :sexe, :cin, :adresse, :telephone)");
   query.bindValue(":id", res);
   query.bindValue(":prenom", prenom);
   query.bindValue(":nom", nom);
   query.bindValue(":date_naissance",date);
   query.bindValue(":sexe",sexe);
   query.bindValue(":cin",cin);
   query.bindValue(":adresse",adr);
   query.bindValue(":telephone",tel);

   return    query.exec();
}
QSqlQueryModel * employe::afficher(QString r)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery(r);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("TELEPHONE"));



    return model;
}

bool employe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from table3 where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel *employe::trieID()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select *from table3 order by ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("TELEPHONE"));




        return model;

}
QSqlQueryModel *employe::read()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select *from table3");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("TELEPHONE"));
    return model;

}

