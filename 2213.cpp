#include<bits/stdc++.h>

using namespace std;

// Structure to hold the segment tree node data
struct Node {
    int max_len;
    int pref_len, suff_len;
    char pref_char, suff_char;
    int size;
};

class SegmentTree {
    vector<Node> tree;
    string s;
    int n;

    // Helper function to merge two segment nodes
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.size = left.size + right.size;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;

        // Calculate prefix length
        res.pref_len = left.pref_len;
        if (left.pref_len == left.size && left.pref_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }

        // Calculate suffix length
        res.suff_len = right.suff_len;
        if (right.suff_len == right.size && right.suff_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }

        // Calculate the maximum length in the current segment
        res.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, val, val, 1};
            s[idx] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(string str) {
        s = str;
        n = s.length();
        tree.resize(4 * n);
        if (n > 0) {
            build(1, 0, n - 1);
        }
    }

    void update(int idx, char val) {
        update(1, 0, n - 1, idx, val);
    }

    int getMax() {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        vector<int> ans;
        int k = queryCharacters.length();
        
        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans.push_back(st.getMax());
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "babacc";
    string queryCharacters = "bcb";
    vector<int> queryIndices = {1, 3, 5};
    vector<int> result = sol.longestRepeating(s, queryCharacters, queryIndices);

    cout << "The longest repeating characters after each query are: ";
    for (int len : result) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}