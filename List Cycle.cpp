/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    //Floyd Loop-Detection Algorithm
    ListNode* fast=A;
    ListNode* slow=A;
    while(slow!=nullptr && fast!=nullptr) //This bit is used to detect the loop
    {
        if(fast->next==nullptr || fast->next->next==nullptr) return nullptr;
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    ListNode* ret=A;
    while(ret!=slow) //Not sure how this works, but gave correct result for all the pen/paper examples I tried
    {
        ret=ret->next;
        slow=slow->next;
    }
    return ret;
}
