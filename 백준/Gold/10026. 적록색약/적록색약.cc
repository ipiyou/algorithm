#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N,sum = 0,sum2 = 0;
    int visit[101][101] = {};
    int visit2[101][101] = {};
    string RGB[101] = {};
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> Q;
    queue<pair<int,int>> Q2;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> RGB[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j]){
                Q.push({i,j});
                while(!Q.empty()){
                    int curX = Q.front().first;
                    int curY = Q.front().second;
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int Dx = curX + dx[dir];
                        int Dy = curY + dy[dir];
                        if(Dx < 0 || Dx >= N || Dy < 0 || Dy >= N) continue;
                        if(RGB[curX][curY] != RGB[Dx][Dy]) continue;
                        if(visit[Dx][Dy]) continue;
                        visit[Dx][Dy] = 1;
                        Q.push({Dx,Dy});
                    }
                }
                sum++;
            }
            if(!visit2[i][j]){
                Q2.push({i,j});
                while(!Q2.empty()){
                    int curX = Q2.front().first;
                    int curY = Q2.front().second;
                    Q2.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int Dx = curX + dx[dir];
                        int Dy = curY + dy[dir];
                        int Funum = 0,Curnum = 0;
                        if(Dx < 0 || Dx >= N || Dy < 0 || Dy >= N) continue;
                        if(visit2[Dx][Dy]) continue;
                        if(RGB[Dx][Dy] == 'G' || RGB[Dx][Dy] == 'R') Funum = 1;
                        if(RGB[curX][curY] == 'G' || RGB[curX][curY] == 'R') Curnum = 1;
                        if(Funum != Curnum) continue;
                        visit2[Dx][Dy] = 1;
                        Q2.push({Dx,Dy});
                    }
                }
                sum2++;
            }
        }
    }
    cout << sum << '\n';
    cout << sum2 << '\n';
}