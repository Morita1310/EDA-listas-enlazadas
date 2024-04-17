//TAD ejercicio 2 

#include <iostream>
using namespace std;
struct Nodo
{
    int dato;
    Nodo *siguiente;
};
Nodo *insertar_principio(Nodo *inicio, Nodo *nuevo)
{
    nuevo->siguiente = inicio;
    return nuevo;
}
Nodo *insertar_final(Nodo *inicio, Nodo *nuevo)
{
    if (inicio == nullptr)
        inicio = nuevo;
    else
    {
        Nodo *aux = inicio;
        while (aux->siguiente != nullptr)
            aux = aux->siguiente;
        aux->siguiente = nuevo;
    }
    return inicio;
}
Nodo *insertar_ordenado(Nodo *inicio, Nodo *nuevo)
{
    if (inicio == nullptr || nuevo->dato < inicio->dato)
    {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else
    {
        Nodo *aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->dato <
                                                nuevo->dato)
        {
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }
    return inicio;
}
Nodo *generar_nodo(int dato)
{
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;
    return nuevo;
}
/* Imprime en pantalla todos los elementos de la lista. */
void imprimir_lista(Nodo *inicio)
{
    for (Nodo *aux = inicio; aux != nullptr; aux = aux->siguiente)
    {
        cout << aux->dato << " ";
    }
    cout << endl;
}
/* Busca un dato en la lista, retornando un puntero al nodo si lo
encuentra, o nullptr si no lo encuentra. */
Nodo *buscar(Nodo *inicio, int datoBuscado)
{
    Nodo *aux = inicio;
    while (aux != nullptr && aux->dato != datoBuscado)
    {
        aux = aux->siguiente;
    }
    return aux;
}
/* Elimina de la lista la primera ocurrencia del dato pasado por
parámetro.
Retorna un puntero al nodo inicial de la lista (que puede haberse
modificado si se eliminó el primer nodo. */
Nodo *eliminar(Nodo *inicio, int datoABorrar)
{
    if (inicio != nullptr)
    { // Sólo proceder si la lista tiene nodos
        Nodo *aux = inicio;
        if (inicio->dato == datoABorrar)
        { // El nodo a borrar es el primero
            inicio = inicio->siguiente;
            delete aux;
        }
        else
        { // Si no se eliminó el primer nodo, buscamos el dato a partir del segundo
            while (aux->siguiente != nullptr && aux->siguiente->dato !=
                                                    datoABorrar)
            {
                aux = aux->siguiente;
            }
            if (aux->siguiente->dato == datoABorrar)
            {
                Nodo *aEliminar = aux->siguiente;
                aux->siguiente = aEliminar->siguiente;
                delete aEliminar;
            }
        }
    }
    return inicio;
}
void liberar_lista(Nodo *inicio)
{
    Nodo *aux;
    while (inicio != nullptr)
    {
        aux = inicio;
        inicio = inicio->siguiente;
        delete aux;
    }
}

int main()
{
    Nodo *lista = nullptr;
    int cantidad, numero;

    cout << "Ingrese la cantidad de numeros a ordenar: ";
    cin >> cantidad;
    
    for (int i = 0; i < cantidad; ++i)
    {
        cout << "Ingrese el numero : ";
        cin >> numero;
        lista = insertar_ordenado(lista, generar_nodo(numero));
    }

    cout << "\nLista enlazada ordenada ------>:" ;
    imprimir_lista(lista);

    return 0;
}
