class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* current = head;
        ListNode* future = nullptr;
        ListNode* prev = nullptr;

        while (current != nullptr) {
            future = current->next;
            current->next = prev;
            prev = current;
            current = future;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* ptr = reverse(slow->next);
        slow->next = nullptr;

        ListNode* start = head;

        while (ptr != nullptr) {
            ListNode* firstNext = start->next;
            ListNode* secondNext = ptr->next;
            start->next = ptr;
            ptr->next = firstNext;
            start = firstNext;
            ptr = secondNext;
        }
    }
};