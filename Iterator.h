#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include "E:\Projects\S3\Laboratorio_CC_II\T14_ListaEnlazadaGenerica\ListaEnlazadaGenerica.h"

template <typename T>
class ListaEnlazadaGenerica;

template <typename T>
class Iterator{
    private:
        ListaEnlazadaGenerica<T>* lista;
        Node<T>* it;
    public:
    //CONSTRUCTOR
        Iterator(ListaEnlazadaGenerica<T>* _lista){
            lista = _lista;
        }

    // BEGIN
        void get_first(){
            this->it = lista->begin(); 
        }

    // END
        void get_end(){
            this->it = lista->end(); 
        }

    // FINISH
        bool finish(){
            return (this->it == nullptr);
        }

    //SOBRECARGA DEL OPERADOR DE CONTENIDO
        T content() const{
            return it->get_value();
        }

    //--
        void operator--(int){
            Node<T>* tmp = lista->begin(), *ant = nullptr;
            while(tmp!=this->it){
                ant = tmp;
                tmp = tmp->get_next();
            }
            this->it = ant;
        }

    //++
        void operator ++(int){
            this->it = this->it->get_next();
        }
};

#endif