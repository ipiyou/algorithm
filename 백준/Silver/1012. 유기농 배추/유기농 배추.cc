#include <iostream>
#include <queue>

using namespace std;

int main(){
    int T,M,N,K;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> Q;
    cin >> T;
    while(T--){
        int X,Y;
        int count = 0;
        cin >> N >> M >> K;
        int visit[201][201] = {};
        while(K--){
           cin >> X >> Y;
           visit[X][Y] = 1;
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(visit[i][j] == 1) {
                    Q.push({i, j});
                    while(!Q.empty()){
                        int X = Q.front().first;
                        int Y = Q.front().second;

                        Q.pop();
                        for(int dir=0;dir<4;dir++){
                            int DX = X + dx[dir];
                            int DY = Y + dy[dir];
                            if(DX >= N || DX < 0 || DY >= M || DY < 0) continue;
                            if(visit[DX][DY] != 1) continue;
                            Q.push({DX,DY});
                            visit[DX][DY] = 0;
                        }
                    }
                    count++;
                }
            }
        }

        cout << count<< "\n";
    }
}