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
    ListNode* removeElements(ListNode* head, int val) {
      ListNode auxiliaryHead(-1, head);

      ListNode* previousNode = &auxiliaryHead;
      ListNode* currentNode = head;

      while (currentNode != nullptr) {
        if (currentNode->val == val) {
          previousNode->next = currentNode->next;
        } else {
          previousNode = currentNode;
        }

        currentNode = currentNode->next;
      }

      ListNode* newHead = auxiliaryHead.next;
      auxiliaryHead.next = nullptr;

      return newHead;
    }
};
