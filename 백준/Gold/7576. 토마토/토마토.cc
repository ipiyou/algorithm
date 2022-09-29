#include <iostream>
#include <queue>

using namespace std;

int board[1002][1002];
int visit[1002][1002];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int,int> > Q;
  cin >> n >> m;
  for(int i = 0; i < m; i++)
    for(int j = 0;j < n;j++){
      cin >> board[i][j];
      if(board[i][j] == 1) {
        Q.push({i,j});
        }
      if(board[i][j] == 0){
        visit[i][j] = -1;
      }
    }
  
//방문해야될 경우를 -1  
   while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      //보드칸을 넘을 때
      if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      //이미 방문헀을 경우
      if(visit[nx][ny] >= 0) continue;

      visit[nx][ny] = visit[cur.first][cur.second]+1;
      Q.push({nx,ny});
    }
  }
  int MAX = 0;
  for(int i = 0;i < m;i++){
    for(int j = 0;j < n;j++){
      if(visit[i][j] == -1){
        cout << -1;
        return 0;
      }
      MAX = max(MAX,visit[i][j]);
    }
  }
  cout << MAX;
}