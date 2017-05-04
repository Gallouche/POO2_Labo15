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

using namespace std;

int main() {

    List<int> l(3);
    l.insert(2);
    l.insert(1);
    l.append(4);

    List<int> l2(l), l3;
    l3 = l2;


    cout << "Liste : ";
    for(List<int>::Iterator it = l.begin(); it != l.end(); it++){
        cout << *it;
    }
    cout << endl << "Liste copie constructeur: ";

    for(List<int>::Iterator it = l2.begin(); it != l2.end(); it++){
        cout << *it;
    }

    cout << endl << "Liste copie affectation: ";

    for(List<int>::Iterator it = l3.begin(); it != l3.end(); it++){
        cout << *it;
    }
    cout << endl;

    return EXIT_SUCCESS;
}