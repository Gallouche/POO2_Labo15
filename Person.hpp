/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 15 : Liste générique
 Fichier     : Person.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 05.05.2017

 But         : Fourni une classe person pour tester la classe liste

 Remarque(s) : R.A.S.

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string.h>
#include <iostream>

using namespace std;

class Person {
protected:
    string _name;
    int _life;
public:

    /**
     * Constructeur de person
     * @param name nom de la personne
     * @param life nombre de pv
     */
    Person(string name, int life) : _name(name), _life(life) {};

    /**
     * Destructeur de personne
     */
    virtual ~Person() {}

    /**
     * Fait combattre contre une autre personne
     * @param p l'autre personne
     */
    virtual void fight(const Person& p) {
        cout << this->getTitle() + " attaque " + p.getTitle() << endl;
        cout << "Je n'ai pas d'arme !" << endl << endl;
    }

    /**
     * Renvoir le titre du personnage [genre + nom]
     * @return le titre
     */
    virtual string getTitle() const { return "[Personne : " + _name + "]"; }
};

class Warrior : public Person {
private:
    int _strength;
public:

    /**
     * Constructeur de warrior
     * @param name nom du warrior
     * @param life nombre de pv
     * @param strength quantite de force
     */
    Warrior(string name, int life, int strength) : Person(name, life), _strength(strength) {}

    /**
     * Destructeur de warrior
     */
    virtual ~Warrior() {}

    /**
     * Fait combattre contre une autre personne
     * @param p l'autre personne
     */
    virtual void fight(const Person& p) {
        cout << this->getTitle() + " attaque " + p.getTitle() << endl;
        cout << "Je frappe avec mon gourdin !" << endl << endl;
    }

    /**
     * Renvoir le titre du personnage [genre + nom]
     * @return le titre
     */
    virtual string getTitle() const { return "[Warrior : " + _name + "]"; }
};

class Wizard : public Person {
private:
    int _mana;
public:
    /**
     * Constructeur de wizard
     * @param name nom du wizard
     * @param life nombre de pv
     * @param mana quantite de mana
     */

    Wizard(string name, int life, int mana) : Person(name, life), _mana(mana) {}
    /**
     * Destructeur de wizard
     */
    virtual ~Wizard() {}

    /**
     * Fait combattre contre une autre personne
     * @param p l'autre personne
     */
    virtual void fight(const Person& p) {
        cout << this->getTitle() + " attaque " + p.getTitle() << endl;
        cout << "Je lance un sort avec mon baton !" << endl << endl;
    }

    /**
     * Renvoir le titre du personnage [genre + nom]
     * @return le titre
     */
    virtual string getTitle() const { return "[Wizard : " + _name + "]"; }
};

#endif //PERSON_HPP