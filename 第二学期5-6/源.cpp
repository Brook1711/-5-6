#include<iostream>
#include<algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

void change(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void quickSort(int* a, int l, int u)
{
	int i, m;
	if (l >= u) return;
	m = l;
	for (i = l + 1; i <= u; i++)
		if (a[i] > a[l])
			change(a[++m], a[i]);
	change(a[l], a[m]);
	quickSort(a, l, m - 1);
	quickSort(a, m + 1, u);
}


int main()
{
	int sum;


	while (cin >> sum)
	{
		if (sum == 0)
		{
			break;
		}
		int win = 0;
		int fail = 0;


		if (sum == 0)
			break;
		int* yuan = new int[sum];
		int* wang = new int[sum];
		for (int i = 0; i < sum; i++)
		{
			cin >> yuan[i];
		}
		for (int i = 0; i < sum; i++)
		{
			cin >> wang[i];
		}
		quickSort(yuan, 0, sum - 1);
		quickSort(wang, 0, sum - 1);

		int ib = 0, jb = 0;
		int ie = sum - 1, je = sum - 1;

		while (ib <= ie)
		{
			if (yuan[ib] > wang[jb])
			{
				win++;
				ib++;
				jb++;
			}
			else if (yuan[ib] < wang[jb])
			{
				fail++;
				ie--;
				jb++;
			}
			else
			{
				if (yuan[ie] > wang[je])
				{
					win++;
					ie--;
					je--;
				}
				else if (yuan[ie] <= wang[je])
				{
					fail++;
					ie--;
					jb++;
				}
			}
		}
		if (win > fail)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		delete[] yuan;
		delete[] wang;
	}
	//system("pause");
	return 0;
}