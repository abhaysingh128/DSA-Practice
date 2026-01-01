#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverse(ListNode* head) {
    if(head==NULL) return NULL;
    ListNode* curr=head;
    ListNode* prev=NULL;
   
    while(curr!=NULL)
    { 
        ListNode* nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;    
}
int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    ListNode* newhead=reverse(head);
    ListNode* temp=newhead;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}