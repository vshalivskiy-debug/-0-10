#include <iostream>
#include <windows.h>

using namespace std;

// ===== СТРУКТУРА =====
struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

// ===== ДОДАВАННЯ В КІНЕЦЬ =====
void Add(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->prev = tail;

    if (head == NULL) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

// ===== ВИВІД З ПОЧАТКУ =====
void ShowForward() {
    Node* temp = head;
    cout << "Список з початку: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ===== ВИВІД З КІНЦЯ =====
void ShowBackward() {
    Node* temp = tail;
    cout << "Список з кiнця: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// ===== ВИДАЛЕННЯ ЕЛЕМЕНТА =====
void Delete(int value) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {

            if (temp == head) {
                head = temp->next;
                if (head != NULL) head->prev = NULL;
            }
            else if (temp == tail) {
                tail = temp->prev;
                if (tail != NULL) tail->next = NULL;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "Елемент видалено!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Елемент не знайдено!\n";
}

// ===== ОЧИЩЕННЯ =====
void Clear() {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = tail = NULL;
}

// ===== MAIN =====
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, x;

    cout << "Скiльки елементiв: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Введiть елемент: ";
        cin >> x;
        Add(x);
    }

    ShowForward();
    ShowBackward();

    cout << "Який елемент видалити: ";
    cin >> x;
    Delete(x);

    ShowForward();

    Clear();

    return 0;
}