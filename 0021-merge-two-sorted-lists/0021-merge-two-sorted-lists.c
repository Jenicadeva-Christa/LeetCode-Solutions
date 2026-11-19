struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode d;
    struct ListNode* t = &d;
    d.next = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            t->next = list1;
            list1 = list1->next;
        } else {
            t->next = list2;
            list2 =list2->next;
        }
        t = t->next;
    }
    if (list1 != NULL) {
        t->next = list1;
    } else {
        t->next = list2;
    }
    return d.next;
}