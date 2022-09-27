#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> Q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int len,num;
  string order;
  cin >> len;
  while(len--){
    cin >> order;
    if(order == "push"){
      cin >> num;
      Q.push(num);
    }
    else if(order == "pop"){
      if(Q.empty()) cout << -1 << "\n";
      else {
        cout << Q.front() << "\n";
        Q.pop();
      }
    }
    else if(order == "size"){
      cout << Q.size() << "\n";
    }
    else if(order == "empty"){
      cout << Q.empty() << "\n";
    }
    else if(order == "front"){
      if(Q.empty()) cout << -1 << "\n";
      else cout << Q.front() << "\n"; 
    }
    else if(order == "back"){
      if(Q.empty()) cout << -1 << "\n";
      else cout << Q.back() << "\n";
    }
  }
}