
#include <bits/stdc++.h>

using namespace std;
class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

/// Base class for Trie
class AbstractBST {
public:
    virtual void insert(string &word) = 0;

    virtual bool search(string &word) = 0;

    virtual vector<string> autocomplete(string &prefix) = 0;


};

class Trie : public AbstractBST {
private:
    TrieNode *root;

    TrieNode *insert(TrieNode *node,  string &word, int index) {
        if (!node) {
            node = new TrieNode;
        }
        if (index == word.length()) {
            node->isEndOfWord = true;
        } else {
            char currentChar = word[index];
            if (!node->children[currentChar]) {
                node->children[currentChar] = insert(node->children[currentChar], word, index + 1);
            } else {
                insert(node->children[currentChar], word, index + 1);
            }
        }
        return node;
    }

    bool search(TrieNode *node,  string &word, int index) {
        if (!node) {
            return false;
        }
        if (index == word.length()) {
            return node->isEndOfWord;
        }
        char currentChar = word[index];
        if (!node->children[currentChar]) {
            return false;
        }
        return search(node->children[currentChar], word, index + 1);
    }

    

    void findWordsWithPrefix(TrieNode* node,  string& prefix, vector<string>& result, string current) {
        if (!node) {
            return;
        }

        if (node->isEndOfWord) {
            result.push_back(prefix + current);
        }

        for ( auto& kvp : node->children) {
            findWordsWithPrefix(kvp.second, prefix, result, current + kvp.first);
        }
    }

public:
    Trie() : root(new TrieNode) {}

    void insert( string &word) override{
        root = insert(root, word, 0);
    }

    bool search( string &word) override{
        return search(root, word, 0);
    }

    

    vector<string> autocomplete(string& prefix) override {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c]) {
                return {};
            }
            node = node->children[c];
        }

        vector<string> result;
        findWordsWithPrefix(node, prefix, result, "");
        return result;
    }
};
