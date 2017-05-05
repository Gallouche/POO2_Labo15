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
         * Constructeur de la classe interne Node
         * @param d la data a stocker de type T
         */
        Node(const T& d);

        /**
         * Getter
         * @return pointeur sur le noeud precedent
         */
        Node* getPrevious();

        /**
         * Getter
         * @return pointeur sur le noeud suivant
         */
        Node* getNext();

        /**
         * Getter
         * @return l'element contenu par le noeud
         */
        T& getData();

        /**
         * Setter pour le noeud precedent
         * @param n pointeur sur le noeud
         */
        void setPrevious(Node* n);

        /**
         * Setter pour le noeud suivant
         * @param n pointeur sur le noeud
         */
        void setNext(Node* n);

        /**
         * Permet de savoir si le noeud a un noeud suivant
         * @return true ou false
         */
        bool hasNext();

        /**
         * Permet de savoir si le noeud a un noeud precedent
         * @return true ou false
         */
        bool hasPrevious();

        /**
          * Operateur de comparaison, permet de comparer deux noeuds
          * @param n reference sur le 2nd noeud
          * @return true ou false
          */
        bool operator == (const Node& n);

    private:
        // Data contenu par le noeud
        T data;
        // Pointeur sur le noeud precedent
        Node* previous;
        // Pointeur sur le noeud suivant
        Node* next;
    };

public:
    class Iterator{

    public:
        /**
         * Constructeur sans parametres de la classe interne Iterator
         */
        Iterator(): node(nullptr) {};

        /**
         * Constructeur de la classe interne Iterator a partir d'un noeud
         * @param pointeur sur le noeud
         */
        Iterator(Node* e): node(e){};

        /**
         * Constructeur de la classe interne Iterator a partir d'un autre iterateur
         * @param it l'iterateur
         */
        Iterator(const Iterator& it): node(it.node) {};

        /**
         * Destructeur de la classe interne Iterator
         */
        virtual ~Iterator(){};

        /**
         * Getteur pour acceder au noeud courent
         * @return pointeur sur le noeud
         */
        Node* getNode() const;

        /**
         * Operateur d'affectation
         * @param it reference sur l'iterateur a copier
         * @return le nouvel iterateur
         */
        Iterator& operator = (const Iterator& it);

        /**
         * Operateur de comparaison, permet de comparer deux iterateurs
         * @param it reference sur le 2nd iterateur
         * @return true si ils sont egaux, false si il ne sont pas egaux
         */
        bool operator == (const Iterator& it);

        /**
         * Operateur de comparaison, permet de comparer deux iterateurs
         * @param it reference sur le 2nd iterateur
         * @return true si ils ne sont pas egaux, false si ils sont egaux
         */
        bool operator != (const Iterator& it);

        /**
         * Operateur d'incrementation prefixe
         * @return l'iterateur sur le noeud suivant
         */
        Iterator& operator ++ ();

        /**
         * Operateur d'incrementation postfixe
         * @return l'iterateur sur le noeud suivant
         */
        Iterator operator ++ (int);

        /**
         * Operateur de decrementation prefixe
         * @return l'iterateur sur le noeud precedent
         */
        Iterator& operator -- ();

        /**
         * Operateur de decrementation postfixe
         * @return l'iterateur sur le noeud precedent
         */
        Iterator operator -- (int);

        /**
         * Operateur de dereferencement
         * @return le data contenu par le noeud
         */
        T& operator * () const;

    private:

        // Noeud courant
        Node* node;

    };

    /**
     * Constructeur sans parametres
     */
    List<T>();

    /**
     * Constructeur a partir d'un element
     * @param d l'element
     */
    List<T>(const T& d);

    /**
    * Constructeur de copie
    * @param l liste a copier
    */
    List<T>(const List<T>& l);

    /**
     * Destructeur
     */
    virtual ~List<T>();

    /**
    * Accesseur sur la taille de la liste
    * @return taille de la liste
    */
    int size() const;

    /**
    * Insere un element de type T en tete de list
    * @param d element a inserer
    */
    void insert(const T& d);

    /**
    * Insere un element de type T en queue de list
    * @param d element a inserer
    */
    void append(const T& d);

    /**
    * Supprime le premier element correspondant a la valeur de d
    * @param d element a supprimer
    */
    void remove(const T& d);

    /**
    * Supprime l'element se trouvant a la position de l'index
    * @param index l'index de l'element a supprimer
    */
    void removeAt(const int index);

    /**
    * Operateur accesseur de liste
    * @param index l'index de l'element a acceder
    * @return l'element
    */
    T& operator [](const int index);

    /**
    * Operateur d'affectation
    * @param l la reference sur la liste a copier
    * @return la nouvelle liste
    */
    List<T>& operator = (const List<T>& l);

    /**
    * Retourne un iterateur sur le premier element de la liste correspondant a d
    * @param d la référence sur l'element
    * @return l'iterateur sur l'element
    */
    Iterator find(const T& d);

    /**
    * Retourne un iterateur sur le premier element de la liste
    * @return l'iterateur sur l'element
    */
    Iterator begin() const;

    /**
    * Retourne un iterateur sur la fin de la liste (apres le dernier element)
    * @return l'iterateur sur l'element
    */
    Iterator end() const;

    /**
    * Retourne un iterateur sur le premier element de la liste depuis la droite (dernier element de la liste)
    * @return l'iterateur sur l'element
    */
    Iterator rbegin() const;

    /**
    * Retourne un iterateur sur le debut de la liste depuis la droite (avant le premier element de la liste)
    * @return l'iterateur sur l'element
    */
    Iterator rend() const;

private:
    int _size;

    // Noeud se trouvant avant le premier element
    Node* head;
    // Noeud se trouvant apres le dernier element
    Node* tail;

    /**
    * Delete tous les noeuds de la liste
    */
    void clear();
};



#include "ListImpl.hpp"

#endif /* LIST_H */

