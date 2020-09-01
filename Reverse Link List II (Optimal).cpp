/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* A)
{
    ListNode* prev;
    ListNode* node;
    ListNode* next;
    node=A; prev=nullptr;
    while(node)
    {
        next=node->next;
        node->next=prev;
        prev=node;
        node=next;
    }
    return prev;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B>=C) return A;

    ListNode* head=new ListNode(0);
    head->next=A;
    ListNode* prev; ListNode* node; ListNode* prevB; ListNode* nodeB; ListNode* followC;
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
            //prevC=prev;
            nodeC=node;
            followC=node->next;
            break;
        }
        count++;
        node=node->next;
        prev=prev->next;
    }
    //isolating selected section
    prevB->next=nodeC->next;
    nodeC->next=nullptr;
    nodeB=reverseList(nodeB);
    prevB->next=nodeB;
    temp=nodeB;
    while(temp->next) temp=temp->next;
    temp->next=followC;
    return head->next;
}
