// Tree Sort Algorithm

// Tree Sort is a sorting technique based on a **Binary Search Tree (BST)**. 
// It leverages the BST property where:
// - The left subtree contains elements smaller than the root.
// - The right subtree contains elements greater than the root.

// Algorithm:

// 1. **Insert all elements into a BST**:
//    - Start with an empty BST.
//    - Insert each element from the array into the BST while maintaining the BST properties.
//    - Each insertion takes O(log n) time on average but can degrade to O(n) in the worst case (if the tree is skewed).

// 2. **Perform In-order Traversal**:
//    - In-order traversal (Left, Root, Right) of a BST retrieves elements in sorted order.
//    - This step takes O(n) time as it visits each node exactly once.

// 3. **Store the sorted elements back into the original array**:
//    - While performing the in-order traversal, store each element back into the array.
//    - This ensures the original array is sorted.

// **Time Complexity**:
// - Best & Average Case (Balanced BST): O(n log n)  
// - Worst Case (Skewed BST): O(n²)  

// **Space Complexity**:
// - O(n) (for the BST node storage)

// **Advantages**:
// ✅ Simple concept based on Binary Search Tree  
// ✅ Performs well for randomly inserted elements  
// ✅ In-order traversal ensures stable sorting  

// **Disadvantages**:
// ❌ Can degrade to O(n²) if the BST becomes unbalanced  
// ❌ Requires additional memory for the BST  

// **Optimizations**:
// - Use a **self-balancing BST** (e.g., AVL Tree, Red-Black Tree) to ensure O(n log n) performance.  

#include <stdio.h>
#include <stdlib.h>

// Double linked list
struct Node
{
    int data;
    struct Node* left; 
    struct Node* right;
}Node;

// create a node 
struct Node* createNode(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(Node));
    if(!newnode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// To insert a node into the BST
struct Node* insertNode(struct Node* root, int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }

    if(data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Perform in order traversal and store elements in the array
void inorderTraversal(struct Node* root, int arr[], int* index)
{
    if (root != NULL)
    {
        inorderTraversal(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorderTraversal(root->right, arr, index);
    }
}

// Tree sorted
void treesort(int arr[], int n)
{
    struct Node* root = NULL;

    // Insert elements into the BST
    for(int i = 0; i < n; i++)
    {
        root = insertNode(root, arr[i]);
    }

    // Retrive sorted elements using in-order traversal
    int index = 0;
    inorderTraversal(root, arr, &index);
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test Tree Sort
int main() 
{
    int arr[] = {5, 2, 8, 4, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    treesort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}









