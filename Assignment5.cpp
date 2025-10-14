#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Enter number of shops: ";
    cin >> N;

    int S[100], E[100];
    cout << "Enter start times: ";
    for (int i = 0; i < N; i++) cin >> S[i];

    cout << "Enter end times: ";
    for (int i = 0; i < N; i++) cin >> E[i];

    cout << "Enter number of people: ";
    cin >> K;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (E[i] > E[j]) {
                swap(E[i], E[j]);
                swap(S[i], S[j]);
            }
        }
    }

    
    int personEndTime[100] = {0};
    int count = 0;

  
    for (int i = 0; i < N; i++) {
        for (int p = 0; p < K; p++) {
            if (personEndTime[p] <= S[i]) {
                personEndTime[p] = E[i];
                count++;
                break; 
            }
        }
    }

    cout << "Maximum shops visited: " << count << endl;
    return 0;
}
