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
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return ;
        }

        ListNode *temp=head;
        int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        temp=head;
        int k=0;
        stack<ListNode*> st;
        while(temp!=NULL){
            if(k>(l/2)){
                st.push(temp);
            }
            k++;
            temp=temp->next;
        }
        temp = head;
        for (int i = 0; i < l / 2; i++) {
            temp = temp->next;
        }
        temp->next = NULL;
        ListNode *a=head;
        while(!st.empty()){
            ListNode *temp=a->next;
            a->next=st.top();
            st.pop();
            a->next->next=temp;
            a=temp;
        }
    }
};