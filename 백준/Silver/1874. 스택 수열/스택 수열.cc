#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dat[100001];
    string pm;
    int top = -1,seq = 1,num;
    int length;
    cin >> length;
    for(int i = 0;i < length;i++){
        cin >> num;
        while(seq <= num){
            dat[++top] = seq++;
            pm += '+';
        }
        pm += '-';
        while(dat[top--] != num){
            if(top < 0) {
            cout << "NO";
            return 0;
        }
        pm += '-';
        }
    }
    for(int i = 0;i < pm.length();i++)
        cout << pm[i] << "\n";
}