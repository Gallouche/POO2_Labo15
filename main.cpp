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

int main() {

    List<string> l("deux");
    l.insert("un");
    l.append("trois");

    cout << "Liste : ";
    for(List<string>::Iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    List<string>::Iterator it = l.find("");
    cout << endl << "Recherche deux : " << *it << endl;

    List<string> l2 = l;
    cout << endl << "Liste copie : ";
    for(List<string>::Iterator it = l2.begin(); it != l2.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


    l.remove("un");
    cout << endl << "Liste sans un : ";
    for(List<string>::Iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    l.removeAt(0);
    cout << endl << "Liste sans un deux : ";
    for(List<string>::Iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << endl;


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