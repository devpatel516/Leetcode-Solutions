/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverse(ListNode *head){
    ListNode *prev=NULL,*temp=head,*fast;
    while(temp!=NULL){
        fast=temp->next;
        temp->next=prev;
        prev=temp;
        temp=fast;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (!head || !head->next) {
        return true; 
    }
    ListNode *slow=head,*fast=head;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode *newhead=reverse(slow);
    ListNode *first=head,*second=newhead;
    while(second!=NULL){
        if(first->val!=second->val){
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;
}
};