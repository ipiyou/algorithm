#include <iostream>
#include <queue>

using namespace std;

string board[102];
int visit[102][102];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> board[i];
  for(int i = 0; i < n; i++) fill(visit[i],visit[i]+m,-1);
  queue<pair<int,int> > Q;
  Q.push({0,0});
  visit[0][0] = 0;
   while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(visit[nx][ny] >= 0 || board[nx][ny] != '1') continue;
      visit[nx][ny] = visit[cur.first][cur.second]+1;
      Q.push({nx,ny});
    }
  }
  cout << visit[n-1][m-1]+1;
}