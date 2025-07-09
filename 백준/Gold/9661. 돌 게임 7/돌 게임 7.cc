#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if(N % 5 == 0 || N % 5 == 2)
        cout << "CY" << '\n';
    else
        cout << "SK" << '\n';

    return 0;
}