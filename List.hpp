/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 15 : Liste générique
 Fichier     : List.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
 Date        : 01.05.2017

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LIST_H
#define LIST_H

template <typename T>
class List {

    class Node {
    public:

        Node();
        /**
         * Constructeur de la classe interne Element
         * @param d la data a stocker de type T
         */
        Node(const T& d);

        Node* getPrevious();
        Node* getNext();
        T& getData();
        void setPrevious(Node* n);
        void setNext(Node* n);
        bool operator == (const Node& n);
        bool hasNext();
        bool hasPrevious();

    private:
        T data;
        Node* previous;
        Node* next;
    };

public:
    class Iterator{

    public:
        Iterator();
        Iterator(Node* e): node(e){};
        Iterator(const Iterator& it);
        virtual ~Iterator();

        Node* getNode() const;
        Iterator& operator = (const Iterator& it);
        bool operator == (const Iterator& it);
        bool operator != (const Iterator& it);
        Iterator& operator ++ ();
        Iterator operator ++ (int);
        Iterator& operator -- ();
        Iterator operator -- (int);
        T& operator * () const;

    private:
        Node* node;
    };

    /**
     * Constructeur par défaut
     */
    List<T>();

    List<T>(const T& d);
    /**
  * Constructeur de copie
  * @param l liste a copier
  */
    List<T>(const List<T>& l);

    /**
     * Destructeur par défaut
     */
    virtual ~List<T>();

    /**
    * Accesseur sur la taille de la liste
    * @return taille de la liste
    */
    int size() const;

    /**
    * Insere un élément de type T dans la list
    * @param d élément a inserer
    */
    void insert(const T& d);

    void append(const T& d);

    List<T>& operator = (const List<T>& l);

    T& operator [](const int index);

    void remove(const T d);

    void remove(const int index);

    Iterator find(const T& d);

    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();



private:
    int _size;
    Node* head;
    Node* tail;
};



#include "ListImpl.hpp"

#endif /* LIST_H */

