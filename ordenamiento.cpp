//Ejercicio 2

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
// fincion para insertar un nuevo nodo en orden creciente
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// funcion para imprimir la lista
void  imprimir(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
         cout << current->data << " ";
        current = current->next;
    }
     cout <<  endl;
}

// funcion para limpiar la memoria de la lista
void limpiar(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int cantidad;
     cout << "Digite la cantidad de numeros a ordenar : ";
     cin >> cantidad;

    for (int i = 0; i < cantidad; ++i) {
        
     cout << "Digite los numeros para ordenarlo :\n";
        int numero;
         cin >> numero;
        insert(head, numero);
    }
     cout << "La lista ya fue ordenada y es ---->: ";
     imprimir(head);
    limpiar(head);

    return 0;
}
