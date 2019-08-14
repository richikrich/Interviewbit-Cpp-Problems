#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
/*Store the node addresses in a vector of node addresses and iterate over it as required*/
struct ListNode
{
    int val;
    ListNode* next;
};
//solution!
ListNode* reorder(ListNode* A)
{
    vector<ListNode*> vect;
    ListNode* curr=A;
    ListNode* after;
    while(curr!=NULL)
    {
        vect.push_back(curr);
        curr=curr->next;
    }
    int i=1, j=vect.size()-1;
    curr=A;
    while(i<=j)
    {
        if(i==j)
        {
            curr->next=vect[i];
            curr=curr->next;
            i++;
        }
        else
        {
            curr->next=vect[j];
            j--;
            curr=curr->next;
            curr->next=vect[i];
            i++;
            curr=curr->next;
        }
    }
    curr->next=nullptr;
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
