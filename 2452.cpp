#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class trie {
public:
  trie *nodes[26];
  trie() { memset(nodes, 0, sizeof(nodes)); }
};

bool within_edits(const string &w, const trie *node, size_t idx,
                  uint8_t edits) {
  if (idx == w.size())
    return true;

  uint8_t c = w[idx] - 'a';

  if (node->nodes[c] && within_edits(w, node->nodes[c], idx + 1, edits))
    return true;

  if (++edits > 2)
    return false;

  for (trie *inner : node->nodes) {
    if (inner && within_edits(w, inner, idx + 1, edits))
      return true;
  }

  return false;
}

class Solution {
public:
  vector<string> twoEditWords(vector<string> &queries,
                              vector<string> &dictionary) {
    trie root;

    for (auto &word : dictionary) {
      trie *curr = &root;
      for (char c : word) {
        trie **node = &curr->nodes[c - 'a'];
        if (!*node)
          *node = new trie();
        curr = *node;
      }
    }

    vector<string> words;

    for (auto &q : queries) {
      if (within_edits(q, &root, 0, 0))
        words.push_back(q);
    }

    return words;
  }
};
