/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 15 : Liste générique
 Fichier     : main.cpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
 Date        : 01.05.2017

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>

#include "List.hpp"
#include "Person.h"

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

    cout << "Insertion (debut) de l'element 2" << endl;
    lInt.insert(2);
    affichage(lInt);

    cout << "Insertion (fin) de l'element 3" << endl;
    lInt.append(3);
    affichage(lInt);

    cout << "Modification avec du 2 eme element (index 1) en 5" << endl;
    lInt[1] = 5;
    affichage(lInt);

    cout << "Suppression de l'element a l'index 2" << endl;
    lInt.removeAt(2);
    affichage(lInt);

    cout << "Ajout de quelques element" << endl;
    lInt.append(4);
    lInt.append(42);
    lInt.append(38);
    lInt.append(76);
    affichage(lInt);

    cout << "Supression de l'element 42" << endl;
    lInt.remove(42);
    affichage(lInt);

    cout << "Supression d'un element inexistant"  << endl;
    lInt.remove(53);
    affichage(lInt);

    cout << "Retour de la taille de la liste" << endl;
    int a = lInt.size();
    affichage(lInt);
    cout << "Taille liste : " << a << endl;

    cout << "Recherche de l'element 5 dans la liste et affichage" << endl;
    List<int>::Iterator it = lInt.find(5);
    cout << "Element : " << *it << endl;


    /*--------------------- List<string> -----------------------*/

//    List<string> l("deux");
//    l.insert("un");
//    l.append("trois");
//
//    cout << "Liste : ";
//    cout << l << endl;
//
//
//    List<string>::Iterator it = l.find("");
//    cout << endl << "Recherche deux : " << *it << endl;
//
//    List<string> l2 = l;
//    cout << endl << "Liste copie : ";
//    for(List<string>::Iterator it = l2.begin(); it != l2.end(); it++){
//        cout << *it << " ";
//    }
//    cout << endl;
//
//
//    l.remove("un");
//    cout << endl << "Liste sans un : ";
//    for(List<string>::Iterator it = l.begin(); it != l.end(); it++) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    l.removeAt(0);
//    cout << endl << "Liste sans un deux : ";
//    for(List<string>::Iterator it = l.begin(); it != l.end(); it++) {
//        cout << *it << " ";
//    }
//    cout << endl << endl;
//
//
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