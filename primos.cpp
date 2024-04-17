//ejercicio uno de los primos aleatorios 


#include <iostream>
#include <random>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

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

bool numPrimo(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    random_device ramd;
    mt19937 gen(ramd());
    uniform_int_distribution<> dis(1, 50);

    Nodo *primosLis = nullptr;
    int cantidadNumeros;

    cout << "Digite la cantidad de numeros primos que desee generar: ";
    cin >> cantidadNumeros;

    for (int i = 0; i < cantidadNumeros;)
    {
        int num = dis(gen);
        if (numPrimo(num))
        {
            Nodo *nuevo = generar_nodo(num);
            primosLis = insertar_final(primosLis, nuevo);
            i++;
        }
    }

    cout << "Los numeros primos generados son: ";
    imprimir_lista(primosLis);

    liberar_lista(primosLis);

    return 0;
}
