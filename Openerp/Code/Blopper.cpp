#include <iostream>
using namespace std;

int n, s;
int l, r;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> s;
		r = n * (n + 1) / 2;
		l = 2 - r;
		cout << "l = " << l << endl;
		cout << "r = " << r << endl;
		if (l <= s && s <= r && (l + 4 == s || l + 4 < s && (s - l) % 2 == 0 || s + 4 == r || s + 4 < r && (r - s) % 2 == 0))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}
