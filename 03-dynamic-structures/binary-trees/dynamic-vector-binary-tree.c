#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Search Tree (BST) node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Recursive function to insert an element into the BST
Node* insert(Node *root, int value) {
    if (root == NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Error: Memory allocation failed for node!\n");
            exit(1);
        }
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    // Duplicates are ignored by default in a standard BST
    return root;
}

// In-order traversal (Left -> Root -> Right) to display elements sorted
void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Recursive function to free memory and prevent leaks
void freeTree(Node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    Node *root = NULL;
    int *vector = NULL; // Pointer to dynamically allocate the array
    int size, i;

    // 1. Prompt user for vector size
    printf("Enter the size of the vector: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // 2. Dynamically allocate memory for the input array
    vector = (int*)malloc(size * sizeof(int));
    if (vector == NULL) {
        printf("Error: Memory allocation failed for vector!\n");
        return 1;
    }

    // 3. Prompt user to populate the vector
    printf("\n=== Populating Vector of %d Elements ===\n", size);
    for (i = 0; i < size; i++) {
        printf("Enter value for position [%d]: ", i);
        if (scanf("%d", &vector[i]) != 1) {
            printf("Invalid input.\n");
            free(vector); // Free allocated buffer before exiting due to failure
            return 1;
        }
    }

    // 4. Feed array elements sequentially into the BST
    printf("\nInserting vector elements into the tree...\n");
    for (i = 0; i < size; i++) {
        root = insert(root, vector[i]);
    }

    // 5. Output results
    printf("Tree in-order (sorted values): ");
    inOrder(root);
    printf("\n");

    // 6. Complete RAM cleanup
    free(vector);     // Frees the contiguous dynamic array block
    freeTree(root);   // Frees all scattered nodes across memory
    
    return 0;
}
