/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : ListImpl.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
 Date        : 02.05.2017

 But         : Implémentation de la classe List<T>

 Remarque(s) : R.A.S.

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */


#ifndef LISTIMPL_HPP
#define LISTIMPL_HPP

#include <stdexcept>

/*----------------------Node---------------------*/

template <typename T>
List<T>::Node::Node(): previous(nullptr),
                       next(nullptr)
{}

template <typename T>
List<T>::Node::Node(const T &d): data(d),
                                 previous(nullptr),
                                 next(nullptr)
{}

template <typename T>
typename List<T>::Node *List<T>::Node::getPrevious() {
    return previous;
}

template <typename T>
typename List<T>::Node *List<T>::Node::getNext() {
    return next;
}

template <typename T>
T& List<T>::Node::getData() {
    return data;
}

template <typename T>
void List<T>::Node::setPrevious(List::Node *n) {
    previous = n;
}

template <typename T>
void List<T>::Node::setNext(List<T>::Node *n) {
    next = n;
}

template <typename T>
bool List<T>::Node::hasNext() {
    return next != nullptr;
}

template <typename T>
bool List<T>::Node::hasPrevious() {
    return previous != nullptr;
}

template <typename T>
bool List<T>::Node::operator==(const List::Node &n) {
    return data == n.data;
}

/*-----------------------Iterator------------------------*/

template <typename T>
typename List<T>::Node* List<T>::Iterator::getNode() const {
    return node;
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator=(const List::Iterator &it) {
    return *(new Iterator(it));
}

template <typename T>
bool List<T>::Iterator::operator==(const List::Iterator &it) {
    return *node == *(it.node);
}

template <typename T>
bool List<T>::Iterator::operator!=(const List::Iterator &it) {
    return !(*node == *(it.node));
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator++() {
    if(node->hasNext()) {
        node = node->getNext();
    }
    return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    Iterator it(*this);
    this->operator++();
    return it;
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator--() {
    if(node->hasPrevious()) {
        node = node->getPrevious();
    }
    return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
    Iterator it(*this);
    this->operator--();
    return it;
}

template <typename T>
T& List<T>::Iterator::operator*() const{
    return node->getData();
}

/*------------------------List----------------------------*/

template <typename T>
List<T>::List():_size(0),
                head(new Node()),
                tail(new Node())
{
    head->setNext(tail);
    tail->setPrevious(head);
}

template <typename T>
List<T>::List(const T& d):_size(1),
                          head(new Node()),
                          tail(new Node()){
    Node* e = new Node(d);
    head->setNext(e);
    e->setPrevious(head);
    tail->setPrevious(e);
    e->setNext(tail);
}

template <typename T>
List<T>::List(const List& l): List()
{
    for(Iterator it = l.begin(); it != l.end(); it++){
        append(*it);
    }
}

template <typename T>
List<T>::~List(){
    clear();
}

template <typename T>
int List<T>::size() const{
    return _size;
}

template <typename T>
void List<T>::insert(const T& d){
    Node* e = new Node(d);
    if(head->getNext() != tail){
        Node* oldHeadNext = head->getNext();
        e->setNext(head->getNext());
        e->setPrevious(head);
        oldHeadNext->setPrevious(e);
        head->setNext(e);
    }
    else{
        head->setNext(e);
        e->setPrevious(head);
        tail->setPrevious(e);
        e->setNext(tail);
    }
    _size++;
}

template <typename T>
void List<T>::append(const T& d){
    Node* e = new Node(d);
    if(head->getNext() != tail){
        Node* oldPreviousTail = tail->getPrevious();
        tail->setPrevious(e);
        e->setNext(tail);
        oldPreviousTail->setNext(e);
        e->setPrevious(oldPreviousTail);
    }
    else{
        head->setNext(e);
        e->setPrevious(head);
        tail->setPrevious(e);
        e->setNext(tail);
    }
    _size++;
}

template <typename T>
void List<T>::remove(const T& d) {

    for(List<T>::Iterator it = begin(); it != end(); it++) {
        if(*it == d) {

            Node* currentNode = it.getNode();

            currentNode->getPrevious()->setNext(currentNode->getNext());
            currentNode->getNext()->setPrevious(currentNode->getPrevious());

            delete currentNode;
            _size--;

            break;
        }
     }
    cout << "Element inexistant !" << endl;
}

template <typename T>
void List<T>::removeAt(const int index) {
    if (index >= _size) {
        throw std::out_of_range("Out of range !");
    }

    Iterator it = begin();
    for(int i = 0; i < index; i++) {
        ++it;
    }

    Node* currentNode = it.getNode();

    currentNode->getPrevious()->setNext(currentNode->getNext());
    currentNode->getNext()->setPrevious(currentNode->getPrevious());

    delete currentNode;
    _size--;
}

template <typename T>
T& List<T>::operator [](const int index) {

    if (index >= _size) {
        throw std::out_of_range("Out of range !");
    }

    Iterator it = begin()++;

    for(int i = 0; i < index; i++) {
        ++it;
    }
    return *it;
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &l) {
    clear();
    List<T> _return = new List(l);
    return _return;
}

template <typename T>
typename List<T>::Iterator List<T>::find(const T &d) {
    for(List<T>::Iterator it = begin(); it != end(); it++) {
        if(*it == d) {
            return it;
        }
    }
    return --end();
}

template <typename T>
typename List<T>::Iterator List<T>::begin() const {
    return *(new Iterator(head->getNext()));
}

template <typename T>
typename List<T>::Iterator List<T>::end() const {
    return *(new Iterator(tail));
}

template <typename T>
typename List<T>::Iterator List<T>::rbegin() const {
    return *(new Iterator(tail->getPrevious()));
}

template <typename T>
typename List<T>::Iterator List<T>::rend() const {
    return *(new Iterator(head));
}

template <typename T>
void List<T>::clear() {
    for(List<T>::Iterator it = begin(); it != end(); it++){
        delete it.getNode();
    }
    delete head;
    delete tail;
}

template <typename T>
ostream &operator <<(ostream &os, const List<T>& l) {
    for(typename List<T>::Iterator it = l.begin(); it != l.end(); it++){
        os << *it << " ";
    }
    return os;
}

#endif /* LISTIMPL_HPP */
