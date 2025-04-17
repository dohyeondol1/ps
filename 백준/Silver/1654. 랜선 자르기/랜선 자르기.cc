#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> cable, int targetCount) {
    long long sum = 0;
    for(int i = 0; i < cable.size(); i++)
        sum += cable[i];
    
    //만약 가정한 랜선 길이를 각 원소로 나누었을 때 값의 합이 targetCount 보다 작다면 가정 랜선길이를 줄이기
    long long left = 1, right = *max_element(cable.begin(), cable.end());
    long long temp = 0;
    while(left <= right) {
        long long mid = (left+right)/2;
        
        long long count = 0;
        for(int arr : cable)
            count += arr/mid;
        
        if(count >= targetCount) {
            temp = mid;
            left = mid+1;
        }
        else if(count < targetCount) right = mid-1;
        
    }
    
    return temp;
}

int main() {
	int K, N;
	cin >> K >> N;
	
	vector<int> cableLength(K);
	for(int i = 0; i < K; i++)
	    cin >> cableLength[i];

    int minCableLength = binarySearch(cableLength, N);
    
    cout << minCableLength << '\n';
	return 0;
}