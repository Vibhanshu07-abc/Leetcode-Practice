/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode*reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*prev=nullptr;
        ListNode*future=nullptr;
        while(curr){
            future=curr->next;
            curr->next=prev;
            prev=curr;
            curr=future;
        }
        return prev;
     }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return true;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=reverse(slow->next);
        slow=head;
        while(fast){
            if(slow->val!=fast->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};