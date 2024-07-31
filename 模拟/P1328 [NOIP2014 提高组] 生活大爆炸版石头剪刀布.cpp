#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, na, nb;
int a[205] = { 0 }, b[205] = { 0 };
int a_score = 0, b_score = 0;

enum Result
{
	win,
	lose,
	deuce
};
Result mat[5][5] = { {deuce,lose,win,win,lose},
{win,deuce,lose,win,lose},
{lose,win,deuce,lose,win},
{lose,lose,win,deuce,win},
{win,win,lose,lose,deuce} };
int main()
{
	cin >> n >> na >> nb;
	for (int i = 0; i < na; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < nb; i++) {
		cin >> b[i];
	}
	int i = 0, j = 0;
	while (n)
	{
		switch (mat[a[i]][b[j]])
		{
		case win:
			a_score++;
			break;
		case lose:
			b_score++;
			break;
		case deuce:
			break;
		default:
			break;
		}
		i++;
		j++;
		i = i % na;
		j = j % nb;
		n--;
	}
	cout << a_score << " " << b_score;
	return 0;
}
