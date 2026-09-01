#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& arr, int N, int C, int minAllowedDis) {
    int cows = 1, lastStallPOS = arr[0];

    for(int i = 1; i < N; i++) {
        if(arr[i] - lastStallPOS >= minAllowedDis) {
            cows++;
            lastStallPOS = arr[i];
        }

        if(cows == C) {
            return true;
        }
    }

    return false;
}

int getDistance(vector<int>& arr, int N, int c) {
    sort(arr.begin(), arr.end());

    int st = 1;
    int end = arr[N-1] - arr[0];
    int ans = -1;

    while(st <= end) {
        int mid = st + (end - st) / 2;

        if(isPossible(arr, N, c, mid)) {
            ans = mid;
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int N = 5, C = 3;

    vector<int> arr = {1, 2, 8, 4, 9};

    cout << getDistance(arr, N, C) << endl;

    return 0;
}