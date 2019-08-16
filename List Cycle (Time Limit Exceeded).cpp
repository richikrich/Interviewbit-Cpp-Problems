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
    ListNode* curr=A;
    vector<ListNode*> vect;
    while(curr!=nullptr)
    {
        if(count(vect.begin(),vect.end(),curr)) return curr;
        else
        {
            vect.push_back(curr);
            curr=curr->next;
        }
    }
    if(curr==nullptr) return nullptr;

}
