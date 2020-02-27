#include<iostream>
using namespace std;
class Hash
{
public:
	int flag = -1, size;
	Hash(int n)
	{
		size = n;
	}
	int* hash = new int[size];
	void set();
	void insert(int);
	void del(int);
	int search(int);
	void display();
};
void Hash::set()
{
	for (int i = 0; i < size; i++)
		hash[i] = -1;
}
void Hash::insert(int key)
{
	int pos = key % size, count = 0;
	while (count < size)
	{
		if (hash[pos] == -1)
		{
			hash[pos] = key;
			break;
		}
		else
		{
			pos = (pos + 1) % size;
		}
		count++;
	}
	if (count >= size)
		cout << "Hash table is full Insertion not possible" << endl;
}
int Hash::search(int key)
{
	int pos = key % size, count = 0;
	while (count < size)
	{
		if (hash[pos] == key)
		{
			return pos;
		}
		else
		{
			pos = (pos + 1) % size;
		}
		count++;
	}
	return 100;
}
void Hash::del(int key)
{
	int flag = search(key);
	if (flag != 100)
	{
		hash[flag] = -1;
		cout << "Element deleted" << endl;
	}
	else
		cout << "Element not found deletion not possible" << endl;
}
void Hash::display()
{
	cout << "Index " << "Value" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << i << "   " << hash[i] << endl;
	}
}
void main()
{
	int n, end = 0;
	cout << "Enter Hash table size you needed" << endl;
	cin >> n;
	Hash ht(n);
	ht.set();
	cout << "Enter what do you want to do" << endl;
	while (end == 0)
	{
		int choose;
		cout << "1.Insert\t2.Display\t3.Search\t4.Delete\t5.Exit" << endl; cin >> choose;
		switch (choose)
		{
		case 1: {
			int x;
			cout << "Enter value to insert" << endl; cin >> x;
			ht.insert(x);
			break;
		}
		case 2: {
			ht.display();
			break; }
		case 3: {
			int ser;
			cout << "Enter value to search" << endl;
			cin >> ser;
			int f = ht.search(ser);
			if (f != 100)
				cout << "Element " << ser << " found" << endl;
			else
				cout << "Element " << ser << " not found" << endl;
			break; }
		case 4: {
			int del;
			cout << "Enter value to delete" << endl;
			cin >> del;
			ht.del(del);
			break; }
		case 5: {
			end = 1;
			break; }
		default:
			cout << "Invalid input try again" << endl;
		}
	}
}