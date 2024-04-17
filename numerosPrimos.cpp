#include <iostream>
#include <vector>
#include <random>
using namespace std;

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

void imprimir_lista(const vector<int>& lista)
{
    for (int elemento : lista)
    {
        cout << elemento << " ";
    }
    cout << endl;
}

void liberar_lista(vector<int>& lista)
{
    lista.clear();
}

int main()
{
    random_device ramd;
    mt19937 gen(ramd());
    uniform_int_distribution<> dis(1, 50);

    vector<int> primosVec;
    int cantidadNumeros;

    cout << "Digite la cantidad de numeros primos que desee generar: ";
    cin >> cantidadNumeros;

    while (primosVec.size() < cantidadNumeros)
    {
        int num = dis(gen);
        if (numPrimo(num))
        {
            primosVec.push_back(num);
        }
    }

    cout << "Los numeros primos generados son: ";
    imprimir_lista(primosVec);

    liberar_lista(primosVec);

    return 0;
}
