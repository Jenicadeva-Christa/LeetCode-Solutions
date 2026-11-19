struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    struct ListNode* tail = head;
    int length = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    
    k = k % length;
    if (k == 0) {
        return head; 
    }
    
    tail->next = head;
    
    struct ListNode* new_tail = head;
    for (int i = 0; i < length - k - 1; i++) {
        new_tail = new_tail->next;
    }
    
    struct ListNode* new_head = new_tail->next;
    new_tail->next = NULL;
    
    return new_head;
}

