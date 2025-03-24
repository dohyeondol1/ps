#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    queue<int> array;
    
    for(int i = 1; i <= N; i++) {
        array.push(i);
    }
    
    cout << "<";
    while(!array.empty()) {
        for(int i = 1; i <= K; i++) {
            if(i == K) {
                if(array.size() != 1) {
                    cout << array.front() << ", ";
                    array.pop();
                }
                else {
                    cout << array.front() << ">";
                    array.pop();
                }
            }
            else {
                array.push(array.front());
                array.pop();
            }
        }
    }
    
    return 0;
}