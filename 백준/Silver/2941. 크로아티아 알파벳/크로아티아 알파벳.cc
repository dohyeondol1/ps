#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> croatia = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

    string input;
    cin >> input;
    for(int i = 0; i < croatia.size(); i++) {
        while(1) {
            int index = input.find(croatia[i]);
            if(index == string::npos) break;
            input.replace(index, croatia[i].length(), "+");
        }
    }
    
    cout << input.length() << '\n';

	return 0;
}