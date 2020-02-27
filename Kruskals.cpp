#include<iostream>
using namespace std;
void main()
{
	int data[50][50], V, nv, ne, check[50], x, y;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			data[i][j] = 99999;
		}
		check[i] = 0;
	}
	cout << "Enter no of vertices" << endl;
	cin >> nv;
	cout << "Enter no of edges" << endl;
	cin >> ne;
	cout << "Enter edge pairs with costs" << endl;
	for (int i = 0; i < ne; i++)
	{
		int x, y, cost;
		cin >> x; cin >> y; cin >> cost;
		data[x][y] = cost;data[y][x] = cost;
	}
	int k = 1;
	while (k < nv)
	{
		int min = 99999, lv = 0, rv = 0, flag = 10;
		for (int i = 1; i <= nv; i++)
		{
			for (int j = 1; j <= nv; j++)
			{
				if (data[i][j] < min)
				{
					min = data[i][j];
					lv =x= i; rv =y= j;
				}
			}
		}
		while(check[lv])
		{
			lv = check[lv];
		}
		while (check[rv])
		{
			rv = check[rv];
		}
		if (lv != rv)
		{
			cout << x << "----" << y;
			check[x] = y;
			k++;
		}
		data[x][y] = 99999; data[y][x] = 99999;
	}
}