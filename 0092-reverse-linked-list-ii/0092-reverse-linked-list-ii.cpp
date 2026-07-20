class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* ptr = dummy;

        // Move ptr to the node just before the 'left' position
        for (int i = 1; i < left; i++) {
            ptr = ptr->next;
        }

        ListNode* start = ptr->next;
        ListNode* current = start;
        ListNode* prev = nullptr;
        ListNode* future = nullptr;

        // Reverse the sublist
        for (int i = left; i <= right; i++) {
            future = current->next;
            current->next = prev;
            prev = current;
            current = future;
        }

        // Reconnect the reversed sublist
        ptr->next = prev;
        start->next = current;

        ListNode* ans = dummy->next;
        delete dummy;   // Prevent memory leak

        return ans;
    }
};