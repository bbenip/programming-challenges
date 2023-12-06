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
  private:
    int getSize(ListNode* head) {
      int size = 0;

      while (head != nullptr) {
        size += 1;

        head = head->next;
      }

      return size;
    }

  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      const int size = getSize(head);
      const int indexOfElementToRemove = size - n;

      ListNode auxiliaryHead(-1, head);

      ListNode* node = &auxiliaryHead;

      for (int i = 0; i < indexOfElementToRemove; ++i) {
        node = node->next;
      }

      ListNode* removedNode = node->next;
      node->next = node->next->next;
      removedNode->next = nullptr;

      ListNode* newHead = auxiliaryHead.next;
      auxiliaryHead.next = nullptr;

      return newHead;
    }
};
