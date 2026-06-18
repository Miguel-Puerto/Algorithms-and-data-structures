#include <stdio.h>
#include <stdlib.h>

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
        printf("%d ", current->intValue);
        current = current->next;
    }
    printf("\n");
}

// Traverse and print the list from tail to head (Backward)
void displayBackward(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->intValue);
        current = current->prev;
    }
    printf("\n");
}

// Search and delete a node containing a specific value
void removeValue(DoublyLinkedList* list, int intValue) {
    Node* current = list->head;

    // Linear search for the node
    while (current != NULL && current->intValue != intValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found.\n");
        return;
    }

    // Unlink the node from the previous side
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        list->head = current->next; // Node was the head

    // Unlink the node from the next side
    if (current->next != NULL)
        current->next->prev = current->prev;
    else
        list->tail = current->prev; // Node was the tail

    free(current);
}

int main() {
    DoublyLinkedList list;
    initList(&list);
    int x, y, a;

    printf("ENTER VALUE FOR X: ");
    if (scanf("%d", &x) != 1) return 1;

    printf("ENTER VALUE FOR Y: ");
    if (scanf("%d", &y) != 1) return 1;

    printf("ENTER VALUE FOR A: ");
    if (scanf("%d", &a) != 1) return 1;

    insertTail(&list, x);
    insertTail(&list, y);
    insertTail(&list, a);

    printf("\nForward traversal (Head to Tail):\n");
    displayForward(&list);

    printf("\nBackward traversal (Tail to Head):\n");
    displayBackward(&list);

    printf("\nRemoving value Y: %d\n", y);
    removeValue(&list, y);

    printf("Updated list layout: ");
    displayForward(&list);

    // Note: In a complete implementation, you should also write a 
    // function to free the remaining nodes before exiting.
    
    return 0;
}
