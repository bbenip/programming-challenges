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
    int getSize(ListNode* head) {
      int size = 0;

      while (head != nullptr) {
        size += 1;
        head = head->next;
      }

      return size;
    }

    ListNode* reverseList(ListNode* head) {
      ListNode* previousNode = nullptr;
      ListNode* currentNode = head;

      while (currentNode != nullptr) {
        ListNode* temporaryNode = currentNode->next;

        currentNode->next = previousNode;

        previousNode = currentNode;
        currentNode = temporaryNode;
      }

      return previousNode;
    }

  public:
    int pairSum(ListNode* head) {
      const int size = getSize(head);

      ListNode* head1 = head;

      for (int i = 1; i < size / 2; ++i) {
        head = head->next;
      }

      ListNode* head2 = head->next;
      head->next = nullptr;

      head2 = reverseList(head2);

      int maxTwinSum = 0;

      for (int i = 0; i < size / 2; ++i) {
        const int twinSum = head1->val + head2->val;

        maxTwinSum = max(maxTwinSum, twinSum);

        head1 = head1->next;
        head2 = head2->next;
      }

      return maxTwinSum;
    }
};
