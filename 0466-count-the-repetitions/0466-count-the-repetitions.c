
#include <stdlib.h>
#include <string.h>

/*
 * Key Insight: Cycle Detection
 * ----------------------------
 * As we scan through copies of s1 matching characters of s2,
 * the state at the START of each s1 copy is determined solely by
 * where we are in s2 (i.e., the index j within s2).
 *
 * Since j ∈ [0, len2), the state MUST repeat within len2 copies of s1.
 * Once we find a cycle, we can skip ahead and compute the answer.
 *
 * Time:  O(len1 * len2)  — at most len2 distinct states, each costs len1
 * Space: O(len2)
 */

int getMaxRepetitions(char* s1, int n1, char* s2, int n2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 == 0 || len2 == 0 || n1 == 0 || n2 == 0) return 0;

    // For each s1 copy index i (0-based), after processing s1 copies [0..i]:
    //   s2CountPerS1[i] = total number of complete s2's matched so far
    //   nextIdxInS2[i]  = position j in s2 where we'd continue matching

    // We only need to track states until a cycle is found.
    // A state is the index j in s2 at the START of processing an s1 copy.
    // There are at most len2 distinct states, so cycle found within len2+1 copies.

    // recall[j] = the s1 copy index where we first started with s2-index j
    int* recall = (int*)malloc(len2 * sizeof(int));
    // s2Count[i] = cumulative s2 completions after processing i-th s1 copy
    int* s2Count = (int*)malloc((n1 + 1) * sizeof(int));

    memset(recall, -1, len2 * sizeof(int));
    s2Count[0] = 0;

    int j = 0;           // current index in s2
    int totalS2 = 0;     // total complete s2's matched

    for (int i = 0; i < n1; i++) {
        // Check if we've seen this s2-index state before
        if (recall[j] != -1) {
            // Found a cycle!
            int cycleStart = recall[j];
            int cycleLen = i - cycleStart;
            int s2InCycle = totalS2 - s2Count[cycleStart];

            // How many full cycles fit in the remaining s1 copies?
            int remaining = n1 - cycleStart;
            int fullCycles = remaining / cycleLen;
            int leftover = remaining % cycleLen;

            // Total s2 count = 
            //   s2's before cycle + full cycles * s2's per cycle + s2's in leftover
            int answer = s2Count[cycleStart] 
                       + fullCycles * s2InCycle 
                       + (s2Count[cycleStart + leftover] - s2Count[cycleStart]);

            free(recall);
            free(s2Count);
            return answer / n2;
        }

        recall[j] = i;
        s2Count[i] = totalS2;

        // Process one full copy of s1, matching characters of s2
        for (int k = 0; k < len1; k++) {
            if (s1[k] == s2[j]) {
                j++;
                if (j == len2) {
                    j = 0;
                    totalS2++;
                }
            }
        }
    }

    // No cycle found — we processed all n1 copies of s1
    free(recall);
    free(s2Count);
    return totalS2 / n2;
}

