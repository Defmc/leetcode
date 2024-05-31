#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
  int val;
  struct TreeNode *left, *right;
} TreeNode;

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
  if (p == NULL || q == NULL) {
    return p == q;
  }
  return p->val == q->val && isSameTree(p->left, q->left) &&
         isSameTree(p->right, q->right);
}
