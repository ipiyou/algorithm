#include <iostream>
#include <deque>

using namespace std;

int main() {

  long len,num;
  cin >> len;
  deque<long> D;
  string order;
  while(len--){
    cin >> order;
    if(order == "push_front"){
      cin >> num;
      D.push_front(num);
    }
    else if(order == "push_back"){
      cin >> num;
      D.push_back(num);
    }
    else if(order == "pop_front"){
      if(D.empty()) cout << -1 << "\n";
      else {
        cout << D.front() << "\n";
        D.pop_front();
      }
    }
    else if(order == "pop_back"){
      if(D.empty()) cout << -1 << "\n";
      else {
          cout << D.back() << "\n";
          D.pop_back();
        }
    }
    else if(order == "size") cout << D.size() << "\n";
    else if(order == "empty") cout << D.empty() << "\n";
    else if(order == "front"){
      if(D.empty()) cout << -1 << "\n";
      else cout << D.front() << "\n";
    }
    else if(order == "back"){
      if(D.empty()) cout << -1 << "\n";
      else cout << D.back() << "\n";
    }
  }
}