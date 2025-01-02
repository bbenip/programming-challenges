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
    ListNode* middleNode(ListNode* head) {
      ListNode sentinel = ListNode(0, head);

      ListNode* slow = &sentinel;
      ListNode* fast = &sentinel;

      while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;

        if (fast == nullptr) {
          break;
        }

        fast = fast->next;
      }

      return slow;
    }
};
