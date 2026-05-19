/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        Node *dummy=new Node(-1);
        Node *h=dummy;
        Node *temp=head;
        unordered_map<Node*,Node*> mp;
        while(temp){
            Node *k=new Node(temp->val);
            mp[temp]=k;
            h->next=k;
            h=h->next;
            temp=temp->next;
        }
        h=dummy->next;
        temp=head;
        while(temp){
            Node *k=temp->random;
            if(!k){
                h->random=NULL;
            }
            else{
                Node *x=mp[temp->random];
                h->random=x;
            }
            temp=temp->next;
            h=h->next;
        }
        return dummy->next;
    }
};