#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> num(N);
    int sum = 0;
    vector<int> count(8001, 0);

    for(int i = 0; i < N; i++) {
        cin >> num[i];
        sum += num[i];
        count[num[i] + 4000]++;
    }

    sort(num.begin(), num.end());

    int arithmeticMean = round((double)sum / N);

    int median = num[N / 2];

    int maxCount = 0;
    int mode = 0;
    bool second = false;

    for(int i = 0; i <= 8000; i++) {
        if(count[i] > maxCount) {
            maxCount = count[i];
            mode = i - 4000;
            second = false;
        } else if(count[i] == maxCount && !second) {
            mode = i - 4000;
            second = true;
        }
    }

    int range = num.back() - num.front();

    cout << arithmeticMean << "\n";
    cout << median << "\n";
    cout << mode << "\n";
    cout << range << "\n";

    return 0;
}
