#include <iostream>
using namespace std;
struct Nodo {
    Nodo* sig;
    int elemento;
    Nodo(int e);
};
class Lista {
private:
    Nodo* inicio;
    size_t t;
    void eliminarfinal(Nodo* aux, Nodo* aux2);
    void recur(Nodo* aux, int i);
public:
    Lista();
    void push_front(int e);
    void mostrar();
    void eliminar(int pos);
    void buscarvalor(int e);
    void buscarpares();
    void ordenar();
    void invertir();
    void listarlambda();
    void listarrecursiva();
 };

//#include "Lista.h"
Nodo::Nodo(int e) {
	elemento = e;
	sig = nullptr;
}
Lista::Lista() {
	inicio = nullptr;
	t = 0;
}
void Lista::push_front(int e) {
    Nodo* n = new Nodo(e);
    if (t == 0)
        inicio = n;
    else {
        n->sig = inicio;
        inicio = n;
    }
    t++;
}
void Lista::mostrar() {
    Nodo* aux;
    aux = inicio;
    cout << endl;
    while (aux!=nullptr) {
        cout << aux->elemento << endl;
        aux = aux->sig;
    }
    cout << endl;
}
void Lista::eliminarfinal(Nodo* aux, Nodo* aux2) {
    aux->sig=nullptr;
}
void Lista::eliminar(int pos) {
    if (pos <= t) {
        Nodo* aux = inicio;
        Nodo* aux2 = nullptr;
        
        if (pos == 1) {
            inicio = aux->sig;
            delete aux;
        }
        else {
            for (int i = 1; i < pos - 1; i++)
                aux = aux->sig;
            aux2 = aux->sig;
            if (pos == t) eliminarfinal(aux, aux2);
            else aux->sig = aux2->sig;
            delete aux2;
        }
        t--;
    }
}
void Lista::buscarvalor(int e) {
    Nodo* aux = inicio;
    int i = 1;
    while (aux->elemento != e) {
        aux = aux->sig;
        i++;
        if (i > t)break;
    }      
    if (i > t)
        cout << "El valor no existe" << endl;
    else
        cout << "El valor " << e << " existe y esta en la posicion " << i << endl;
}
void Lista::buscarpares() {
    Nodo* aux = inicio;
    for (int i = 1; i <= t; i++) {
        if (aux->elemento % 2 == 0) {
            cout << i << ". " << aux->elemento << endl;
        }
        aux = aux->sig;
    }
}
void Lista::ordenar() {
    Nodo* aux = inicio;
    Nodo* aux2 = nullptr;
    for (int i = 1; i <= t; i++) {
        aux2 = aux->sig;
        for (int j = i+1; j <= t; j++) {
            
            if (aux->elemento < aux2->elemento) {
                int temp;
                temp = aux->elemento;
                aux->elemento = aux2->elemento;
                aux2->elemento = temp;
            }
            aux2 = aux2->sig;
        }
        aux = aux->sig;
    }
}
void Lista::invertir() {
    Nodo* aux = inicio;
    Nodo* aux2 = nullptr;
    for (int i = 1; i <= t; i++) {
        aux2 = aux->sig;
        for (int j = i + 1; j <= t; j++) {
            int temp;
            temp = aux->elemento;
            aux->elemento = aux2->elemento;
            aux2->elemento = temp;
            aux2 = aux2->sig;
        }
        aux = aux->sig;

    }
}
void Lista::listarlambda() {
    auto listar = [](Nodo* aux, int i) { cout<<i<<". "<<aux->elemento<<endl; };
    Nodo* aux = inicio;
    cout << endl;
    for (int i = 1; i <= t; i++) {
        listar(aux, i);
        aux = aux->sig;
    }
}
void Lista::recur(Nodo* aux, int i) {
    auto listar = [](Nodo* aux, int i) { cout << i << ". " << aux->elemento << endl; };
    listar(aux, i);
    if (i < t) {
        aux = aux->sig;
        i++;
        recur(aux, i);
    }
}
void Lista::listarrecursiva() {
    cout << endl;
    recur(inicio, 1);
}
//#include "Lista.h"
int main()
{
    Lista list;
    list.push_front(5);
    list.push_front(6);
    list.push_front(4);
    list.push_front(0);
    list.push_front(1);
    list.push_front(3);
    list.mostrar();
    list.eliminar(5);
    list.mostrar();
    list.buscarvalor(4);
    list.buscarvalor(10);
    list.buscarpares();
    list.ordenar();
    list.mostrar();
    list.invertir();
    list.mostrar();
    list.listarlambda();
    list.listarrecursiva();
    return 0;
}

//Asignacion
//1-obtener objeto en posicion = at()
//2-eliminar en posicion(n), 
//3-eliminar al inicio
//4-eliminar al final
//5-ordenar elementos(n2)
//6-buscar por valor(n)
//7-invertir lista(n2)
//8-buscar solo elementos pares
//9-listar con uso de lambdas
//10-listar de forma recursiva
