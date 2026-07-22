class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* ptr = head;
        int count = 1;

        while (ptr->next != nullptr) {
            ptr = ptr->next;
            count++;
        }

        k %= count;

        if (k == 0)
            return head;

        ptr->next = head;

        for (int i = 0; i < count - k; i++) {
            ptr = ptr->next;
        }

        head = ptr->next;
        ptr->next = nullptr;

        return head;
    }
};