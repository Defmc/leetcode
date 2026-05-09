#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  size_t recRem(ListNode *node, size_t toRemove) {
    if (!node->next) {
      return 1;
    } else {
      const size_t currIdx = recRem(node->next, toRemove);
      if (currIdx == toRemove) {
        node->next = node->next->next;
      }
      return currIdx + 1;
    }
  }

public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (recRem(head, n) == n) {
      return head->next;
    }
    return head;
  }
};
