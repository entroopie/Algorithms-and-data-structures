#include <iostream>
using namespace std;

typedef struct List {
    int data;
    struct List* next;
} List_type;

void freeMemory(List_type** head) {
    List_type* temp = *head;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void addElement(List_type** head, const int key, List_type** tail) {
    if (*head == NULL) {
        *head = (List_type*)malloc(sizeof(List_type));
        (*head)->data = key;
        (*head)->next = NULL;
        *tail = *head;
    }
    else {
        List_type* temp = *tail;
        temp->next = (List_type*)malloc(sizeof(List_type));
        temp->next->data = key;
        temp->next->next = NULL;
        *tail = temp->next;
    }
}

void deleteElement(List_type** head) {
    List_type* temp = NULL;
    if (*head != NULL) {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}

int printElement(List_type* head, const int key) {
    if (head == NULL) return -1;
    else {
        List_type* temp = head;
        int i = 0;
        do {
            if (temp->data == key) return i;
            temp = temp->next;
            i++;
        } while (temp->next != NULL);
        if (temp->data == key) return i;
    }
    return -1;
}

void showAll(List_type* head) {
    if (head == NULL) cout << "err" << endl;
    else {
        List_type* temp = head;
        do {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != NULL);
    }
}

int main() {
    List_type* head;
    head = NULL;

    List_type* tail;
    tail = NULL;

    int key;
    char opt = NULL;

    while (opt != 'q') {
        cin >> opt;
        switch (opt) {
        case 'i':
            cin >> key;
            addElement(&head, key, &tail);
            break;
        case 'd':
            deleteElement(&head);
            break;
        case 's':
            cin >> key;
            cout << printElement(head, key) << endl;
            break;
        case 'h':
            showAll(head);
            break;
        }
    }
    freeMemory(&head);

    return 0;
}