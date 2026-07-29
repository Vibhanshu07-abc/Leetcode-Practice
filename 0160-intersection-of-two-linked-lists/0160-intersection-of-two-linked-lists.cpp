class Solution {
public:
    int length(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);

        ListNode *A = headA;
        ListNode *B = headB;

        int diff = abs(lenA - lenB);

        if (lenA > lenB) {
            while (diff--) {
                A = A->next;
            }
        } else {
            while (diff--) {
                B = B->next;
            }
        }

        while (A != B) {
            A = A->next;
            B = B->next;
        }

        return A;
    }
};