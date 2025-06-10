#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    long long N;
    cin >> N;
    
    vector<long long> count(10, 0);
    long long digit = 1;
    long long start = 1, end = N;

    while(start <= end) {
        while(end%10 != 9 && start <= end) {
            long long num = end;
            while(num > 0) {
                count[num%10] += digit;
                num /= 10;
            }
            end--;
        }

        while(start%10 != 0 && start <= end) {
            long long num = start;
            while(num > 0) {
                count[num%10] += digit;
                num /= 10;
            }
            start++;
        }
        if(start > end) break;

        long long cnt = (end/10 - start/10 + 1);
        for(int i = 0; i < 10; ++i)
            count[i] += cnt * digit;

        start /= 10;
        end /= 10;
        digit *= 10;
    }

    for(int i = 0; i < 10; ++i) {
        cout << count[i];
        if(i < 9) cout << ' ';
    }
    
    return 0;
}