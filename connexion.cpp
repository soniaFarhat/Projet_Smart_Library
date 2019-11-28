#include "connexion.h"
#include<QSqlError>

connexion::connexion()
{


}
bool connexion::ouvrirConnexion()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
                 db.setDatabaseName("Source_Projet2A");
                 db.setUserName("sonia");
                 db.setPassword("esprit19");

    if (db.open())
        test=true;

    else throw QString ("Erreur Paramétres"+db.lastError().text());
    return  test;
    }
void connexion::fermerConnexion()
{
   db.close();
}
