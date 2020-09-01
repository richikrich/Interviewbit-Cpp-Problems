/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B>=C) return A;

    ListNode* head=new ListNode(0);
    head->next=A;
    ListNode* prev; ListNode* node; ListNode* prevB; ListNode* nodeB; ListNode* prevC;
    ListNode* nodeC; ListNode* temp;
    prev=head; node=A;
    int count=1;
    while(node!=nullptr)
    {
        if(count==B)
        {
            prevB=prev;
            nodeB=node;
        }
        else if(count==C)
        {
            prevC=prev;
            nodeC=node;
            break;
        }
        count++;
        node=node->next;
        prev=prev->next;
    }
    temp=nodeC;
    if(prevC==nodeB)
    {
       nodeB->next=temp->next;
       prevB->next=temp;
       temp->next=nodeB;
    }
    else
    {
    prevC->next=temp->next;
    temp->next=nodeB->next;
    prevB->next=temp;
    nodeB->next=prevC->next;
    prevC->next=nodeB;
    }
    return reverseBetween(head->next,B+1,C-1);
}
