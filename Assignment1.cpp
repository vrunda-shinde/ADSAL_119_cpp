#include <iostream>
using namespace std;

int countZeros(int arr[], int n) {
    int low = 0, high = n - 1;
    int firstZeroIndex = n; // default if no zero is found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 0) {
            firstZeroIndex = mid;   // possible answer, look left for earlier 0
            high = mid - 1;
        } else {
            low = mid + 1;          // move right, all 1s so far
        }
    }

    return n - firstZeroIndex; // count of zeros
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n]; // variable-length array (VLA)

    cout << "Enter " << n << " elements (only 1s followed by 0s):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int zeroCount = countZeros(arr, n);
    cout << "Number of 0s: " << zeroCount << endl;

    return 0;
}
