#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};
class Heap
{
public:
	Node* head = NULL;Node* preNode = NULL;
	int count, n, last;
	Heap()
	{
		count = 0, n = 0, last = 0;
	}
	void heapify(int);
	void insert(int);
	void display();
	void del();
	void find(int);
};
void Heap::heapify(int flag)
{
	int itr = last = (count / 2);
	for(int i=0;i<count && (itr*2<=count || itr*2+1<=count);i++)
	{
		if (itr == 0)
			itr=last;
		int par, lchild, rchild;
		Node* parNode = head; Node* leftchild = head; Node* rightchild = head;
		for (int i = 1; i < itr; i++)
			parNode = parNode->next;
		for (int i = 1; i < itr * 2; i++)
			leftchild = leftchild->next;
		for (int i = 1; i < (itr * 2 + 1); i++)
		{
			if ((itr * 2 + 1) > count)
				break;
			rchild = rightchild->data;
			rightchild = rightchild->next;
		}
		par = parNode->data;
		lchild = leftchild->data;
		if (rightchild != head)
			rchild = rightchild->data;
		else
			rchild = -1;
		if (par > lchild&& par > rchild)
			itr--;
		else if (par < lchild && lchild>rchild)	{
			parNode->data = lchild;
			leftchild->data = par;
			int temp = par; par = lchild; lchild = temp;
			if (flag == 1)
				itr = itr * 2;
			else
				itr--;
		}
		else if (par < rchild && rchild>lchild)	{
			parNode->data = rchild;
			rightchild->data = par;
			int temp = par; par = rchild; rchild = par;
			if (flag == 1)
				itr = itr * 2 + 1;
			else
				itr--;
		}
	}
}
void Heap::insert(int x)
{
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	if (count == 0)	{
		head = newNode;
		preNode = head;
	}
	else	{
		preNode->next = newNode;
		preNode = newNode;
	}
	count++;
	heapify(0);
}
void Heap::del()
{
	if (count == 1)	{
		head = NULL;
	}
	else if (count > 1)	{
		Node* delNode = head;
		for (int i = 1; i < count - 1; i++)
			delNode = delNode->next;
		int temp = head->data;
		head->data = (delNode->next)->data;
		(delNode->next)->data = temp;
		delete (delNode->next);
		delNode->next = NULL;
		count--;
		heapify(1);
	}
	else
		cout << "No elements to delete" << endl;
}
void Heap::find(int key)
{
	int pos=1,flag=0; Node* findNode = head; Node* parNode = head;
	for (int i = 0; i < count; i++)
	{
		if (findNode->data == key)
		{
			flag = 1;
			break;
		}
		findNode = findNode->next;
		pos++;
	}
	if (flag == 1)	{
		for (int i = 1; i < (pos / 2); i++)
			parNode = parNode->next;
		if(key==parNode->data)
			cout << key << " is root node " <<  endl;
		else
			cout << "The parent of element " << key << " is " << parNode->data << endl;
		cout << "Position of element " << key << " is " << pos << endl;
	}
	else
		cout << "Entered element not found" << endl;
}
void Heap::display()
{
	Node* dispNode = head;
	while (dispNode != NULL)
	{
		cout << dispNode->data << " ";
		dispNode = dispNode->next;
	}
	cout << endl;
}
void main()
{
	int x, choose, key, end = 1;
	Heap h;
	cout << "Enter no of elements" << endl;
	cin >> h.n;
	cout << "Enter elements" << endl;
	for (int i = 0; i < h.n; i++)
	{
		cin >> x;
		h.insert(x);
	}
	while (end)
	{
		cout << "Enter what do you want to do" << endl;
		cout << "1.Insert\t2.Display\t3.Delete\t4.Find\t5.Exit" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Enter element to insert" << endl;
			cin >> key;
			h.insert(key);
			break;
		case 2:
			cout << "Elements are" << endl;
			h.display();
			break;
		case 3:
			h.del();
			break;
		case 4:
			cout << "Enter element to find details" << endl;
			cin >> key;
			h.find(key);
			break;
		case 5:
			end = 0; break;
		default:
			cout << "Invalid input" << endl;
		}
	}
}