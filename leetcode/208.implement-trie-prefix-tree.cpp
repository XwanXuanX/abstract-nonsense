#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
struct TrieNode {
  TrieNode *child[26];
  bool isWord;

  TrieNode() {
    isWord = false;
    for (int i = 0; i < 26; ++i) {
      child[i] = nullptr;
    }
  }
};

class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *p = root;
    for (auto &c : word) {
      int i = c - 'a';
      if (p->child[i] == nullptr) {
        p->child[i] = new TrieNode();
      }
      p = p->child[i];
    }
    p->isWord = true;
  }

  bool search(string word) {
    TrieNode *p = root;
    for (auto &c : word) {
      int i = c - 'a';
      if (p->child[i] == nullptr) {
        return false;
      }
      p = p->child[i];
    }
    return p->isWord;
  }

  bool startsWith(string prefix) {
    TrieNode *p = root;
    for (auto &c : prefix) {
      int i = c - 'a';
      if (p->child[i] == nullptr) {
        return false;
      }
      p = p->child[i];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
