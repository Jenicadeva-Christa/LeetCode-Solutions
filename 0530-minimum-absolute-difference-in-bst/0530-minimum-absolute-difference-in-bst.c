int diff;
int pre;
int check;

void find(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    find(root->left);

    if (check) {
        int current_diff = abs(root->val - pre);
        if (current_diff < diff) {
            diff = current_diff;
        }
    } else {
        check = 1;
    }
    pre = root->val;

    find(root->right);
}

int getMinimumDifference(struct TreeNode* root) {
    diff = INT_MAX;
    pre = -1;
    check = 0;

    find(root);
    return diff;
}