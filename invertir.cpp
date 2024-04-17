//invertir usando STL

#include <iostream>
#include <sstream>
#include <string>

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
        while (aux->siguiente != nullptr && aux->siguiente->dato < nuevo->dato)
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

void imprimir_lista(Nodo *inicio)
{
    for (Nodo *aux = inicio; aux != nullptr; aux = aux->siguiente)
    {
        cout << aux->dato << " ";
    }
    cout << endl;
}

Nodo *buscar(Nodo *inicio, int datoBuscado)
{
    Nodo *aux = inicio;
    while (aux != nullptr && aux->dato != datoBuscado)
    {
        aux = aux->siguiente;
    }
    return aux;
}

Nodo *eliminar(Nodo *inicio, int datoABorrar)
{
    if (inicio != nullptr)
    {
        Nodo *aux = inicio;
        if (inicio->dato == datoABorrar)
        {
            inicio = inicio->siguiente;
            delete aux;
        }
        else
        {
            while (aux->siguiente != nullptr && aux->siguiente->dato != datoABorrar)
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

Nodo *invertir_lista(Nodo *inicio)
{
    Nodo *lista_invertida = nullptr;
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        lista_invertida = insertar_principio(lista_invertida, generar_nodo(actual->dato));
        actual = actual->siguiente;
    }
    return lista_invertida;
}

int main()
{
    string entrada;

    cout << "Ingrese una lista de números separados por comas: ";
    getline(std::cin, entrada);

    istringstream ss(entrada);
    string token;
    Nodo *numeros = nullptr;

    while (std::getline(ss, token, ','))
    {
        numeros = insertar_final(numeros, generar_nodo(std::stoi(token)));
    }

    cout << "Lista original: ";
    imprimir_lista(numeros);

    Nodo *lista_invertida = invertir_lista(numeros);

    cout << "Lista invertida: ";
    imprimir_lista(lista_invertida);

    Nodo *aux;
    while (numeros != nullptr)
    {
        aux = numeros;
        numeros = numeros->siguiente;
        delete aux;
    }
    while (lista_invertida != nullptr)
    {
        aux = lista_invertida;
        lista_invertida = lista_invertida->siguiente;
        delete aux;
    }

    return 0;
}
