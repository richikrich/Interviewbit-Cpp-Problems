#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* reorder(ListNode* A)
{
    //ListNode* head=A;
    ListNode* curr;
    ListNode* prev;
    ListNode* itr=A;
    while(itr!=nullptr)
    {
        curr=itr;
        prev=itr;
        if(curr->next==nullptr || curr->next->next==nullptr) return A;
        else curr=curr->next;
        while(curr->next!=nullptr)
        {
            prev=prev->next;
            curr=curr->next;
        }
        curr->next=itr->next;
        itr->next=curr;
        prev->next=nullptr;
        itr=itr->next->next;
    }
    return A;
}

//the next 3 functions are utility functions and can be defined differently
ListNode* getNewNode(int x)
{
    ListNode* newNode=new ListNode();
    newNode->val=x;
    newNode->next=nullptr;
    return newNode;
}

void printList(ListNode* A)
{
    ListNode* curr=A;
    while(curr!=nullptr)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}

void push(ListNode** A, int x)
{
    ListNode* temp=new ListNode();
    temp->val=x;
    temp->next=*A;
    *A=temp; //the pointer to head will now point to temp;
}

int main()
{
    ListNode* head;
    head=nullptr;
    cout<<"Enter number of inputs: ";
    int n, temp; cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        push(&head,temp);
    }
    cout<<"List: "; printList(head); cout<<endl;
    head=reorder(head);

    cout<<"After processing: "; printList(head); cout<<endl;
    return 0;
}
