class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *mid = MidNode(head);
        ListNode *next = mid->next;
        mid->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(next);

        return Merge(left, right);
    }
    //找中间节点
    ListNode *MidNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    //  合并两个有序链表
    ListNode *Merge(ListNode *head1, ListNode *head2)
    {
        ListNode *head = nullptr, *Cur = nullptr;
        if (head1->val > head2->val)
        {
            head = head2;
            Cur = head2;
            head2 = head2->next;
        }
        else
        {
            head = head1;
            Cur = head1;
            head1 = head1->next;
        }

        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val > head2->val)
            {
                Cur->next = head2;
                head2 = head2->next;
            }
            else
            {
                Cur->next = head1;
                head1 = head1->next;
            }
            Cur = Cur->next;
        }

        if (head1 != nullptr)
        {
            Cur->next = head1;
        }
        if (head2 != nullptr)
        {
            Cur->next = head2;
        }
        return head;
    }
};
