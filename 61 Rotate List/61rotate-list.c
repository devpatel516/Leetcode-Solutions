/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL){
        return head;
    }
    struct ListNode* curr=head;
    int len=1;
    while(curr->next!=NULL){
        curr=curr->next;
        len++;
    }
    k=k%len;
    if(k==0){
        return head;
    }
    curr->next=head;
    curr=head;
    for(int i=1;i<len-k;i++){
        curr=curr->next;
    }
    head=curr->next;
    curr->next=NULL;
    return head;
}