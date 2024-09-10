/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode *current,*prev;
    current=head;
    prev=NULL;
    while(current!=NULL){
        if(current->next!=NULL && current->val == current->next->val){
            while(current->next!=NULL && current->val == current->next->val){
            current=current->next;
            }
            if(prev==NULL){
                head=current->next;
            }
            else{
            prev->next=current->next;}
        }
        else{
            prev=current;
        }
            current=current->next;
    }
    return head;
}