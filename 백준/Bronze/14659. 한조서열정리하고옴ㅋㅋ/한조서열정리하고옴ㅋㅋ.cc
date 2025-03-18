#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> peaks(N);
    for(int i = 0; i < N; i++){
        cin >> peaks[i];
    }
    
    vector<int> kill(N);
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N-i; j++) {
            if(peaks[i] > peaks[i+j]) kill[i]++;
            else break;
        }
    }
    
    sort(kill.begin(), kill.end(), greater<int>());
    
    cout << kill[0];
    
    return 0;
}