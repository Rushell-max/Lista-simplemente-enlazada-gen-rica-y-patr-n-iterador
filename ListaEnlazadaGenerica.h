#ifndef __LISTAENLAZADAGENERICA_H__
#define __LISTAENLAZADAGENERICA_H__
#include "E:\Projects\S3\Laboratorio_CC_II\T14_ListaEnlazadaGenerica\Node.h"
#include "E:\Projects\S3\Laboratorio_CC_II\T14_ListaEnlazadaGenerica\Iterator.h"

template <typename T>
class ListaEnlazadaGenerica;

template <typename T>
std::ostream& operator <<(std::ostream &o, const ListaEnlazadaGenerica<T>& L);

template <typename T>
class ListaEnlazadaGenerica {
    private:
        int size;
        Node<T>* head;
    public:
    
        friend class Iterator<T>;
        Iterator<T>* crearIterador(){
            return new Iterator<T>(this);
        }
    //CONSTRUCTORES Y DESTRUCTORES
        //CONSTRUCTORES PRINCIPALES
        ListaEnlazadaGenerica();
        ListaEnlazadaGenerica(T);
        //CONSTRUCTOR COPIA
        ListaEnlazadaGenerica(const ListaEnlazadaGenerica<T> &);   
        //SOBRECARGA DEL OPERADOR COPIA
        ListaEnlazadaGenerica& operator =(const ListaEnlazadaGenerica<T> &o){
            std::cout<<" EN SOBRECARGA DEL OPERADOR COPIA ";
            this->size = 0;
            this->head = nullptr;
            if( this != &o ){
                Node<T>* temp = o.head;
                while (temp){
                    this->push_back(temp->get_value());
                    temp = temp->get_next();
                }
            }
            return *this;
        }
        //CONSTRUCTOR DE MOVIMIENTO
        ListaEnlazadaGenerica(ListaEnlazadaGenerica<T> &&);
        //SOBRECARGA DEL OPERADOR DE MOVIMIENTO
        ListaEnlazadaGenerica& operator =(ListaEnlazadaGenerica<T> &&o){
            std::cout<<" EN SOBRECARGA DEL OPERADOR DE MOVIMIENTO ";
            this->size = 0;
            this->head = nullptr;
            Node<T>* temp = o.head;
            while (temp){
                this->push_back(temp->get_value());
                temp = temp->get_next();
            }
            o.~ListaEnlazadaGenerica();
            return *this;
        }
        //DESTRUCTOR
        ~ListaEnlazadaGenerica();
    
    //SETTERS
        void set_size(int _size){ this->size = _size; }
        void set_head(Node<T>* _head){ this->head = _head; }
        
    // GETTERS
        int get_size() const{ return size; }
        Node<T>* get_head() const{ return head; }

    //INSERCIÓN
        //PUSH-FRONT
        void push_front(const T &);
        //PUSH-BACK
        void push_back(const T &);
        //INSERT - POS
        void insert(const T &, const int &);

    //ELIMINACIÓN
        //POP-FRONT
        void pop_front();
        //POP-BACK
        void pop_back();
        //REMOVE - POS
        void remove_by_position(const int&);
    
    //OTRAS
        //Retorna el valor del primer elemento de nuestra lista.
        T front();
        //Retorna el valor del ultimo elemento de nuestra lista.
        T back();
        //Retorna 0 o 1 si la lista esta vacia o no.
        bool empty();
        //Elimina los elementos de la lista, que son iguales al elemento dado.
        void remove(const T &);
        //Invierte la lista.
        void reverse();

    //ITERADOR
        Node<T>* begin();
        Node<T>* end();

    friend std::ostream& operator << <>(std::ostream &salida1,const ListaEnlazadaGenerica<T>& L);
};

template <typename T>
std::ostream & operator <<(std::ostream &salida1,const ListaEnlazadaGenerica<T>& L){
    Node<T>* actual = L.head; 
    if(!L.head){
        salida1<<"\n\t > LISTA VACIA ";
    }else{
        salida1 <<"\n\t LISTA (SIZE="<<L.get_size()<<") >> ";
        salida1 <<" [ ";
        while(actual!=nullptr){
            salida1 << actual->get_value()<<" "/**<<actual<<" "**/;
            actual = actual->get_next();
        }
        salida1 << "] ";
    }return salida1;
}

#endif