#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node definition for the doubly linked list
typedef struct Node {
    int intValue;
    struct Node* prev;
    struct Node* next;
} Node;

// List structure definition holding head and tail pointers
typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Initialize the list pointers to NULL
void initList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Append a new node to the end of the list
void insertTail(DoublyLinkedList* list, int intValue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    newNode->intValue = intValue;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = newNode;
    else
        list->head = newNode;

    list->tail = newNode;
}

// Traverse and print the list from head to tail (Forward)
void displayForward(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("  %d\n", current->intValue);
        current = current->next;
    }
    printf("\n");
}

// Traverse and print the list from tail to head (Backward)
void displayBackward(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("  %d\n", current->intValue);
        current = current->prev;
    }
    printf("\n");
}

// Search and delete a node containing a specific value
void removeValue(DoublyLinkedList* list, int intValue) {
    Node* current = list->head;

    while (current != NULL && current->intValue != intValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        list->head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;
    else
        list->tail = current->prev;

    free(current);
}

int main() {
    char repeat;

    do {
        DoublyLinkedList list;
        initList(&list);

        int x, y, a;

        printf("\n   \033[1mEnter value for X:\033[0m ");
        if (scanf("%d", &x) != 1) return 1;

        printf("   \033[1mEnter value for Y:\033[0m ");
        if (scanf("%d", &y) != 1) return 1;

        printf("   \033[1mEnter value for A:\033[0m ");
        if (scanf("  %d", &a) != 1) return 1;

        printf("\033[1m_____________________________________________________\033[0m\n");

        insertTail(&list, x);
        insertTail(&list, y);
        insertTail(&list, a);

        printf("\n   \033[1mForward Traversal (Head to Tail):\033[0m\n");
        displayForward(&list);

        printf("\033[1m_____________________________________________________\033[0m\n");

        printf("\n   \033[1mBackward Traversal (Tail to Head):\033[0m\n");
        displayBackward(&list);

        printf("\033[1m_____________________________________________________\033[0m\n");

        srand(time(NULL)); // Initialize the random seed generator

        int option = rand() % 3; // Generates 0, 1, or 2
        int valueToRemove;

        switch (option) {
            case 0:
                valueToRemove = x;
                printf("\n   \033[1mRandomly removing X = %d\033[0m\n", x);
                break;
            case 1:
                valueToRemove = y;
                printf("\n   \033[1mRandomly removing Y = %d\033[0m\n", y);
                break;
            case 2:
                valueToRemove = a;
                printf("\n   \033[1mRandomly removing A = %d\033[0m\n", a);
                break;
        }
        
        printf("\033[1m_____________________________________________________\033[0m\n");
        removeValue(&list, valueToRemove);

        printf("\n   \033[1mFinal List Layout:\n\033[0m");
        displayForward(&list);
        
        printf("\033[1m_____________________________________________________\033[0m\n");
        
        printf("\n   \033[1mWould you like to repeat? (Y/N):   \033[0m"); 
        if (scanf(" %c", &repeat) != 1) return 1;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
