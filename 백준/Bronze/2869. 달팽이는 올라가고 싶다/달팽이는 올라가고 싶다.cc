#include <iostream>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;
    int day_count = (V-A) / (A-B);
    
    if ((V - A) % (A - B) == 0){
        day_count += 1;
    }
	else {
	    day_count += 2;
	}
	
	cout << day_count;
}