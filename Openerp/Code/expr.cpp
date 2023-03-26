#include <iostream>
using namespace std;

#define MAX 31

int n, b;
int a[MAX];
int x[MAX];
int s = 0;
long long cnt = 0;

void solution()
{
	if (s == b)
		cnt++;
}

void TRY(int k)
{
	for (int v = 0; v <= 1; v++)
	{
		x[k] = v;
		if (v == 0)
			s += a[k];
		else
			s -= a[k];
		if (k == n)
			solution();
		else
			TRY(k + 1);
		if (v == 0)
			s -= a[k];
		else
			s += a[k];
	}
}

void input()
{
	cin >> n >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
}

int main()
{
	input();
	s = a[1];
	TRY(2);
	cout << cnt;
}
