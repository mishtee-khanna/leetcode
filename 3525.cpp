#include <vector>

using namespace std;

struct Node {
    int prod = 1;
    int cnt[5] = {0}; 
};

class Solution {
    vector<Node> tree;
    int K;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % K;
        
        for(int i = 0; i < K; ++i) {
            res.cnt[i] = left.cnt[i];
        }
        
        for(int i = 0; i < K; ++i) {
            if (right.cnt[i] > 0) {
                int new_rem = (left.prod * i) % K;
                res.cnt[new_rem] += right.cnt[i];
            }
        }
        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % K;
            tree[node].prod = val;
            tree[node].cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, nums);
        build(2 * node + 2, mid + 1, end, nums);
        tree[node] = mergeNodes(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int v = val % K;
            tree[node].prod = v;
            for (int i = 0; i < K; ++i) tree[node].cnt[i] = 0;
            tree[node].cnt[v] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = mergeNodes(tree[2 * node + 1], tree[2 * node + 2]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node + 1, start, mid, l, r);
        } else if (l > mid) {
            return query(2 * node + 2, mid + 1, end, l, r);
        } else {
            Node left = query(2 * node + 1, start, mid, l, r);
            Node right = query(2 * node + 2, mid + 1, end, l, r);
            return mergeNodes(left, right);
        }
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        K = k;
        tree.resize(4 * n);
        
        build(0, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int idx = q[0], val = q[1], st = q[2], x = q[3];
            
            update(0, 0, n - 1, idx, val);

            Node res = query(0, 0, n - 1, st, n - 1);
            result.push_back(res.cnt[x]);
        }
        
        return result;
    }
};

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(4));

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> queries[i][j];
        }
    }

    Solution sol;

    vector<int> ans = sol.resultArray(nums, k, queries);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
