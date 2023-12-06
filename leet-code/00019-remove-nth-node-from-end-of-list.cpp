/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode* next) : val(x), next(next) {}
 * };
 */

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* slow = head;
      ListNode* fast = head;

      for (int i = 0; i < n; ++i) {
        fast = fast->next;
      }

      if (fast == nullptr) {
        ListNode* newHead = head->next;
        head->next = nullptr;

        return newHead;
      }

      while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
      }

      // slow->next is guaranteed to be a node
      // Since slow must be before fast and fast is guaranteed to be a node

      ListNode* removedNode = slow->next;
      slow->next = slow->next->next;
      removedNode->next = nullptr;

      return head;
    }
};
