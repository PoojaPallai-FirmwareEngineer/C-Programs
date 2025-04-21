// Sort a linked list (ascending/descending)

#include <stdio.h>
#include <stdlib.h>

// The structure for linked list for Node
struct Node
{
    int data;            // Store data of the node
    struct Node* next;   // Pointer to the next node in the list
};

struct Node* createNode(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); // Exits the program if memory allocation fails
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Insert at the end of the linked list
void lastNode(struct Node ** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printlist(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortlist(struct Node* head, int ascending)
{
    if (head == NULL)
    {
        return;
    }

    struct Node* current;
    struct Node* nextNode;
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

int main()
{
        struct Node* head = NULL;

    // Add nodes to the linked list
    lastNode(&head, 50);
    lastNode(&head, 30);
    lastNode(&head, 40);
    lastNode(&head, 20);
    lastNode(&head, 10);

    printf("Original List:\n");
    printlist(head);

    // Sort in ascending order
    sortlist(head, 1);
    printf("\nSorted List in Ascending Order:\n");
    printlist(head);

    // Sort in descending order
    sortlist(head, 0);
    printf("\nSorted List in Descending Order:\n");
    printlist(head);

    return 0;
}