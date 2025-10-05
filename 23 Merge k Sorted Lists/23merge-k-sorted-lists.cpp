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
    struct compare{
        bool operator()(ListNode *l1,ListNode *l2){
            return l1->val>l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;

        for(auto k:lists){
            if(k!=NULL){
                pq.push(k);
            }
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        while(!pq.empty()){
            ListNode *top=pq.top();
            pq.pop();

            curr->next=top;
            curr=top;

            if((top->next)!=NULL){
                pq.push(top->next);
            }
        }
        return dummy->next;
    }
};