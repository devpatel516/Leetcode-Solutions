/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int a=0,b=0;
    struct ListNode *listA=headA;
    struct ListNode *listB=headB;
    while(listA!=NULL){
        listA=listA->next;
        a++;
    }
    while(listB!=NULL){
        listB=listB->next;
        b++;
    }
    listA=headA;
    listB=headB;
    if(a>b){
    for(int i=0;i<(a-b);i++){
        listA=listA->next;
    }
    }
    else{
    for(int i=0;i<(b-a);i++){
        listB=listB->next;
    }
    }
    while(listA!=NULL && listB!=NULL){
    if(listA==listB){
        return listA;
    }
    listA=listA->next;
    listB=listB->next;
    }
    return 0;
}