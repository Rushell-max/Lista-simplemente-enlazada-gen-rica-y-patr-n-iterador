#include "E:\Projects\S3\Laboratorio_CC_II\T14_ListaEnlazadaGenerica\ListaEnlazadaGenerica.h"

template <typename T>
ListaEnlazadaGenerica<T>::ListaEnlazadaGenerica(){
    this->size = 0;
    this->head = nullptr;
}

template <typename T>
ListaEnlazadaGenerica<T>::ListaEnlazadaGenerica(T _value){
    this->size = 0;
    this->head = new Node<T>(_value);
}

template <typename T>
ListaEnlazadaGenerica<T>::ListaEnlazadaGenerica(const ListaEnlazadaGenerica<T> &o){
    std::cout<<" EN CONSTRUCTOR COPIA ";
    this->size = 0;
    this->head = nullptr;
    if( this != &o ){
        Node<T>* temp = o.head;
        while (temp){
            this->push_back(temp->get_value());
            temp = temp->get_next();
        }
    }
}

template <typename T>
ListaEnlazadaGenerica<T>::ListaEnlazadaGenerica(ListaEnlazadaGenerica<T> &&o){
    std::cout<<" EN CONSTRUCTOR DE MOVIMIENTO ";
    this->size = 0;
    this->head = nullptr;
    Node<T>* temp = o.head;
    while (temp){
        this->push_back(temp->get_value());
        temp = temp->get_next();
    }
    o.~ListaEnlazadaGenerica();
}

template <typename T>
ListaEnlazadaGenerica<T>::~ListaEnlazadaGenerica(){
    //std::cout<<"\n\t >> ELIMINANDO LISTA >> ";
    this->size = 0;
    Node<T> *actual;
    while (head){
        actual = head->get_next();
        delete head;
        head = actual;
    }
    delete head;
}

template <typename T>
void ListaEnlazadaGenerica<T>::push_front(const T &_value){
    Node<T>* newNode = new Node<T>(_value);
    if(head==nullptr){
        head = newNode;
    }else{
        newNode->set_next(head);
        head = newNode;
    }size++;
}

template <typename T>
void ListaEnlazadaGenerica<T>::push_back(const T &_value){
    Node<T>* newNode = new Node<T>(_value);
    if(head==nullptr){
        head = newNode;
    }else{
        Node<T>* tmp = head;
        while (tmp->get_next()){
            tmp = tmp->get_next();
        }
        tmp->set_next(newNode);
    }size++;
}

template <typename T>
void ListaEnlazadaGenerica<T>::insert(const T &_value, const int &_pos){
    if(_pos > size){
        std::cout<<"\n\t Fuera de rango ! "<<_pos<<" "<<size<<" ";
        return;
    }if(_pos == 0){
        push_front(_value);
        return;
    }
    Node<T>* newNode = new Node<T>(_value);
    Node<T>* tmp = head, *ant = nullptr;
    for(int i=0; i<_pos; i++){
        ant = tmp;
        tmp = tmp->get_next();
    }
    newNode->set_next(tmp);
    ant->set_next(newNode);
    size++;
}

template <typename T>
void ListaEnlazadaGenerica<T>::pop_front(){
    head = head->get_next();
    size--;
}

template <typename T>
void ListaEnlazadaGenerica<T>::pop_back(){
    Node<T>* tmp = head, *ant;
    if(size==1){
        head = nullptr;
        size--;
    }else{
        while(tmp->get_next()){
            ant = tmp;
            tmp = tmp->get_next();
        }
        ant->set_next(nullptr);
        size--;
    }
}

template <typename T>
void ListaEnlazadaGenerica<T>::remove_by_position(const int &_pos){
    if(_pos >= size){
        std::cout<<"\n\t Fuera de rango ! ";
        return;
    }if(_pos == 0){
        pop_front();
    }else{
        Node<T>* tmp = head, *ant = nullptr;
        for(int i=0; i<_pos; i++){
            ant = tmp;
            tmp = tmp->get_next();
        }
        ant->set_next(tmp->get_next());
        size--;
    }
}

template <typename T>
T ListaEnlazadaGenerica<T>::front(){
    return head->get_value();
}

template <typename T>
T ListaEnlazadaGenerica<T>::back(){
    return this->end()->get_value();
}

template <typename T>
bool ListaEnlazadaGenerica<T>::empty(){
    return (head==nullptr);
}

template <typename T>
void ListaEnlazadaGenerica<T>::remove(const T & _value){
    Node<T>* tmp = head; int pos = 0;
    while(tmp->get_next()){
        if(tmp->get_value() == _value){
            remove_by_position(pos);
            pos--;
        }tmp = tmp->get_next();
        pos++;
    }if(tmp->get_value() == _value){
        remove_by_position(pos);
    }
}

template <typename T>
void ListaEnlazadaGenerica<T>::reverse(){
    ListaEnlazadaGenerica<int> l2;
    Iterator<int>* it = this->crearIterador();
    for(it->get_end(); !it->finish(); (*it)--){
        l2.push_back(it->content());
    }*this = std::move(l2);
}

template <typename T>
Node<T>* ListaEnlazadaGenerica<T>::begin(){
    return head;
}

template <typename T>
Node<T>* ListaEnlazadaGenerica<T>::end(){
    Node<T>* tmp = head; 
    while (tmp->get_next()){
        tmp = tmp->get_next();
    }return tmp;
}