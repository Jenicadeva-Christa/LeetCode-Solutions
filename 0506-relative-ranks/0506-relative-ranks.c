#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
        char** result = (char**)malloc(scoreSize * sizeof(char*));
    if (scoreSize == 0) return result;
    int max_score = score[0];
    for (int i = 1; i < scoreSize; i++) {
        if (score[i] > max_score) {
            max_score = score[i];
        }
    }
    int* score_to_index = (int*)calloc(max_score + 1, sizeof(int));
    for (int i = 0; i < scoreSize; i++) {
        score_to_index[score[i]] = i + 1; 
    }
    int rank = 1;
    for (int s = max_score; s >= 0; s--) {
        if (score_to_index[s] > 0) {
            int orig_idx = score_to_index[s] - 1; 
            result[orig_idx] = (char*)malloc(16 * sizeof(char));
            if (rank == 1) {
                strcpy(result[orig_idx], "Gold Medal");
            } else if (rank == 2) {
                strcpy(result[orig_idx], "Silver Medal");
            } else if (rank == 3) {
                strcpy(result[orig_idx], "Bronze Medal");
            } else {
                snprintf(result[orig_idx], 16, "%d", rank);
            }
            rank++;
        }
    }
    free(score_to_index);
    return result;
}
