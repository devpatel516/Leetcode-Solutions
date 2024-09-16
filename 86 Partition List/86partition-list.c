/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *before = NULL, *after = NULL;
    struct ListNode *before_curr = NULL, *after_curr = NULL;
    
    while(head != NULL){
        if(head->val < x){
            if(before == NULL) {
                before = head;
                before_curr = before;
            } else {
                before_curr->next = head;
                before_curr = head;
            }
        } else {
            if(after == NULL) {
                after = head;
                after_curr = after;
            } else {
                after_curr->next = head;
                after_curr = head;
            }
        }
        head = head->next;
    }
    
    if(after_curr != NULL) {
        after_curr->next = NULL; 
    }
    
    if(before == NULL) {
        return after;  
    }
    
    before_curr->next = after; 
    return before;
}
