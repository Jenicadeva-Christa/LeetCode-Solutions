
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * Bottom-Up Merge Sort (Iterative)
 * --------------------------------
 * Instead of recursion (which uses O(log n) stack space),
 * we iteratively merge sublists of size 1, 2, 4, 8, ...
 * until the entire list is sorted.
 *
 * Time:  O(n log n)
 * Space: O(1)
 */

// ---- Helper: Split off the first `size` nodes and return the rest ----
struct ListNode* splitList(struct ListNode* head, int size) {
    for (int i = 1; head && i < size; i++) {
        head = head->next;
    }
    if (!head) return NULL;

    struct ListNode* rest = head->next;
    head->next = NULL;  // cut
    return rest;
}

// ---- Helper: Merge two sorted lists, return merged head ----
// Also sets *tail to the last node of the merged list
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2, struct ListNode** tail) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* curr = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    curr->next = l1 ? l1 : l2;

    // Advance curr to the very last node
    while (curr->next) {
        curr = curr->next;
    }

    *tail = curr;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    // ---- Step 1: Count total nodes ----
    int length = 0;
    struct ListNode* node = head;
    while (node) {
        length++;
        node = node->next;
    }

    // ---- Step 2: Bottom-up merge sort ----
    struct ListNode dummy;
    dummy.next = head;

    for (int size = 1; size < length; size *= 2) {
        struct ListNode* curr = dummy.next;  // start of unsorted portion
        struct ListNode* tail = &dummy;      // tail of sorted portion

        while (curr) {
            // Split out two sublists of `size` each
            struct ListNode* left = curr;
            struct ListNode* right = splitList(left, size);
            curr = splitList(right, size);  // remainder for next iteration

            // Merge the two sublists and attach to sorted portion
            struct ListNode* mergedTail;
            tail->next = merge(left, right, &mergedTail);
            tail = mergedTail;
        }
    }

    return dummy.next;
}

