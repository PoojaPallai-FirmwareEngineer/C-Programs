#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Initially, the node points to itself
    return newNode;
}

// Insert a node at the end of the circular linked list
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
    newNode->next = head; // Point back to the head to maintain the circular nature
    return head;
}

// Display the circular linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Sort the circular linked list
void sortCircularLinkedList(Node* head, int ascending) {
    if (head == NULL || head->next == head) {
        // If the list is empty or has only one node, it's already sorted
        return;
    }

    Node* current;
    Node* nextNode;
    int swapped;

    do {
        swapped = 0;
        current = head;

        // Traverse the circular linked list
        do {
            nextNode = current->next;

            // Compare and swap for ascending or descending order
            if ((ascending && current->data > nextNode->data) ||
                (!ascending && current->data < nextNode->data)) {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                swapped = 1;
            }

            current = current->next;
        } while (current->next != head);

    } while (swapped);
}

int main() {
    Node* head = NULL;

    // Insert elements into the circular linked list
    head = insertEnd(head, 40);
    head = insertEnd(head, 20);
    head = insertEnd(head, 50);
    head = insertEnd(head, 10);
    head = insertEnd(head, 30);

    printf("Original Circular Linked List:\n");
    displayList(head);

    // Sort the list in ascending order
    sortCircularLinkedList(head, 1);
    printf("\nSorted Circular Linked List in Ascending Order:\n");
    displayList(head);

    // Sort the list in descending order
    sortCircularLinkedList(head, 0);
    printf("\nSorted Circular Linked List in Descending Order:\n");
    displayList(head);

    return 0;
}
