/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* sum = NULL;
    struct ListNode* current = NULL;
    int c = 0;
    while (l1 != NULL || l2 != NULL || c != 0) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        int total = val1 + val2 + c;
        c = total / 10;
        total = total % 10;
        struct ListNode* ptr =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        ptr->val = total;
        ptr->next = NULL;
        if (sum == NULL) {
            sum = ptr;
            current = sum;
        } else {
            current->next = ptr;
            current = ptr;
        }
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }
    return sum;
}