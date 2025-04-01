#include<iostream>	
using namespace std;

char arr[101][101];
char text[10] = { '.', 'O', '|', '-', '/', '\\', '^', '<', 'v', '>' };
char stumbleText[10] = { '.', 'O', '-', '|', '\\', '/', '<', 'v', '>', '^' };

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 10; k++) {
				if (arr[i][j] == text[k]) {
					arr[i][j] = stumbleText[k];
					break;
				}
			}
		}
	}
	
	for (int i = M-1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			cout << arr[j][i];
		}
		cout << '\n';
	}
	
	return 0;
}