#include<iostream>
using namespace std;
void main()
{
	int V, nv, ne, data[50][50], visited[50], costs[50], k = 0, extra = 0;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			data[i][j] = 9999;
		}
		visited[i] = costs[i] = 9999;
	}
	cout << "Enter no of vertices" << endl;
	cin >> nv;
	cout << "Enter no of edges" << endl;
	cin >> ne;
	cout << "Enter edge pairs with costs" << endl;
	for (int i = 0; i < ne; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		data[x][y] = data[y][x] = cost;
	}
	cout << "Enter Initial vertex" << endl;
	cin >> V; int first = V;
	visited[V] = 1;
	while (k < nv)
	{
		int min = 9999, flag = 0;
		for (int i = 0; i <= nv; i++)
		{
			if (data[V][i] != 9999 && visited[i] != 1)
			{
				if(costs[i]>(extra+data[V][i]))
					costs[i] = extra+data[V][i];
			}
		}
		for (int i = 0; i <= nv; i++)
		{
			if (min > costs[i])
			{
				min = costs[i]; V = i; extra = costs[i]; flag = 1;
			}
		}
		if (flag == 1)
		{
			cout << first << "-----" << V << "-----" << min << endl;
			visited[V] = 1; costs[V] = 9999;
		}
		k++;
	}
}