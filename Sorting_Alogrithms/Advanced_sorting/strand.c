#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;            
    struct Node* next;   
} Node;

// Create a new Node with given data
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int newData)
{
    Node* newNode = createNode(newData);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head)
{
    while (head != NULL)
    {
        printf("%d --> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Extract a sorted subsequence (strand) from the list
Node* extractStrand(Node** head)
{
    if (*head == NULL)
        return NULL;

    Node* strandHead = *head;
    Node* strandTail = strandHead;
    Node* prev = *head;
    Node* curr = (*head)->next;

    // Update *head to point to the first element not in the strand
    *head = curr;

    while (curr)
    {
        if (curr->data >= strandTail->data)
        {
            strandTail->next = curr;
            strandTail = curr;
            prev->next = curr->next; // Remove from original list
            curr = curr->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    strandTail->next = NULL; // Terminate strand

    return strandHead;
}

// Merge two sorted lists
Node* mergeLists(Node* a, Node* b)
{
    if (!a) return b;
    if (!b) return a;

    Node* head = NULL;
    Node** tail = &head;

    while (a && b)
    {
        if (a->data <= b->data)
        {
            *tail = a;
            a = a->next;
        }
        else
        {
            *tail = b;
            b = b->next;
        }
        tail = &((*tail)->next);
    }
    *tail = (a) ? a : b;

    return head;
}

// Strand Sort
void strandSort(Node** head)
{
    if (*head == NULL)
        return;

    Node* sortedList = NULL;
    while (*head)
    {
        Node* strand = extractStrand(head);
        sortedList = mergeLists(sortedList, strand);
    }
    *head = sortedList;
}

// Free memory allocated for list nodes
void freeList(Node* head)
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Input list: {10, 5, 30, 40, 2, 8}
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 8);

    printf("Original list: ");
    printList(head);

    strandSort(&head);

    printf("Sorted list: ");
    printList(head);

    freeList(head);

    return 0;
}
