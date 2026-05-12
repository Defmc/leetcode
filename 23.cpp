#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *merged(ListNode *a, ListNode *b) {
    ListNode *head = nullptr, *tail = nullptr;

    auto pushNode = [&](ListNode **p) {
      if (!head) {
        head = *p;
        tail = *p;
      } else {
        tail->next = *p;
        tail = tail->next;
      }
      *p = (*p)->next;
    };

    while (a || b) {
      if (!a) {
        pushNode(&b);
      } else if (!b) {
        pushNode(&a);
      } else if (a->val < b->val) {
        pushNode(&a);
      } else {
        pushNode(&b);
      }
    }

    return head;
  }

public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    while (lists.size() > 1) {
      for (size_t i = 0; i + 1 < lists.size(); i++) {
        lists[i] = merged(lists[i], lists[i + 1]);
        lists[i + 1] = std::move(lists.back());
        lists.pop_back();
      }
    }

    return lists.size() ? lists[0] : nullptr;
  }
};
