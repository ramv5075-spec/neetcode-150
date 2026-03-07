// NeetCode 150 - Tries
// Problem: Design Add and Search Words Data Structure
// Difficulty: Medium
// Approach: Trie + DFS
// Time Complexity: O(n) average, O(26^n) in worst case with dots
// Space Complexity: O(n)

#include <string>
using namespace std;

class WordDictionary {
    struct Node {
        Node* links[26];
        bool flag = false;

        bool containsKey(char ch) {
            return (links[ch - 'a'] != NULL);
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };

private:
    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool dfsSearch(string& word, int index, Node* node) {
        if (!node) return false;
        if (index == word.size()) return node->isEnd();

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] && dfsSearch(word, index + 1, node->links[i])) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->containsKey(ch)) return false;
            return dfsSearch(word, index + 1, node->get(ch));
        }
    }

    bool search(string word) {
        return dfsSearch(word, 0, root);
    }
};