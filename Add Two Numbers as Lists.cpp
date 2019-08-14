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

ListNode* sumToList(ListNode* A, ListNode* B)
{
    ListNode* curr_1=A; ListNode* curr_2=B;
    ListNode* ret=nullptr; ListNode* prev=nullptr; ListNode* temp;
    int carry_over=0, x;
    while(curr_1!=nullptr && curr_2!=nullptr)
    {
        x=(curr_1->val)+(curr_2->val)+carry_over;
        if(x<10) carry_over=0;
        else
        {
            carry_over=(x/10);
            x=(x%10);
        }
        temp=getNewNode(x);
        if(ret==nullptr) ret=temp;
        else prev->next=temp;
        prev=temp;
        curr_1=curr_1->next;
        curr_2=curr_2->next;
    }
    while(curr_1!=nullptr)
    {
        x=(curr_1->val)+carry_over;
        if(x<10) carry_over=0;
        else
        {
            carry_over=(x/10);
            x=(x%10);
        }
        temp=getNewNode(x);
        if(ret==nullptr) ret=temp;
        else prev->next=temp;
        prev=temp;
        curr_1=curr_1->next;
    }
    while(curr_2!=nullptr)
    {
        x=(curr_2->val)+carry_over;
        if(x<10) carry_over=0;
        else
        {
            carry_over=(x/10);
            x=(x%10);
        }
        temp=getNewNode(x);
        if(ret==nullptr) ret=temp;
        else prev->next=temp;
        prev=temp;
        curr_2=curr_2->next;
    }
    if(carry_over>0)
    {
        temp=getNewNode(carry_over);
        prev->next=temp;
    }
    return ret;
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
    ListNode* head_1; ListNode* head_2;
    //List 1
    head_1=nullptr;
    cout<<"Enter number of inputs in List 1: ";
    int n_1, n_2, temp; cin>>n_1;
    for(int i=0; i<n_1; i++)
    {
        cin>>temp;
        push(&head_1,temp);
    }
    cout<<"List 1: "; printList(head_1); cout<<endl;
    //List 2
    head_2=nullptr;
    cout<<"Enter number of inputs in List 2: "; cin>>n_2;
    for(int i=0; i<n_2; i++)
    {
        cin>>temp;
        push(&head_2,temp);
    }
    cout<<"List 2: "; printList(head_2); cout<<endl;
    ListNode* result=sumToList(head_1, head_2);
    cout<<"Result: "; printList(result); cout<<endl;
    return 0;
}
