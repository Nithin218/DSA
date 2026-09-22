class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int n, k;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left
        for (int i = 0; i < k; i++) {
            res.cnt[i] += a.cnt[i];
        }

        // Prefixes which enter right
        for (int i = 0; i < k; i++) {
            int rem = (a.prod * i) % k;
            res.cnt[rem] += b.cnt[i];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % k;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, 2 * node + 1, l, mid);
        build(nums, 2 * node + 2, mid + 1, r);

        tree[node] = merge(tree[2 * node + 1],
                           tree[2 * node + 2]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] = Node();

            val %= k;
            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * node + 1, l, mid, pos, val);
        else
            update(2 * node + 2, mid + 1, r, pos, val);

        tree[node] = merge(tree[2 * node + 1],
                           tree[2 * node + 2]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr)
            return Node();

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        Node left = query(2 * node + 1, l, mid, ql, qr);
        Node right = query(2 * node + 2, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->k = k;
        n = nums.size();

        tree.resize(4 * n);

        build(nums, 0, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update nums[index]
            update(0, 0, n - 1, index, value);

            // Query [start, n-1]
            Node res = query(0, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};