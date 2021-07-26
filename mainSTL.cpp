#include <iostream>
#include <iterator> 
#include <list> 
#include <chrono> 
#include <thread>

using namespace std;


int main(){
    ////////// TIEMPO DE EJECUCIÓN ///////////////////
        auto start = std::chrono::high_resolution_clock::now();
    ////////// TIEMPO DE EJECUCIÓN ///////////////////

    //CREAR LISTA DE ENTEROS
        list <int> l1;
    //PRUEBAS PUSH-BACK
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(4);
        l1.push_back(5);
        //cout<<l1<<endl;
    //PRUEBAS PUSH-FRONT
        l1.push_front(0);
        l1.push_front(-1);
        l1.push_front(-2);
        //cout<<l1<<endl;
    //PRUEBAS INSERT-BY-POSITION
        list<int>::iterator it = l1.begin();
        advance(it, 5);
        l1.insert(it, 3);
        it = l1.end();
        l1.insert(it, 6);
        it = l1.begin();
        l1.insert(it, -3);
        //cout<<l1<<endl;
    //PRUEBAS POP-FRONT 
        l1.pop_front();
        //cout<<l1<<endl;
    //PRUEBAS POP-BACK
        l1.pop_back();
        //cout<<l1<<endl;
    //PRUEBAS REMOVE_BY_POSITION
        advance(it, 7);
        l1.erase(it);
        //cout<<l1<<endl;

    //PRUEBA ITERATOR
        cout<<"\n\t MOTRANDO LISTA POR ITERADOR (SIZE="<<l1.size()<<") >>  [ ";
        for(it = l1.begin(); it != l1.end(); (it)++){
            cout<<*it<<" ";
        }cout<<"]";
    
    // FRONT
        cout<<"\n\t > El valor del primer elemento es "<<l1.front()<<endl;
    //BACK
        cout<<"\n\t > El valor del ultimo elemento es "<<l1.back()<<endl;
    //EMPTY
        if(l1.empty()){ cout<<"\n\t > YES! "<<endl; }
        else{ cout<<"\n\t > NO! "<<endl; }
    //REMOVE
        l1.remove(1);
    //REVERSE
        l1.reverse();

        cout<<"\n\t MOTRANDO LISTA POR ITERADOR (SIZE="<<l1.size()<<") >>  [ ";
        for(it = l1.begin(); it != l1.end(); (it)++){
            cout<<*it<<" ";
        }cout<<"]";

    //PRUEBAS CONSTRUCTORES LISTA  //////////////////////////
    //CONSTRUCTOR COPIA
        //if(true)
            //list<int> l2(l1);    
    //SOBRECARGA DEL OPERADOR COPIA";
        //if(true){
            //list <int> l2;
            //l2 = l1;
        //}
    //CONSTRUCTOR DE MOVIMIENTO
        //if(true)
            //ListaEnlazadaGenerica<int> l2 (std::move(l1));    
    //SOBRECARGA DEL OPERADOR DE MOVIMIENTO";
        //if(true){
            //ListaEnlazadaGenerica<int> l2;
            //l2 = std::move(l1);
        //}
    //PRUEBAS CONSTRUCTORES  ///////////////////////// **/

    ////////// TIEMPO DE EJECUCIÓN ///////////////////
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> float_ms = end - start;
        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::chrono::duration<long, std::micro> int_usec = int_ms;

        std::cout << "\n\t main() elapsed time is " << float_ms.count() << " ms "
                << "( " << int_ms.count() << " milliseconds )" << std::endl;
    ////////// TIEMPO DE EJECUCIÓN ///////////////////

    return 0;
}