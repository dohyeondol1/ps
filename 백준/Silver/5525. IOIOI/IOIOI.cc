#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int N, M;
	cin >> N >> M;
	
	string S;
	cin >> S;
	
	int answer = 0, OIcount = 0;
	for(int i = 0; i < M; i++) {
	    if(S[i] == 'O') continue;
	    else {
	        while(S[i+1] == 'O' && S[i+2] == 'I') {
	            OIcount++;
	            if(OIcount == N) {
	                answer++;
	                OIcount--;
	            }
	            i += 2;
	        }
	    }
	    OIcount = 0;
	}
	
	cout << answer << '\n';
	
	return 0;
}