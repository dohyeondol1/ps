#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int x[3], y[3];
	for(int i = 0; i < 3; i++)
	    cin >> x[i] >> y[i];
	
	int answerX, answerY; 
	if(x[0] == x[1]) answerX = x[2];
	if(x[0] == x[2]) answerX = x[1];
	if(x[1] == x[2]) answerX = x[0];
	if(y[0] == y[1]) answerY = y[2];
	if(y[0] == y[2]) answerY = y[1];
	if(y[1] == y[2]) answerY = y[0];
	
	cout << answerX << ' ' << answerY << '\n';
	
	return 0;
}