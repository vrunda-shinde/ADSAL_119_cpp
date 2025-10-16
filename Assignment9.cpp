#include <iostream>
using namespace std;

int main() {
    int N, sum;
    cout << "Enter number of coins: ";
    cin >> N;

    int coins[100]; 
    cout << "Enter coin denominations: ";
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    int dp[1001] = {0}; 
    dp[0] = 1; 


    for (int i = 0; i < N; i++) {      
        for (int j = coins[i]; j <= sum; j++) {  
            dp[j] += dp[j - coins[i]]; 
        }
    }

    cout << "Number of ways to make sum: " << dp[sum] << endl;

    return 0;
}
