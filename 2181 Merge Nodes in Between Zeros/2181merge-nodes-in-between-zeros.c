struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode *p = head->next;
    struct ListNode *q = p;
    while (p != NULL) {
        int c = 0;
        while (p->val != 0) {
            c += p->val;
            p = p->next;
        }
        q->val = c;
        p = p->next;
        if (p != NULL) {
            q = q->next;
        }
    }
    
    q->next = NULL;
    return head->next;
}
