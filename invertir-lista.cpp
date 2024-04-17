#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};

int main()
{
    LinkedList list;
    int numElements;
    cout << "Digite la candidad de numeros que desea agregar a la lista: ";
    cin >> numElements;

    cout << "Ingrese los numeros:" << endl;
    for (int i = 0; i < numElements; ++i)
    {
        int num;
        cin >> num;
        list.insert(num);
    }

    cout << "Lista original: ";
    list.display();

    list.reverse();

    cout << "Lista invertida: ";
    list.display();

    return 0;
}
