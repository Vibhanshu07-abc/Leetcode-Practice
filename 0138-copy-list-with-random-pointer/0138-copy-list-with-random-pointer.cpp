/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return head;
        Node* curr=head;
        Node*newhead=nullptr;
        Node*prev=nullptr;
        unordered_map<Node*,Node*>mp;
        while(curr){
         Node* temp=new Node(curr->val);
            mp[curr]=temp;
            if(newhead==nullptr){
                newhead=temp;
                prev=temp;
            }else{
                prev->next=temp;
                prev=temp;
            }
            curr=curr->next;
        }
        // filling start
        curr=head;
       Node* newcurr=newhead;
        while(curr){
            if(curr->random==nullptr){
                newcurr->random=nullptr;
            }else{
                newcurr->random=mp[curr->random];
            }
            curr=curr->next;
            newcurr=newcurr->next;
        }
        return newhead;
    }
};