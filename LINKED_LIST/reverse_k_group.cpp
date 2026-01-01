#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
void reverse(ListNode* head,int times)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(times--)
        {
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return;
    }
    ListNode* swapPairs(ListNode* head ,int k) {
        if(head==NULL ) return head;
        ListNode* left=head;
        ListNode* res=NULL;
        ListNode* prevleft= NULL;
        ListNode* right;
        int size=k;
        while(true)
        {
            right=left;
            for(int i=0;i<(size-1);i++)
            {
                if(right==NULL) break;
                right=right->next;
            }
            if(right)
            {
                ListNode*nextleft=right->next;
                reverse(left,size);
                if(prevleft) prevleft->next=right;
                prevleft=left;
                if(res==NULL) res=right;
                left=nextleft;
            }
            else{
                if(prevleft) prevleft->next=left;
                if(res==NULL) res=left;
                break;
            }
        }
        return res;
     }

     int main(){
    ListNode* head=new ListNode(1);     

    head->next=new ListNode(2);     
    head->next->next=new ListNode(3);     
    head->next->next->next=new ListNode(4);                 
    head->next->next->next->next=new ListNode(5);   
    int k=3;
    ListNode* newhead=swapPairs(head,k);
    ListNode* temp=newhead;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}