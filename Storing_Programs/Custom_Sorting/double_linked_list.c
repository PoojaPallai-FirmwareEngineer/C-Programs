#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
typedef struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) 
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Display the doubly linked list
void displaylist(Node* head) 
{
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Append a node at the end of the doubly linked list
Node* lastNode(Node* head, int data) 
{
    Node* newnode = createNode(data);
    if (head == NULL) 
    {
        return newnode; // New node becomes the head if the list is empty
    }

    Node* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next; // Traverse to the last node
    }

    temp->next = newnode; // Link new node to the current last node
    newnode->prev = temp; // Link the new node back to the current last node
    return head; // Return the original head of the list
}

// Sort the doubly linked list in ascending or descending order
void sortDoublyLinkedList(Node* head, int ascending) 
{
    if (head == NULL) 
    {
        return;
    }

    Node* current;
    Node* nextNode;
    int swapped;

    do 
    {
        swapped = 0;
        current = head;

        while (current->next != NULL) 
        {
            nextNode = current->next;

            // Compare and swap for ascending or descending order
            if ((ascending && current->data > nextNode->data) ||
                (!ascending && current->data < nextNode->data)) 
            {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

int main() {
    Node* head = NULL;

    // Add nodes to the doubly linked list
    head = lastNode(head, 40);
    head = lastNode(head, 20);
    head = lastNode(head, 50);
    head = lastNode(head, 10);
    head = lastNode(head, 30);

    printf("Original Doubly Linked List:\n");
    displaylist(head);

    // Sort the list in ascending order
    sortDoublyLinkedList(head, 1);
    printf("\nSorted Doubly Linked List in Ascending Order:\n");
    displaylist(head);

    // Sort the list in descending order
    sortDoublyLinkedList(head, 0);
    printf("\nSorted Doubly Linked List in Descending Order:\n");
    displaylist(head);

    return 0;
}
