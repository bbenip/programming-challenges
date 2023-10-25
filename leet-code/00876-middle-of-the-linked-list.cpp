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
  private:
    int getListSize(ListNode* head) {
      int size = 0;

      while (head != nullptr) {
        head = head->next;
        size += 1;
      }

      return size;
    }

  public:
    ListNode* middleNode(ListNode* head) {
      const int listSize = getListSize(head);
      const int midwayIndex = listSize / 2;

      ListNode* node = head;

      for (int i = 0; i < midwayIndex; ++i) {
        node = node->next;
      }

      return node;
    }
};
