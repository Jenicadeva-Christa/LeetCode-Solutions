
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
 * BFS Approach:
 * - Treat each word as a node in a graph.
 * - Two nodes are connected if they differ by exactly one letter.
 * - BFS from beginWord finds the shortest path to endWord.
 */

// ---------- Helper: check if two words differ by exactly 1 character ----------
bool diffByOne(const char* a, const char* b, int len) {
    int diff = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int wordLen = strlen(beginWord);

    // ---- Step 1: Check if endWord exists in wordList ----
    int endIdx = -1;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            endIdx = i;
            break;
        }
    }
    if (endIdx == -1) return 0;

    // ---- Step 2: Setup BFS ----
    int totalNodes = wordListSize + 1;

    bool* visited = (bool*)calloc(totalNodes, sizeof(bool));
    int* queue = (int*)malloc(totalNodes * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue beginWord (index 0)
    queue[rear++] = 0;
    visited[0] = true;

    int level = 1;

    // ---- Step 3: BFS level-by-level ----
    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            int nodeIdx = queue[front++];

            const char* currentWord;
            if (nodeIdx == 0)
                currentWord = beginWord;
            else
                currentWord = wordList[nodeIdx - 1];

            // Try all words in wordList as neighbors
            for (int j = 0; j < wordListSize; j++) {
                int neighborIdx = j + 1;

                if (visited[neighborIdx]) continue;

                if (diffByOne(currentWord, wordList[j], wordLen)) {
                    // Found endWord? Return immediately
                    if (j == endIdx) {
                        free(visited);
                        free(queue);
                        return level + 1;
                    }

                    visited[neighborIdx] = true;
                    queue[rear++] = neighborIdx;
                }
            }
        }
        level++;
    }

    free(visited);
    free(queue);
    return 0;
}

