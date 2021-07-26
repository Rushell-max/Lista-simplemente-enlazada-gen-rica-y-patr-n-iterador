#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node;

template <typename T>
std::ostream& operator <<(std::ostream &o, const Node<T> &_Node);

template<typename T>
class Node{    
    public:
    //CONSTRUCTORES Y DESTRUCTORES
        //CONSTRUCTORES PRINCIPALES
        Node(T _value = 0 , Node<T>* _next = nullptr):
            value(_value), next(_next){}
        //CONSTRUCTOR COPIA
        Node(const Node<T> &);   
        //SOBRECARGA DEL OPERADOR COPIA
        Node& operator =(const Node<T> &_o){
            std::cout<<" EN SOBRECARGA DEL OPERADOR COPIA ";
            if(this != &_o){
                this->value = _o.get_value();
                this->next = new Node<T>(*_o.get_next());
            }return *this;
        }
        //CONSTRUCTOR DE MOVIMIENTO
        Node(Node<T> &&);
        //SOBRECARGA DEL OPERADOR DE MOVIMIENTO
        Node& operator =(Node<T> &&_o){
            std::cout<<" EN SOBRECARGA DEL OPERADOR DE MOVIMIENTO ";
            if(this != &_o){
                this->value = _o.get_value();
                Node<T> *tmp = _o.next;
                _o.~Node();
                this->next = new Node<T>(std::move(*tmp));
            }
            return *this;
        }
        //DESTRUCTOR
        ~Node();

    //SETTERS
        void set_value(T);
        void set_next(Node*);
        
    //GETTERS
		T get_value() const;
		Node<T>* get_next() const;
    
    //SOBRECARGAR OPERADOR <<
        friend std::ostream &operator<< <>(std::ostream &o, const Node<T> &_Node);
    
    private:
        T value;
        Node* next;
};

template <typename T>
Node<T>::Node(const Node<T> &_o){
    std::cout<<" EN CONSTRUCTOR COPIA ";
    this->value = _o.get_value();
	if (_o.get_next()){
		this->next = new Node<T>(*_o.next);
	}else{
		this->next = nullptr;
    }
}

template <typename T>
Node<T>::Node(Node<T> &&_o){
    std::cout<<" EN CONSTRUCTOR DE MOVIMIENTO ";

    this->value = _o.get_value();
	if (_o.get_next()){
        Node<T> *tmp = _o.next;
        _o.~Node();
		this->next = new Node<T>(std::move(*tmp));
	}else{
		this->next = nullptr;
    }
}

template <typename T>
Node<T>::~Node(){
    std::cout<<" >> Eliminando nodo "<<this->value;
    this->value = 0;
    this->next = nullptr;
}

template <typename T>
void Node<T>::set_value(T _value){
    this->value = _value;
}

template <typename T>
T Node<T>::get_value() const {
    return value;
}

template <typename T>
void Node<T>::set_next(Node *_next){
    this->next = _next;
}

template <typename T>
Node<T>* Node<T>::get_next() const{
    return next;
}

template <typename T>
std::ostream &operator <<(std::ostream &o, const Node<T> &_Node){
    o << _Node.get_value() ;
    return o;
}

#endif