#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1000003

typedef struct Node {
    char sequence[11];
    int count;
    struct Node* next;
} Node;

unsigned int hash(const char* str) {
    unsigned int h = 0;
    for (int i = 0; i < 10; i++) {
        h = (h << 5) + h + str[i];
    }
    return h % HASH_SIZE;
}

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    *returnSize = 0;
    int len = strlen(s);
    if (len < 10) {
        return NULL;
    }

    Node** hashTable = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    char** result = (char**)malloc(sizeof(char*) * (len - 9));
    
    char temp[11];
    temp[10] = '\0';

    for (int i = 0; i <= len - 10; i++) {
        memcpy(temp, s + i, 10);
        unsigned int h = hash(temp);
        
        Node* curr = hashTable[h];
        int found = 0;
        
        while (curr != NULL) {
            if (strcmp(curr->sequence, temp) == 0) {
                curr->count++;
                if (curr->count == 2) {
                    result[*returnSize] = (char*)malloc(sizeof(char) * 11);
                    strcpy(result[*returnSize], temp);
                    (*returnSize)++;
                }
                found = 1;
                break;
            }
            curr = curr->next;
        }

        if (!found) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            strcpy(newNode->sequence, temp);
            newNode->count = 1;
            newNode->next = hashTable[h];
            hashTable[h] = newNode;
        }
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr != NULL) {
            Node* tempNode = curr;
            curr = curr->next;
            free(tempNode);
        }
    }
    free(hashTable);

    return result;
}
