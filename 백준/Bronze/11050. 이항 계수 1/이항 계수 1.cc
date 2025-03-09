#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int N_factorial = N;
    int K_factorial = K;
    int N_minus_K_factorial = N-K;
    int binomial_coefficient = 0;
    
    if(N == K || K == 0) {
        cout << 1;
        return 0;
    }
    
    for(int i = 1; i < N; i++) N_factorial *= i;
    for(int i = 1; i < K; i++) K_factorial *= i;
    for(int i = 1; i < (N-K); i++) N_minus_K_factorial *= i;
    
    binomial_coefficient = N_factorial / (N_minus_K_factorial * K_factorial);
    cout << binomial_coefficient;
    
    return 0;
}