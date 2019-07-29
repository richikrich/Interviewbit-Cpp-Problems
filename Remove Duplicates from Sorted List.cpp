#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* A)
{
    ListNode* temp;
    ListNode* curr;
    curr=A;
    while(curr!=nullptr && curr->next!=nullptr)
    {
        if(curr->val==curr->next->val)
        {
            temp=curr->next;
            curr->next=curr->next->next;
            free(temp);
            continue;
        }
        else curr=curr->next;
    }
    return A;
}

void append(ListNode** head_ref, int data)
{
    ListNode* new_node=new ListNode();
    ListNode *last=(*head_ref);
    new_node->val=data;
    new_node->next=nullptr;
    if(*head_ref==nullptr)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=nullptr)
    {
        last=last->next;
    }
    last->next=new_node;
    return;
}

void printList(ListNode *node)
{
    while(node!=nullptr)
    {
        cout<<node->val<<" ";
        node=node->next;
    }
    cout<<"\n";
}

int main()
{
    ListNode* head=nullptr;
    cout<<"Enter number of inputs: "; int n; cin>>n;
    cout<<"Inputs: ";
    for(int i=0; i<n; i++)
    {
        int temp; cin>>temp;
        append(&head,temp);
    }
    cout<<"The list is: ";
    printList(head);
    ListNode* result=deleteDuplicates(head);
    cout<<"Result: ";
    printList(result);
}
