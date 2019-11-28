#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class employe
{
public:
    employe();
    employe(int,QString,QString,QDate,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    QSqlQueryModel *afficher(QString r);
    bool supprimer(int);
     QSqlQueryModel *trieID();
     bool modifer();
     QSqlQueryModel *read();
private:
    QString nom,prenom,cin,adr,tel,sexe;
    int id;
    QDate date;
};

#endif // EMPLOYE_H
