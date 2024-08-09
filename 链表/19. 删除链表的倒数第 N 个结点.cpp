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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Pre = new ListNode(0);
        Pre->next = head;
        ListNode *Nextn = head, *Cur = head;
        for (int i = 1; i <= n; i++) {
            Nextn = Nextn->next;
        }
        while (Nextn != nullptr) {
            Nextn = Nextn->next;
            Cur = Cur->next;
            Pre = Pre->next;
        }
        if (Pre->next) {
            Pre->next = Cur->next;
        } else {
            return nullptr;
        }
        if (Cur == head) {
            return head->next;
        }
        delete Cur;

        return head;
    }
};
