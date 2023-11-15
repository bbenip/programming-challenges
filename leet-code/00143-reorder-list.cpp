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
    void reorderList(ListNode* head) {
      vector<ListNode*> nodes;

      while (head != nullptr) {
        nodes.push_back(head);
        head = head->next;
      }

      int index1 = 0;
      int index2 = nodes.size() - 1;

      bool isEvenIteration = true;

      while (index1 < index2) {
        ListNode* node1 = nodes[index1];
        ListNode* node2 = nodes[index2];

        if (isEvenIteration) {
          node1->next = node2;
          index1 += 1;
        } else {
          node2->next = node1;
          index2 -= 1;
        }

        isEvenIteration = !isEvenIteration;
      }

      ListNode* lastNode = nodes[index1];
      lastNode->next = nullptr;
    }
};
