#include <iostream>
#include <deque>

using namespace std;

int main() {

  int len,num,sum = 0,index;
  cin >> len;
  deque<long> D;
  for(int i = 1;i <= len;i++) D.push_back(i);
  cin >> len;
  while(len--){
    cin >> num;
    for(int i = 0;i < D.size();i++){
      if(num == D[i]) {
        index = i;
        break;
      }
    }
    while(D.front() != num){
      if(index < D.size() - index){
        D.push_back(D.front());
        D.pop_front();
      } else {
        D.push_front(D.back());
        D.pop_back();
      }
      sum++;
    }
    D.pop_front();
  }
  cout << sum;
}