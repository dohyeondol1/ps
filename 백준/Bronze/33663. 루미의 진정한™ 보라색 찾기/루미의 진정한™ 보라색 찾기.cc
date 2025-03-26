#include <iostream>
using namespace std;

int main() {
	int hLow, hHigh, sLow, sHigh, vLow, vHigh, R, G, B;
	cin >> hLow >> hHigh >> sLow >> sHigh >> vLow >> vHigh >> R >> G >> B;

	double M = max(max(R, G), B), m = min(min(R, G), B);
	double V = M, S = 255*(V-m)/V, H;
	if(V == R) H = 60 * (G-B) / (V-m);
	if(V == G) H = 120 + 60 * (B-R) / (V-m);
	if(V == B) H = 240 + 60 * (R-G) / (V-m);
	if(H < 0) H += 360;

	if(H >= hLow && H <= hHigh && S >= sLow && S <= sHigh && V >= vLow && V <= vHigh)
	    cout << "Lumi will like it." << '\n';
	else cout << "Lumi will not like it." << '\n';
    
}