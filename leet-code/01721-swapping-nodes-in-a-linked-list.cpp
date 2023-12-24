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
    ListNode* swapNodes(ListNode* head, int k) {
      ListNode* kthNodeFromStart = head;

      for (int i = 1; i < k; ++i) {
        kthNodeFromStart = kthNodeFromStart->next;
      }

      ListNode* fastNode = kthNodeFromStart;
      ListNode* kthNodeFromEnd = head;

      while (fastNode->next != nullptr) {
        kthNodeFromEnd = kthNodeFromEnd->next;
        fastNode = fastNode->next;
      }

      swap(kthNodeFromStart->val, kthNodeFromEnd->val);

      return head;
    }
};
