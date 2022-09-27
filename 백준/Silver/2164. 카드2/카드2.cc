#include <iostream>
#include <queue>

using namespace std;

int main() {

  long len;
  cin >> len;
  queue<long> Q;
  long front = -1,back = -1;

  for(long i = 1;i <= len;i++) Q.push(i);
  while(Q.size() != 1){
    Q.pop();
    Q.push(Q.front());
    Q.pop();
  }
  cout << Q.front(); 
}