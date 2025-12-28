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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        int i=1;
        ListNode* prevl=dummy;
        while(prevl!=NULL && i<left){
            prevl=prevl->next;
            i++;
        }
        ListNode *a=prevl->next;
        ListNode *prev=NULL;
        ListNode *curr=a;
        ListNode *next;
        while(curr!=NULL && i<=right){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        prevl->next=prev;
        a->next=curr;
        return dummy->next;
    }
};