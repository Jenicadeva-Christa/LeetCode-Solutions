#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrieNode {
    int wordIndex;
    int* palindromeIndexes;
    int palindromeCount;
    int palindromeCapacity;
    struct TrieNode* children[26];
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->wordIndex = -1;
    node->palindromeCount = 0;
    node->palindromeCapacity = 4;
    node->palindromeIndexes = (int*)malloc(node->palindromeCapacity * sizeof(int));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

bool isPalindrome(const char* word, int left, int right) {
    while (left < right) {
        if (word[left++] != word[right--]) return false;
    }
    return true;
}

void addPalindromeIndex(TrieNode* node, int index) {
    if (node->palindromeCount >= node->palindromeCapacity) {
        node->palindromeCapacity *= 2;
        node->palindromeIndexes = (int*)realloc(node->palindromeIndexes, node->palindromeCapacity * sizeof(int));
    }
    node->palindromeIndexes[node->palindromeCount++] = index;
}

void insert(TrieNode* root, const char* word, int wordIndex) {
    TrieNode* curr = root;
    int len = strlen(word);
    
    for (int i = len - 1; i >= 0; i--) {
        if (isPalindrome(word, 0, i)) {
            addPalindromeIndex(curr, wordIndex);
        }
        int idx = word[i] - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = createNode();
        }
        curr = curr->children[idx];
    }
    curr->wordIndex = wordIndex;
    addPalindromeIndex(curr, wordIndex); 
}

void search(TrieNode* root, const char* word, int wordIndex, int** res, int* count, int** colSizes) {
    TrieNode* curr = root;
    int len = strlen(word);
    
    for (int i = 0; i < len; i++) {
        if (curr->wordIndex != -1 && curr->wordIndex != wordIndex && isPalindrome(word, i, len - 1)) {
            res[*count] = (int*)malloc(2 * sizeof(int));
            res[*count][0] = wordIndex;
            res[*count][1] = curr->wordIndex;
            (*colSizes)[*count] = 2;
            (*count)++;
        }
        
        int idx = word[i] - 'a';
        if (!curr->children[idx]) return;
        curr = curr->children[idx];
    }
    
    for (int i = 0; i < curr->palindromeCount; i++) {
        int palIdx = curr->palindromeIndexes[i];
        if (palIdx != wordIndex) {
            res[*count] = (int*)malloc(2 * sizeof(int));
            res[*count][0] = wordIndex;
            res[*count][1] = palIdx;
            (*colSizes)[*count] = 2;
            (*count)++;
        }
    }
}

void freeTrie(TrieNode* root) {
    if (!root) return;
    for (int i = 0; i < 26; i++) {
        freeTrie(root->children[i]);
    }
    free(root->palindromeIndexes);
    free(root);
}

int** palindromePairs(char** words, int wordsSize, int* returnSize, int** returnColumnSizes) {
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) {
        insert(root, words[i], i);
    }
    
    int maxPairs = wordsSize * wordsSize; 
    int** res = (int**)malloc(maxPairs * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPairs * sizeof(int));
    int count = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        search(root, words[i], i, res, &count, returnColumnSizes);
    }
    
    *returnSize = count;
    res = (int**)realloc(res, count * sizeof(int*));
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, count * sizeof(int));
    
    freeTrie(root);
    return res;
}
