#include <stdio.h>
#include <stdlib.h>
#define NULL 0x0000000

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void insertAtHead(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

void insertAtTail(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = tail;
    newNode->next = NULL;
    if (tail != NULL) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

void deleteFromHead() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    free(temp);
}

void deleteFromTail() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

void printList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insertAtHead(1);
    insertAtTail(2);
    insertAtHead(3);
    insertAtTail(4);
    insertAtHead(5);
    printList();
    deleteFromHead();
    deleteFromTail();
    printList();
    return 0;
}
