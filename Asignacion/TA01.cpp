#include "Lista.h"
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
