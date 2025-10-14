#include <iostream>
using namespace std;

int maxProfit(int arr[], int n) {
    int maxSoFar = arr[n - 1];  
    int profit = 0;

  
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < maxSoFar) {
          
            profit += (maxSoFar - arr[i]);
        } else {
           
            maxSoFar = arr[i];
        }
    }
    return profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int arr[1000];
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum Profit: " << maxProfit(arr, n) << endl;
    return 0;
}
