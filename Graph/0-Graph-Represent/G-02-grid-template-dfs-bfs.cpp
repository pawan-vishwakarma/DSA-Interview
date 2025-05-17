// dfs recursive

void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int rows = grid.size(), cols = grid[0].size();
    visited[x][y] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
            grid[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, grid, visited);
        }
    }
}

// bfs iterative
#include <queue>

void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                grid[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

