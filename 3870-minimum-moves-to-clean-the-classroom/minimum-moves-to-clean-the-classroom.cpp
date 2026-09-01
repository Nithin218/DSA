class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;

        // Number each litter cell
        vector<vector<int>> id(m, vector<int>(n, -1));

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        // All litter is initially uncollected
        int fullMask = (1 << cnt) - 1;

        /*
            state = {row, col, currentEnergy, mask}

            mask:
            1 -> litter still needs to be collected
            0 -> litter already collected
        */

        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, fullMask});

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(energy + 1,
                                           vector<bool>(1 << cnt, false))));

        visited[sr][sc][energy][fullMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Cannot make another move
                if (e == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Moving costs 1 energy
                    int ne = e - 1;

                    // Collect litter
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {

                        int bit = id[nr][nc];

                        nmask &= ~(1 << bit);
                    }

                    // Recharge after entering R
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // New state
                    if (!visited[nr][nc][ne][nmask]) {

                        visited[nr][nc][ne][nmask] = true;

                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};