/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode *a=head;
    struct ListNode *b=head->next;
    struct ListNode *c,*h=b;
    while(a!=NULL && b!=NULL){
        c=b->next;
        b->next=a;
        if(c!= NULL){
            if(c->next !=NULL){
                a->next=c->next;
            }
            else{
                a->next=c;
            }
        }
        else{
            a->next=NULL;
        }
        a=c;
        if(a!=NULL){
        b=a->next;
        }
    }
    return h;
}   