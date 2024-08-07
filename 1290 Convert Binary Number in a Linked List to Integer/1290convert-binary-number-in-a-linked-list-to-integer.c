/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    struct ListNode *ptr=head;
    int l=0,b=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        l++;
    }
    ptr=head;
    while(ptr!=NULL){
        b+=ptr->val*pow(2,l-1);
        l--;
        ptr=ptr->next;
    }
    return b;
}