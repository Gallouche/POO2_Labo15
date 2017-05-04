//
// Created by Pierre-Samuel Rochat on 04.05.17.
//

#ifndef PERSON_H
#define PERSON_H

#include <string.h>
#include <iostream>

using namespace std;

class Person {
protected:
    string _name;
    int _life;
public:
    Person(string name, int life) : _name(name), _life(life) {};
    virtual ~Person() {}
    virtual void fight(const Person& p) {
        cout << this->getTitle() + " attaque " + p.getTitle() << endl;
        cout << "Je n'ai pas d'arme !" << endl << endl;
    }
    virtual string getTitle() const { return "Personne " + _name; }
};

class Warrior : public Person {
private:
    int _strength;
public:
    Warrior(string name, int life, int strength) : Person(name, life), _strength(strength) {}
    virtual ~Warrior() {}
    virtual void fight(const Person& p) {
        cout << this->getTitle() + " attaque " + p.getTitle() << endl;
        cout << "Je frappe avec mon gourdin !" << endl << endl;
    }
    virtual string getTitle() const { return "Warrior " + _name; }
};

class Wizard : public Person {
private:
    int _mana;
public:
    Wizard(string name, int life, int mana) : Person(name, life), _mana(mana) {}
    virtual ~Wizard() {}
    virtual void fight(const Person& p) {
        cout << this->getTitle() + " attaque " + p.getTitle() << endl;
        cout << "Je lance un sort avec mon baton !" << endl << endl;
    }
    virtual string getTitle() const { return "Wizard " + _name; }
};

#endif //PERSON_H
