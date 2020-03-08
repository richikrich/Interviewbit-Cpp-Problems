/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int count=1, counter=2;
    ListNode* temp;
    ListNode* prev;
    temp=A;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
        count+=1;
    }
    if(B>=count)
    {
        A=A->next;
        return A;
    }
    count=count-B+1;
    temp=A->next;
    prev=A;
    while(prev->next!=nullptr)
    {
        if(counter==count)
        {
            prev->next=temp->next;
            free(temp);
            return A;
        }
        else
        {
            prev=prev->next;
            temp=temp->next;
            counter++;
        }
    }
    return A;
}
