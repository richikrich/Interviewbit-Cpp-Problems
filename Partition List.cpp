#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getNewNode(int x)
{
    ListNode* newNode=new ListNode(x);
    //newNode->val=x;
    //newNode->next=nullptr;
    return newNode;
}

ListNode* partitionList(ListNode* A, int B)
{
    ListNode* prev=A;
    ListNode* curr=A->next;
    if(curr==nullptr) return A;
    ListNode* last_right; ListNode* temp;
    if(A->val<B) last_right=A;
    else
    {
        while(curr!=nullptr && curr->val>=B)
        {
            prev=prev->next;
            curr=curr->next;
        }
        if(curr==nullptr) return A;
        else
        {
        temp=curr;
        prev->next=curr->next;
        temp->next=A;
        A=temp;
        last_right=A;
        curr=prev->next;
        }
    }
    while(curr!=nullptr && prev!=nullptr)
    {
        if(curr->val>=B)
        {
            curr=curr->next;
            prev=prev->next;
        }
        else
        {
            if(prev->val<B)
            {
                curr=curr->next;
                prev=prev->next;
                last_right=prev;
            }
            else
            {
                temp=curr;
            prev->next=curr->next;
            temp->next=last_right->next;
            last_right->next=temp;
            curr=prev->next;
            last_right=last_right->next;
            }
        }
    }
    return A;
}

//the next 2 functions are utility functions and can be defined differently
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
    ListNode* temp=new ListNode(x);
    //temp->val=x;
    temp->next=*A;
    *A=temp; //the pointer to head will now point to temp;
}
//main function
int main()
{
    ListNode* head; //ListNode* head_2;
    head=nullptr;
    cout<<"Enter number of inputs: ";
    int n, temp; cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        push(&head,temp);
    }
    cout<<"List: "; printList(head); cout<<endl;
    cout<<"Enter key value "; int key; cin>>key;
    ListNode* result=partitionList(head,key);
    cout<<"Result: "; printList(result); cout<<endl;
    return 0;
}
