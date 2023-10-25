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
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) {
        return nullptr;
      }

      ListNode* previousNode = head;
      ListNode* currentNode = head->next;

      while (currentNode != nullptr) {
        if (previousNode->val == currentNode->val) {
          previousNode->next = currentNode->next;
        } else {
          previousNode = currentNode;
        }

        currentNode = currentNode->next;
      }

      return head;
    }
};
