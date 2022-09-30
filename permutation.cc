/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

const int MAXN = 15;
const int MAXS = 1 << MAXN;

int n, s;
int a[MAXN], lg2[MAXS];
bool sg[MAXS];

bool Check(int st)
{
	int z, x;
	cout << "in Check st: " << st << "lg2 index: " << lg2[x=(st&(-st))] << endl;
	z = a[lg2[x=(st&(-st))]];
	for (st -= x; st; st -= x)
		if (a[lg2[x=(st&(-st))]] <= z)  return false;
		else z = a[lg2[x]];
	return true;
}

bool Work()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	s = 1 << n;

	for (int k = 1, z, x; k < s; k ++)
	{
		cout << "k: " << k << " z: " << z << " x: " << x << endl;
		sg[k] = false;
		if (Check(k))
			continue;
		for (z = k; z > 0 && !sg[k]; z -= x)
		{
			x = (z & (-z));
			if (!sg[k-x])  sg[k] = true;
		}
	}

	return sg[s-1];
}

int main()
{

	for (int i = 0; i < MAXN; i ++)
		lg2[1<<i] = i;

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i ++)
		printf((Work()? "Alice\n": "Bob\n"));

	return 0;
}
