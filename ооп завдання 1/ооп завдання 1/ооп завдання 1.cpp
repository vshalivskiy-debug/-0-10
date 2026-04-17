#include <iostream>
#include <windows.h>

using namespace std;

// ===== СТРУКТУРА ВУЗЛА =====
struct Node {
    int data;
    Node* next;
};

// ===== СТВОРЕННЯ СПИСКУ =====
Node* CreateList() {
    Node* head = NULL;
    Node* tail = NULL;

    int n, value;
    cout << "Введiть кiлькiсть елементiв: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Введiть елемент: ";
        cin >> value;

        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

// ===== ВИВЕДЕННЯ СПИСКУ =====
void ShowList(Node* head) {
    Node* temp = head;

    cout << "Список: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ===== MAIN =====
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* head = CreateList();
    ShowList(head);

    return 0;
}