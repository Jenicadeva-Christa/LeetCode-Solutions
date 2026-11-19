/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode* root, int* prev, int* count, int* maxCount, int** modes, int* returnSize) {
    if (!root) return;

    inorder(root->left, prev, count, maxCount, modes, returnSize);

    // Count frequency
    if (*prev == root->val) {
        (*count)++;
    } else {
        *count = 1;
        *prev = root->val;
    }

    if (*count > *maxCount) {
        *maxCount = *count;
        *returnSize = 1;
        *modes = realloc(*modes, (*returnSize) * sizeof(int));
        (*modes)[0] = root->val;
    } else if (*count == *maxCount) {
        (*returnSize)++;
        *modes = realloc(*modes, (*returnSize) * sizeof(int));
        (*modes)[(*returnSize) - 1] = root->val;
    }

    inorder(root->right, prev, count, maxCount, modes, returnSize);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int* modes = NULL;
    *returnSize = 0;

    int prev = 0;        // Last visited value
    int count = 0;       // Frequency of current value
    int maxCount = 0;    // Max frequency seen so far

    // Trick: INT_MIN cannot be first node if negative values possible
    // So mark first node with a separate flag
    inorder(root, &prev, &count, &maxCount, &modes, returnSize);

    return modes;
}