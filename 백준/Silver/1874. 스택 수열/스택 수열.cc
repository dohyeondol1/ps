#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> array(N);
	stack<int> s;
	for(auto &arr : array)
	    cin >> arr;
	
	int num = 1;
	vector<char> answer;
	while(!array.empty()) {
	    if(!s.empty() && s.top() == array.front()) {
	        s.pop();
	        array.erase(array.begin());
	        answer.push_back('-');
	    }
	    else if(num <= N) {
	        s.push(num);
	        num++;
	        answer.push_back('+');
	    }
        else {
            cout << "NO" << '\n';
            return 0;
        }
	}

    for(auto &ans : answer)
        cout << ans << '\n';
    
	return 0;
}