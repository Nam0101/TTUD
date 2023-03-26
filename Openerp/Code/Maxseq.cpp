#include <iostream>
using namespace std;

#define MAX 100000

int main()
{
	int n, m = -9999;
	int a[MAX], b[MAX];
	cin >> n;
	b[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (m < a[i])
			m = a[i];
		b[i + 1] = b[i] + a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int t = b[j + 1] - b[i];
			if (m < t)
				m = t;
		}
	}
	cout << m;
}
