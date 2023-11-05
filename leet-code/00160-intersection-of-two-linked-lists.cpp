/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
  public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      unordered_set<ListNode*> visitedNodes;

      while (headA != nullptr) {
        visitedNodes.insert(headA);
        headA = headA->next;
      }

      while (headB != nullptr) {
        if (visitedNodes.contains(headB)) {
          return headB;
        }

        headB = headB->next;
      }

      return nullptr;
    }
};
