// **Trie Data Structure for Prefix Matching**
// -------------------------------------------
// This program demonstrates how to use a Trie (prefix tree) for fast insertion and lookup of words and prefixes in C.

/*
🧠 What is a Trie?

A Trie (pronounced "try") is a tree-like data structure that is highly efficient 
for storing and retrieving strings, particularly when many strings share common prefixes.

Each node in a Trie typically represents a single character of a string, 
and paths down the tree represent different strings or prefixes.

✅ Common Use Cases:
--------------------
1. Auto-complete: Suggesting words based on typed prefixes.
2. Spell checking: Validating or suggesting corrections for words.
3. Prefix-based searching: Checking if any word starts with a given prefix.
4. IP routing (longest prefix matching): Used in networking to route data packets.

✨ Key Properties:
------------------
- Fast prefix lookup: O(k), where k is the length of the word or prefix.
- Efficient storage for strings with overlapping prefixes.
- May consume more memory compared to other structures if not optimized 
  (e.g., via compression techniques like Ternary Search Trees or Radix Trees).

Implementation:
-----------------
This C implementation of a Trie includes:
- Inserting words into the Trie.
- Checking if a full word exists.
- Checking if any word starts with a given prefix (prefix matching).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE           26

typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndofWord;
}TrieNode;

// Create a new Trie node
TrieNode *createNode()
{
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndofWord = false;
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, const char *word)
{
    TrieNode *curr = root;
    for(int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a'; // convert character to index (0 - 25)
        if (curr->children[index] == NULL)
            curr->children[index] = createNode(); // changes
        curr = curr->children[index];
    }
    curr->isEndofWord = true; // changes
}

// Checks if the word exists in the Trie
bool search(TrieNode *root, const char *word) 
{
    TrieNode *curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL)
            return false; // changes
        curr = curr->children[index];
    }
    return curr->isEndofWord; // changes
}

// Checks if any word in the Trie starts with the given prefix
bool startswith(TrieNode *root, const char *prefix)
{
    TrieNode *curr = root;
    for(int i = 0; prefix[i] != '\0'; i++)
    {
        int index = prefix[i] - 'a';
        if(curr->children[index] == NULL)
            return false; // changes
        curr = curr->children[index];
    }
    return true; // changes
}

int main()
{
    TrieNode *root = createNode();

    insert(root, "apple");
    insert(root, "app");
    insert(root, "bat");
    insert(root, "ball");

    printf("Search 'apple': %s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("Search 'appl': %s\n", search(root, "appl") ? "Found" : "Not Found");
    printf("Prefix 'app': %s\n", startswith(root, "app") ? "Exists" : "Not Exists");
    printf("Prefix 'ba': %s\n", startswith(root, "ba") ? "Exists" : "Not Exists");

    return 0;
}






