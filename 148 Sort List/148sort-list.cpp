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
        ListNode* middle(ListNode* head){
            ListNode *slow=head;
            ListNode *fast=head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }
        ListNode *merge(ListNode* l1,ListNode *l2){
            ListNode dummy(0);
            ListNode *tail=&dummy;
            ListNode *p1=l1;
            ListNode *p2=l2;
            while(p1 && p2){
                if(p1->val<p2->val){
                    tail->next=p1;
                    p1=p1->next;
                }
                else{
                    tail->next=p2;
                    p2=p2->next;
                }
                tail=tail->next;
            }
            while(p1!=NULL){
                tail->next=p1;
                p1=p1->next;
                tail=tail->next;
            }
            while(p2!=NULL){
                tail->next=p2;
                p2=p2->next;
                tail=tail->next;
            }
            return dummy.next;
        }
        ListNode *mergeSort(ListNode* head){
            if(head==NULL || head->next==NULL){
                return head;
            }
            ListNode *mid=middle(head);
            ListNode *temp=head;
            while(head->next!=mid){
                head=head->next;
            }
            head->next=NULL;
            head=temp;
            ListNode *left=mergeSort(head);
            ListNode *right=mergeSort(mid);
            return merge(left,right);
        }
        ListNode* sortList(ListNode* head) {
            return mergeSort(head);
        }
    };