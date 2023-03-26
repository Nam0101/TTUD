#include <iostream>
using namespace std;

#define MAX 100000

int n, k, a[MAX], b[MAX + 1]; // b[i] = a[0] + a[1] + ... + a[i - 1]
int res = 0;

void input()
{
	cin >> n >> k;
	b[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i + 1] = b[i] + a[i];
	}
}

int main()
{
	input();
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			cout << "num:" << b[j + 1] - b[i] << " i " << i << " j " << j << endl;
			if (b[j + 1] - b[i] == k)
				res++;
		}
	}
	cout << res;
}
