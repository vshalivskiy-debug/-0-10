#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// створення списку
void CreateList(Node*& head) {
    int n, value;
    cout << "Введiть кiлькiсть елементiв: ";
    cin >> n;

    head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        cout << "Введiть елемент " << i + 1 << ": ";
        cin >> value;

        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
}

// перегляд списку
void ShowList(Node* head) {
    if (head == NULL) {
        cout << "Список порожнiй." << endl;
        return;
    }

    cout << "Список: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// видалення з початку
void DeleteFromBegin(Node*& head) {
    if (head == NULL) {
        cout << "Список порожнiй." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Перший елемент видалено." << endl;
}

// видалення з кінця
void DeleteFromEnd(Node*& head) {
    if (head == NULL) {
        cout << "Список порожнiй." << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Останнiй елемент видалено." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    cout << "Останнiй елемент видалено." << endl;
}

// видалення за ключем
void DeleteByKey(Node*& head, int key) {
    if (head == NULL) {
        cout << "Список порожнiй." << endl;
        return;
    }

    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }

    cout << "Видалення за ключем завершено." << endl;
}

// додавання на початок
void AddToBegin(Node*& head, int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;

    cout << "Елемент додано на початок." << endl;
}

// додавання в кінець
void AddToEnd(Node*& head, int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }

    cout << "Елемент додано в кiнець." << endl;
}

// додавання після ключа
void AddAfterKey(Node*& head, int key, int value) {
    if (head == NULL) {
        cout << "Список порожнiй." << endl;
        return;
    }

    Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Ключ не знайдено." << endl;
        return;
    }

    Node* temp = new Node;
    temp->data = value;
    temp->next = current->next;
    current->next = temp;

    cout << "Елемент додано пiсля ключа." << endl;
}

// очищення списку
void ClearList(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Список очищено." << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* head = NULL;
    int choice, value, key;

    do {
        cout << "\n===== МЕНЮ =====" << endl;
        cout << "1. Створити список" << endl;
        cout << "2. Переглянути список" << endl;
        cout << "3. Видалити елемент з початку" << endl;
        cout << "4. Видалити елемент за ключем" << endl;
        cout << "5. Видалити елемент з кiнця" << endl;
        cout << "6. Додати елемент на початок" << endl;
        cout << "7. Додати елемент в кiнець" << endl;
        cout << "8. Додати елемент пiсля ключа" << endl;
        cout << "9. Вихiд та очищення списку" << endl;
        cout << "Ваш вибiр: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ClearList(head);
            CreateList(head);
            break;
        case 2:
            ShowList(head);
            break;
        case 3:
            DeleteFromBegin(head);
            break;
        case 4:
            cout << "Введiть ключ для видалення: ";
            cin >> key;
            DeleteByKey(head, key);
            break;
        case 5:
            DeleteFromEnd(head);
            break;
        case 6:
            cout << "Введiть значення: ";
            cin >> value;
            AddToBegin(head, value);
            break;
        case 7:
            cout << "Введiть значення: ";
            cin >> value;
            AddToEnd(head, value);
            break;
        case 8:
            cout << "Введiть ключ, пiсля якого додати: ";
            cin >> key;
            cout << "Введiть значення нового елемента: ";
            cin >> value;
            AddAfterKey(head, key, value);
            break;
        case 9:
            ClearList(head);
            cout << "Програма завершена." << endl;
            break;
        default:
            cout << "Неправильний вибiр." << endl;
        }

    } while (choice != 9);

    return 0;
}