#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	//srand(46);
	srand(time(NULL));
	const int N = 4, M = 3;
	int arr[N][M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = rand() % 10 + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	int ci = 0, cj = 0, norep = N * M;
	for (int i = ci; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == ci && j <= cj) continue;
			if (arr[i][j] == arr[ci][cj]) {
				cout << "ci=" << ci << ".cj=" << cj << ".arr[ci][cj]=" << arr[ci][cj] << ".\ti=" << i << ".j=" << j << ".arr[i][j]=" << arr[i][j] << ".\n";
				--norep;
				if (cj + 2 <= M) cj++;
				else {
					ci++;
					cj = 0;
				}
				i = ci;
				j = cj;
			}
			else if ((i + 1 >= N) && (j + 1 >= M)) {
				if (cj + 2 <= M) cj++;
				else {
					ci++;
					cj = 0;
				}
				i = ci;
				j = cj;
			}
		}
	}
	cout << norep << "\n";

	system("pause");
	return 0;
}