#include <iostream>
#include <algorithm> 
using namespace std;
 
bool canFinish(int task[], int N, int D, int limit) {
    int days = 1;
    int currentWork = 0;

    for (int i = 0; i < N; i++) {
        if (currentWork + task[i] <= limit)
            currentWork += task[i];
        else {
            days++;
            currentWork = task[i];
        }
    }

    return days <= D;
}

int minWorkPerDay(int task[], int N, int D) {
    int low = task[0], high = 0;

   
    for (int i = 0; i < N; i++) {
        high += task[i];
        if (task[i] > low)
            low = task[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canFinish(task, N, D, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int N, D;
    cout << "Enter number of tasks: ";
    cin >> N;

    int task[100];
    cout << "Enter work for each task: ";
    for (int i = 0; i < N; i++) {
        cin >> task[i];
    }

    cout << "Enter number of days: ";
    cin >> D;

    int result = minWorkPerDay(task, N, D);
    cout << "Minimum work to be done per day: " << result << endl;

    return 0;
}
