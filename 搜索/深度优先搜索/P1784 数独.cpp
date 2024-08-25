#include <iostream>

using namespace std;
int mat[9][9] = { 0 };
bool RowExist[9][10] = { 0 };
bool ColExist[9][10] = { 0 };

bool CheckChar(int row, int col, int val) {

	if (RowExist[row][val]) {
		return false;
	}
	if (ColExist[col][val]) {
		return false;
	}

	int lrow = (row / 3) * 3;
	int lcol = (col / 3) * 3;

	for (int i = lrow; i < lrow + 3; i++) {
		for (int j = lcol; j < lcol + 3; j++) {
			if (mat[i][j] == val) {
				return false;
			}
		}
	}
	return true;
}

bool MatSearch() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (mat[i][j] == 0) {
				for (int k = 1; k <= 9; k++) {
					if (CheckChar(i, j, k)) {
						mat[i][j] = k;
						RowExist[i][k] = true;
						ColExist[j][k] = true;
						bool res = MatSearch();
						if (res) {
							return true;
						}
						else {
							mat[i][j] = 0;
							RowExist[i][k] = false;
							ColExist[j][k] = false;
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mat[i][j];
			RowExist[i][mat[i][j]] = true;
			ColExist[j][mat[i][j]] = true;
		}
	}
	MatSearch();
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
