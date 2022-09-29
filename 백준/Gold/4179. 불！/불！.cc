#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string board[1002];
    int dist1[1002][1002]; // 불의 전파 시간
    int dist2[1002][1002]; // 지훈이의 이동 시간
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }
    for (int i = 0; i < n; i++)
        cin >> board[i];
    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'F')
            {
                Q1.push(make_pair(i, j));
                dist1[i][j] = 0;
            }
            if (board[i][j] == 'J')
            {
                Q2.push(make_pair(i, j));
                dist2[i][j] = 0;
            }
        }
    }
    // 불에 대한 BFS
    while (!Q1.empty())
    {
        int x = Q1.front().first;
        int y = Q1.front().second;
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            dist1[nx][ny] = dist1[x][y] + 1;
            Q1.push(make_pair(nx, ny));
        }
    }

    // 지훈이에 대한 BFS
    while (!Q2.empty())
    {
        int x = Q2.front().first;
        int y = Q2.front().second;
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            { // 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 됨.
                cout << dist2[x][y] + 1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[x][y] + 1)
                continue; // 불의 전파 시간을 조건에 추가
            dist2[nx][ny] = dist2[x][y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}