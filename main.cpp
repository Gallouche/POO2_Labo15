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

    cout << l[1] << endl;

//    for(List<int>::Iterator it = l.begin(); it != l.end(); it++){
//        cout << *it << endl;
//    }

//    for(List<int>::Iterator it = l.rbegin(); it != l.rend(); --it){
//        cout << *it << endl;
//    }

    return EXIT_SUCCESS;
}