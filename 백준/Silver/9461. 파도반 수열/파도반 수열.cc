#include <iostream>

using namespace std;

long long dp[101] = {};

int main(){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    int num,cnt;
    cin >> cnt;
    for(int i = 0;i < cnt;i++){
        cin >> num;
        for(int i = 6;i <= num;i++){
            dp[i] = dp[i-1] + dp[i-5];
        }
        cout << dp[num] << "\n";
    }
    return 0;
}