#include<iostream>
using namespace std;
 void main()
{
	int data[50][50], visited[50], V, nv, ne, list[20], top = 0;
	for (int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			data[i][j] = 99999;
		}
		visited[i] = 0;
	}
	cout << "Enter no of  vertices" << endl;
	cin >> nv;
	cout << "Enter no of edges" << endl;
	cin >> ne;
	cout << "Enter edge pairs with costs" << endl;
	for (int i = 0; i < ne; i++)
	{
		int x, y, cost;
		cin >> x;
		cin >> y;
		cin >> cost;
		data[x][y] = cost; data[y][x] = cost;
	}
	cout << "Enter starting vertex to visit" << endl;
	cin >> V;
	cout << "Path is " << V;
	visited[V] = 1;
	list[top] = V; top++;
	int k = 1;
	while (k < nv)
	{
		int min = 99999, vertex = 0, flag = 10;
		for (int i = 1; i <= nv; i++)
		{
			if (data[V][i] < min && visited[i]!=1)
			{
				min = data[V][i];
				vertex = i;
				flag = 1;
			}
		}
		if (vertex == 0)
		{
			V = list[top]; top--;
			flag = 0;
		}
		if (flag == 1)
		{
			V = vertex;
			cout << "----" << V;
			visited[V] = 1;
			list[top] = V; top++;
			k++;
		}
	}
}