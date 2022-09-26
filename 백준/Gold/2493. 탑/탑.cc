#include <iostream>
#include <stack>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int,int>> tower;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;  
  tower.push({100000001, 0});
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;
    while (tower.top().X < height) 
    // 큰 값을 만나기 전 작은 값은 모두 현재 큰 값의 좌표를 따름
      tower.pop(); 
    cout << tower.top().Y << " "; 
    tower.push({height, i});      
  }
}