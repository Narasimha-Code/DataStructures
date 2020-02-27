#include<iostream>
using namespace std;
class Node
{
public:
	Node* left = NULL;
	int value=-1;
	Node* right=NULL;
};
class HuffMann
{
public:
	int primary_data[20], duplicate_data[20], n, next_pos, size=0;
	char keys[20];
	Node* data[20];
	HuffMann()
	{
		for (int i = 0; i < 20; i++)
			primary_data[i] = duplicate_data[i] = 9999;
	}
	void huffmann();
	int minimum();
};
int HuffMann::minimum()
{
	int min = 9999, pos = -1;
	for (int i = 0; i <= next_pos; i++)
	{
		if (min > duplicate_data[i])
		{
			min = duplicate_data[i]; pos = i;
		}
	}
	duplicate_data[pos] = 9999;
	return min;
}
void HuffMann::huffmann()
{
	int k = 0;
	while (k < n)
	{
		int m1 = minimum(), m2 = minimum();
		if (m1 != 9999 && m2 != 9999)
		{
			Node* sumNode = new Node; Node* leftNode = new Node; Node* rightNode = new Node;
			leftNode->value = m1; rightNode->value = m2;
			sumNode->value = (m1 + m2); sumNode->left = leftNode; sumNode->right = rightNode;
			data[k] = sumNode; size++;
			next_pos++;
			duplicate_data[next_pos] = (m1 + m2);
		}
		k++;
	}
	k = 0;
	cout << "Keys\tValues\t\tCode" << endl;
	while (k < n)
	{
		int arr[20], j = 0, x = primary_data[k], first = x;
		for (int i = 0; i < size && data[i]->value!=-1; i++)
		{
			if ((data[i]->left)->value==(data[i]->right)->value && (data[i]->right)->value==first)	{
				x = data[i]->value; arr[j] = 1; j++;
			}
			else if ((data[i]->left)->value == x)	{
				x = data[i]->value; arr[j] = 0; j++;
			}
			else if ((data[i]->right)->value == x)	{
				x = data[i]->value; arr[j] = 1; j++;
			}
		}
		cout << keys[k] << "\t" << primary_data[k] << "\t\t";
		for (int i = j-1 ; i >= 0; i--)
			cout << arr[i];
		cout << endl;k++;
	}
}
void main()
{
	HuffMann hf;
	cout << "Enter no of elements" << endl;
	cin >> hf.n;
	cout << "Enter Keys and values" << endl;
	for (int i = 0; i < hf.n; i++)
	{
		cin >> hf.keys[i] >> hf.primary_data[i];
		hf.duplicate_data[i] = hf.primary_data[i];
		hf.next_pos = i;
	}
	hf.huffmann();
}