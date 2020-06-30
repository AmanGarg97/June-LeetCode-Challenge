// Question -   Word Search II

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example:

Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]


Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

// Solution

class Solution {
private:
    struct Node {
        vector<Node*> ch;
        bool is_word;

        Node() : ch(26, nullptr), is_word(false) {};
    };

    Node* root = nullptr;
    vector<string> ans;

    void addWord(string& s) {
        Node* curr = root;
        for (int i = 0; i < s.size(); ++i) {
            if (curr->ch[s[i]-'a'] == nullptr) curr->ch[s[i]-'a'] = new Node;

            if (i == s.size() - 1) curr->ch[s[i]-'a']->is_word = true;

            curr = curr->ch[s[i]-'a'];
        }
    }

    void createTrie(vector<string> &words) {
        root = new Node;
        for (auto &e: words) addWord(e);
    }

    void checkAddWordHelper(vector<vector<char>> &board, int i, int j, string &s,
                            vector<vector<int>> &checked, Node* curr) {
        if (curr->ch[board[i][j] - 'a'] == nullptr) return;

        curr = curr->ch[board[i][j] - 'a'];
        s += board[i][j];
        checked[i][j] = 1;

        if (i-1 >=0 && checked[i-1][j] == 0) checkAddWordHelper(board, i-1, j, s, checked, curr);
        if (i+1 < board.size() && checked[i+1][j] == 0) checkAddWordHelper(board, i+1, j, s, checked, curr);
        if (j-1 >=0 && checked[i][j-1] == 0) checkAddWordHelper(board, i, j-1, s, checked, curr);
        if (j+1 < board[0].size() && checked[i][j+1] == 0) checkAddWordHelper(board, i, j+1, s, checked, curr);

        if (curr->is_word == true) {
            ans.push_back(s);
            curr->is_word = false;
        }

        s.pop_back();
        checked[i][j] = 0;
    };

    void checkAddWord(vector<vector<char>> &board, int i, int j) {
        string s;
        vector<vector<int>> checked( board.size(), vector<int>(board[0].size(), 0));
        checkAddWordHelper(board, i, j, s, checked, root);
    }

    void findWords(vector<vector<char>> &board) {
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                checkAddWord(board, i, j);
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        createTrie(words);
        findWords(board);

        return ans;
    }
};
