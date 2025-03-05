#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    int count = 0;
    cin >> N;
    
    vector<int> H(N);
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }
    
    for(int i = 0; i < N; i++){
        count++;
        if(i == N-1){
            break;   
        }
        else if(H[i] > H[i+1]){
            count--;
        }
    }

    cout << count;
    
    return 0;
}