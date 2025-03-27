#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    int goodWordCount = 0;
    
    for(int i = 0; i < N; i++) {
        string word;
        cin >> word;
        stack<char> stack;
        
        for(int j = 0; j < word.size(); j++) {
            if(stack.empty()) stack.push(word[j]);
            else if(word[j] != stack.top()) stack.push(word[j]);
            else if(word[j] == stack.top()) stack.pop();
        }
        if(stack.empty()) goodWordCount++;
    }
    cout << goodWordCount << '\n';
	
	return 0;
}