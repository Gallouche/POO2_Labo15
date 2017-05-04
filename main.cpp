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

    List<string> l("deux");
    l.insert("un");
    l.append("trois");
    int a = l.size();
    for(List<string>::Iterator it = l.begin(); it != l.end(); it++){
        cout << *it << endl;
    }

    cout << endl;

    l.remove("un");

    for(List<string>::Iterator it = l.begin(); it != l.end(); it++){
        cout << *it << endl;
    }

    cout << endl;

    l[1] = "dixhuit";

    for(List<string>::Iterator it = l.begin(); it != l.end(); it++){
        cout << *it << endl;
    }

    /*
    for(List<int>::Iterator it = l.rbegin(); it != l.rend(); it--){
        cout << *it << endl;
    }
     */

//    for(List<int>::Iterator it = l.begin(); it != l.end(); it++){
//        cout << *it << endl;
//    }

//    for(List<int>::Iterator it = l.rbegin(); it != l.rend(); --it){
//        cout << *it << endl;
//    }

    return EXIT_SUCCESS;
}