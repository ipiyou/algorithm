#include <iostream>
#include <stack>
using namespace std;

int N;
stack<long long> tower;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;  
  long long int sum = 0;
  tower.push(1000000001);
  for (int i = 1; i <= N; i++) {
    long long int height;
    cin >> height;
    while (tower.top() <= height)
        tower.pop();
    sum += tower.size() - 1;
    // 스택에 남은 것은 height와 비교해 옥상을 확인 할 수 있다
    tower.push(height);
  }
  cout << sum; 
}