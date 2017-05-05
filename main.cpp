/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 15 : Liste générique
 Fichier     : main.cpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 05.05.2017

 But         : Fourni une série de tests de la classe List

 Remarque(s) : R.A.S.

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>

#include "List.hpp"
#include "Person.hpp"

using namespace std;

template <typename T>
void affichage(const List<T>& l){
    cout << "Liste : " << l<< endl;
}

int main() {

    /*--------------------- List<int> --------------------------*/

    cout << "------------------ Test List<int> ------------------" << endl;
    cout << "Creation liste avec l'element 1" << endl;
    List<int> lInt(1);
    affichage(lInt);
    cout << endl;

    cout << "Insertion (debut) de l'element 2" << endl;
    lInt.insert(2);
    affichage(lInt);
    cout << endl;

    cout << "Insertion (fin) de l'element 3" << endl;
    lInt.append(3);
    affichage(lInt);
    cout << endl;

    cout << "Modification avec du 2 eme element (index 1) en 5" << endl;
    lInt[1] = 5;
    affichage(lInt);
    cout << endl;

    cout << "Suppression de l'element a l'index 2" << endl;
    lInt.removeAt(2);
    affichage(lInt);
    cout << endl;

    cout << "Ajout de quelques element" << endl;
    lInt.append(4);
    lInt.append(42);
    lInt.append(38);
    lInt.append(76);
    affichage(lInt);
    cout << endl;

    cout << "Supression de l'element 42" << endl;
    lInt.remove(42);
    affichage(lInt);
    cout << endl;

    cout << "Supression d'un element inexistant"  << endl;
    lInt.remove(53);
    affichage(lInt);
    cout << endl;

    cout << "Retour de la taille de la liste" << endl;
    int a = lInt.size();
    affichage(lInt);
    cout << "Taille liste : " << a << endl;
    cout << endl;

    cout << "Recherche de l'element 5 dans la liste et affichage" << endl;
    List<int>::Iterator it = lInt.find(5);
    cout << "Element : " << *it << endl;
    cout << endl;


    /*--------------------- List<string> -----------------------*/
    cout << "------------------ Test List<string> ------------------" << endl;
    cout << "Creation liste avec l'element 1" << endl;
    List<string> lstring("salut");
    affichage(lstring);
    cout << endl;

    cout << "Insertion (debut) de l'element 2" << endl;
    lstring.insert("fromage");
    affichage(lstring);
    cout << endl;

    cout << "Insertion (fin) de l'element 3" << endl;
    lstring.append("abricot");
    affichage(lstring);
    cout << endl;

    cout << "Modification avec du 2 eme element (index 1) en \"salade\" " << endl;
    lstring[1] = "salade";
    affichage(lstring);
    cout << endl;

    cout << "Suppression de l'element a l'index 2" << endl;
    lstring.removeAt(2);
    affichage(lstring);
    cout << endl;

    cout << "Ajout de quelques element" << endl;
    lstring.append("lutin");
    lstring.append("filou");
    lstring.append("retard");
    lstring.append("cff");
    affichage(lstring);
    cout << endl;

    cout << "Supression de l'element filou" << endl;
    lstring.remove("filou");
    affichage(lstring);

    cout << "Supression d'un element inexistant \"dragon\""  << endl;
    lstring.remove("dragon");
    affichage(lstring);
    cout << endl;

    cout << "Retour de la taille de la liste" << endl;
    int b = lstring.size();
    affichage(lstring);
    cout << "Taille liste : " << b << endl;
    cout << endl;

    cout << "Recherche de l'element \"abricot\" dans la liste et affichage" << endl;
    List<string>::Iterator is = lstring.find("abricot");
    cout << "Element : " << *is << endl;
    cout << endl;


    /*------------------------- List<Person> -----------------------*/
    //Tests avec des personnes et des classe qui en hérite.

    cout << "------------------ Test List<Person> ------------------" << endl;
    List<Person*> people;
    Person *person  = new Person("Bilbon", 10);
    Person *warrior = new Warrior("Ragnar", 150, 100);
    Person *wizard  = new Wizard("Gandalf", 50, 100);

    people.append(person);
    people.append(warrior);
    people.append(wizard);

    for(List<Person*>::Iterator p1 = people.begin(); p1 != people.end(); p1++) {
        for(List<Person*>::Iterator p2 = people.begin(); p2 != people.end(); p2++) {
            (*p1)->fight(*(*p2));
        }
    }

    delete person;
    delete warrior;
    delete wizard;

    return EXIT_SUCCESS;
}