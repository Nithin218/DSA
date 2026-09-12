class Solution {
public:

    struct State {
        long long score;
        vector<int> indices;
    };

    vector<vector<State>> memo;
    vector<vector<int>> a;
    int n;

    State solve(int i, int k) {

        // No intervals left
        if (i == n || k == 0) {
            return {0, {}};
        }

        // Already calculated
        if (memo[i][k].score != -1) {
            return memo[i][k];
        }

        // -------------------------
        // OPTION 1: SKIP
        // -------------------------
        State skip = solve(i + 1, k);


        // -------------------------
        // OPTION 2: TAKE
        // -------------------------

        int end = a[i][1];
        int weight = a[i][2];
        int originalIndex = a[i][3];

        // Find first interval with start > end
        int lo = i + 1;
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (a[mid][0] > end)
                hi = mid;
            else
                lo = mid + 1;
        }

        int next = lo;

        State takeNext = solve(next, k - 1);

        State take;

        take.score = weight + takeNext.score;

        take.indices.push_back(originalIndex);

        for (int x : takeNext.indices)
            take.indices.push_back(x);

        // The final answer must be sorted by original index
        sort(take.indices.begin(), take.indices.end());


        // -------------------------
        // COMPARE
        // -------------------------

        if (take.score > skip.score) {
            return memo[i][k] = take;
        }

        if (take.score < skip.score) {
            return memo[i][k] = skip;
        }

        // Equal score
        if (take.indices < skip.indices) {
            return memo[i][k] = take;
        }

        return memo[i][k] = skip;
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        a.clear();

        // Add original index
        for (int i = 0; i < n; i++) {

            a.push_back({
                intervals[i][0],   // start
                intervals[i][1],   // end
                intervals[i][2],   // weight
                i                   // original index
            });
        }

        // Sort by start
        sort(a.begin(), a.end());

        // memo[i][k]
        memo.assign(n, vector<State>(5));

        // -1 means not calculated
        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= 4; k++) {
                memo[i][k].score = -1;
            }
        }

        return solve(0, 4).indices;
    }
};