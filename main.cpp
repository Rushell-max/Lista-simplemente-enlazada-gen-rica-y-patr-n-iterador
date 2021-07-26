#include <iostream>
#include <chrono>
#include <thread>
#include "E:\Projects\S3\Laboratorio_CC_II\T14_ListaEnlazadaGenerica\ListaEnlazadaGenerica.cpp"
using namespace std;

//COMPARAR CON LA LISTA ENLAZADA DE LA LIBRERÍA STL
//TIEMPOS DE EJECUCIÓN Y MÉTODOS

int main(){
    //////// TIEMPO DE EJECUCIÓN ///////////////////
        auto start = std::chrono::high_resolution_clock::now();
    ////////// TIEMPO DE EJECUCIÓN ///////////////////

    /** / PRUEBA CONSTRUCTORES NODO //////////////
        Node<int> node_1;
        Node<int> node_2;
        Node<int> node_3;

        node_1.set_value(1);
        node_2.set_value(2);
        node_3.set_value(3);

        node_1.set_next(&node_2);
        node_2.set_next(&node_3);


        Node<int> node_4;
        //PRUEBA DE SOBRECARGA DEL OPERADOR COPIA
            //node_4 = node_1;
        //PRUEBA DE SOBRECARGA DEL OPERADOR DE MOVIMIENTO
            node_4 = std::move(node_1);

        if(node_1.get_next()!=nullptr){ cout<<"\tYES! "<<endl; }
            else{ cout<<"\tNO! "<<endl; }

        //PRUEBA DEL CONSTRUCTOR COPIA
            //Node<int> node_4(node_1);
        //PRUEBA DEL CONSTRUCTOR DE MOVIMIENTO
            //Node<int> ode_4(std::move(node_1));


        //node_1.get_next()->set_value(9);
        //node_4.get_next()->set_value(6);

        
        //cout << node_1 << *node_1.get_next() << *node_1.get_next()->get_next() << endl; 
        cout << node_4 << *node_4.get_next() << *node_4.get_next()->get_next() << endl; 
    // CONSTRUCTORES NODO ///////////// **/

    //CREAR LISTA DE ENTEROS
        ListaEnlazadaGenerica<int> l1;
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
        l1.insert(3, 5);
        l1.insert(6, 8);
        l1.insert(-3, 0);
        //cout<<l1<<endl;
    //PRUEBAS POP-FRONT
        l1.pop_front();
        //cout<<l1<<endl;
    //PRUEBAS POP-BACK
        l1.pop_back();
        //cout<<l1<<endl;
    //PRUEBAS REMOVE_BY_POSITION
        l1.remove_by_position(7);
        //cout<<l1<<endl;

    //PRUEBA ITERATOR
        Iterator<int>* it = l1.crearIterador();
        
        cout<<"\n\t MOTRANDO LISTA CON ITERADOR (SIZE="<<l1.get_size()<<") >>  [ ";
        for(it->get_first(); !it->finish(); (*it)++){
            cout<<it->content()<<" ";
        }cout<<"]";

        cout<<"\n\t MOTRANDO LISTA EN REVERSA CON ITERADOR (SIZE="<<l1.get_size()<<") >>  [ ";
        for(it->get_end(); !it->finish(); (*it)--){
            cout<<it->content()<<" ";
        }cout<<"]"<<endl;   
    
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

        cout<<"\n\t MOTRANDO LISTA CON ITERADOR (SIZE="<<l1.get_size()<<") >>  [ ";
        for(it->get_first(); !it->finish(); (*it)++){
            cout<<it->content()<<" ";
        }cout<<"]";

    /** /PRUEBAS CONSTRUCTORES LISTA  //////////////////////////
    //CONSTRUCTOR COPIA
        //if(true)
            ListaEnlazadaGenerica<int> l2(l1);    
    //SOBRECARGA DEL OPERADOR COPIA";
        //if(true)
            //ListaEnlazadaGenerica<int> l2;
            //l2 = l1;
    //CONSTRUCTOR DE MOVIMIENTO
        //if(true)
            //ListaEnlazadaGenerica<int> l2 (std::move(l1));    
    //SOBRECARGA DEL OPERADOR DE MOVIMIENTO";
        //if(true)
            //ListaEnlazadaGenerica<int> l2;
            //l2 = std::move(l1);
    cout<<l2<<endl;
    cout<<l1<<endl;
    //PRUEBAS CONSTRUCTORES  ///////////////////////// **/

    ////////// TIEMPO DE EJECUCIÓN ///////////////////
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> float_ms = end - start;
        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::chrono::duration<long, std::micro> int_usec = int_ms;

        std::cout << "\n\t main() elapsed time is " << float_ms.count() << " ms "
                << "( " << int_ms.count() << " milliseconds )" << std::endl;
    ////////// TIEMPO DE EJECUCIÓN ///////////////////
    
    /** /MENU
    ListaEnlazadaGenerica<int> l1;
    int opcion;
    bool repetir = true;

    do{
        cout << "\n\n\t\t\tOpciones" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Push-back" << endl;
        cout << "\t2. Push-front " << endl;
        cout << "\t3. Insert_by_position" << endl;
        cout << "\t4. Pop-back" << endl;
        cout << "\t5. Pop-front" << endl;
        cout << "\t6. Remove_by_position" << endl;
        cout << "\t7. Front" << endl;
        cout << "\t8. Back" << endl;
        cout << "\t9. Empty? " << endl;
        cout << "\t10. Remove " << endl;
        cout << "\t11. Reverse" << endl;
        cout << "\t0. SALIR" << endl;

        cout << l1 <<endl;
    
        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        
        int valor, pos;
        switch (opcion){
            case 1:
                cout<<"\tValor a ingresar? ";cin>>valor;
                l1.push_back(valor);
                break;
            case 2:
                cout<<"\tValor a ingresar? ";cin>>valor;
                l1.push_front(valor);
                break;
            case 3:
                cout<<"\tValor a ingresar? ";cin>>valor;
                cout<<"\tPosicion? ";cin>>pos;
                l1.insert(valor, pos);
                break;
            case 4:
                l1.pop_back();
                break;
            case 5:
                l1.pop_front();
                break;
            case 6:
                cout<<"\tPosicion? ";cin>>pos;
                l1.remove_by_position(pos);
                break;
            case 7:
                cout<<"\tEl valor del primer elemento es "<<l1.front()<<endl;
                break;
            case 8:
                cout<<"\tEl valor del ultimo elemento es "<<l1.back()<<endl;
                break;                
            case 9:
                if(l1.empty()){ cout<<"\tYES! "<<endl; }
                else{ cout<<"\tNO! "<<endl; }
                break;      
            case 10:
                cout<<"\tIngrese valor a eliminar ";cin>>valor;
                l1.remove(valor);
                break;
            case 11:
                l1.reverse();
                break;
            case 0:
                repetir = false;
                break;
        }
    } while (repetir); **/
    
    return 0; 
}