#include <iostream>
#include <queue>

using namespace std;

int board[501][501];
bool visit[501][501];
int m,n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i =0;i < n;i++)
    for(int j = 0;j < m;j++)
      cin >> board[i][j];

  int mx = 0;
  int num = 0;
  for(int i =0;i < n;i++){
    for(int j = 0;j < m;j++){
      if(board[i][j] == 0 || visit[i][j]) continue;
      num++;
      queue<pair<int,int>> Q;
      visit[i][j] = 1;
      Q.push({i,j});
      int area  = 0;
      while(!Q.empty()){
        area++;
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir < 4;dir++){
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];
          if(nx < 0 || nx >= n || ny < 0|| ny >= m) continue;
          if(visit[nx][ny]||board[nx][ny] != 1) continue;
          visit[nx][ny] = 1;
          Q.push({nx,ny});
        }
      }
       mx = max(mx, area);
    }
  }
  cout << num << '\n' << mx;
}