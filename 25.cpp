#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *reverse(ListNode *head, size_t k) {
    if (k == 1) {
      return head;
    } else if (!head->next) {
      return nullptr;
    } else {
      ListNode *front = head->next;
      ListNode *base = reverse(front, k - 1);
      if (!base)
        return nullptr;
      head->next = front->next;
      front->next = head;
      return base;
    }
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1)
      return head;
    ListNode *newHead = reverse(head, k);
    ListNode *node = head;

    while (node && node->next) {
      ListNode *rev = reverse(node->next, k);
      if (!rev) {
        break;
      }
      ListNode *last = node->next;
      node->next = rev;
      node = last;
    }

    return newHead;
  }
};
