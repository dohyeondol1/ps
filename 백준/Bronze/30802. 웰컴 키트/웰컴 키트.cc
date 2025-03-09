#include <iostream>
using namespace std;

int main()
{
    int N, T, P;
    int size[6];
    int count_tshirt_bundle = 0;
    cin >> N;
    for(int i = 0; i < 6; i++) {
        cin >> size[i];
    }
    cin >> T >> P;
    
    for(int i = 0; i < 6; i++) {
        if(size[i] == 0) continue;
        else if((size[i]/T) == 0) count_tshirt_bundle++;
        else if(size[i]%T == 0) count_tshirt_bundle += size[i]/T;
        else count_tshirt_bundle += (size[i]/T)+1;
    }
    
    cout << count_tshirt_bundle << '\n';
    cout << N/P << ' ' << N%P << '\n';
    
    return 0;
}