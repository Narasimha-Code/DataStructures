#include<iostream>
using namespace std;
class Node
{
public:
	Node* left=NULL;
	int data=-1;
	Node* right=NULL;
};
class BStree
{
public:
	int count=0;
	Node* head=NULL;
	void insert(int);
	Node* parent(int);
	Node* search(int);
	void del(int);
	void display(Node*);
};
void BStree::insert(int key)
{
	Node* moveNode = head;
	Node* newNode = new Node;
	newNode->data = key;
	if (count == 0)
		head = newNode;
	else
	{
		for (int i = 0; i < count; i++)
		{
			if (key < moveNode->data && moveNode->left != NULL)
				moveNode = moveNode->left;
			else if (key > moveNode->data&& moveNode->right != NULL)
				moveNode = moveNode->right;
			if (key < moveNode->data && moveNode->left == NULL)
				moveNode->left = newNode;
			else if (key > moveNode->data&& moveNode->right == NULL)
				moveNode->right = newNode;
		}
	}
	count++;
}
Node* BStree::parent(int key)
{
	Node* chiNode = search(key);
	Node* parNode = head;
	if (chiNode != NULL)
	{
		for (int i = 0; i < count; i++)
		{
			if (parNode->left == chiNode || parNode->right == chiNode)
				return parNode;
			else if (key < parNode->data)
				parNode = parNode->left;
			else if (key > parNode->data)
				parNode = parNode->right;
		}
	}
	else
		return NULL;
}
Node* BStree::search(int key)
{
	Node* serNode = head;
	for (int i = 0; i < count; i++)
	{
		if (serNode == NULL)
			return NULL;
		if (serNode->data == key)
			return serNode;
		else if (key < serNode->data)
			serNode = serNode->left;
		else if (key > serNode->data)
			serNode = serNode->right;
	}
}
void BStree::del(int key)
{
	Node* delNode = search(key);
	if (delNode != NULL)
	{
		Node* parNode = parent(key);
		if (delNode->left == NULL && delNode->right == NULL)
		{
			if (delNode == parNode->left)
				parNode->left = NULL;
			else if (delNode == parNode->right)
				parNode->right = NULL;
			delete delNode;
		}
		else if (delNode->right == NULL && delNode->left != NULL)
		{
			if (key < parNode->data)
				parNode->left = delNode->left;
			else
				parNode->right = delNode->left;
			delete delNode;
		}
		else if (delNode->left == NULL && delNode->right != NULL)
		{
			if (key < parNode->data)
				parNode->left = delNode->right;
			else
				parNode->right = delNode->right;
			delete delNode;
		}
		else if (delNode->right != NULL && delNode->left != NULL)
		{
			int flag = 0;
			Node* changeNode = delNode->left;
			while (changeNode->right != NULL)
			{
				changeNode = changeNode->right;
				flag = 1;
			}
			parNode = parent(changeNode->data);
			if (changeNode->left == NULL)
			{
				delNode->data = changeNode->data;
				if (flag == 0)
					parNode->left = NULL;
				else if (flag == 1)
					parNode->right = NULL;
			}
			else if (changeNode->left != NULL)
			{
				delNode->data = changeNode->data;
				if (flag == 0)
					parNode->left = changeNode->left;
				else if (flag == 1)
					parNode->right = changeNode->left;
			}
			delete changeNode;
		}
		count--;
	}
	else
	{
		cout << "Element not found to delete" << endl;
	}
}
void BStree::display(Node* root)
{
	if (root != NULL)
	{
		display(root->left);
		cout << root->data << " ";
		display(root->right);
	}
}
int main()
{
	int choose, x, end = 1, n;
	BStree bt;
	cout << "Enter number of elements to insert" << endl;
	cin >> n;
	cout << "Enter elements" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		bt.insert(x);
	}
	while (end)
	{
		cout << "===================================================================" << endl;
		cout << "Enter an option you want" << endl;
		cout << "1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit" << endl;
		cout << "===================================================================" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Enter element to insert" << endl;
			cin >> x;
			bt.insert(x);
			break;
		case 2:
			cout << "Enter element to search" << endl;
			cin >> x;
			if (bt.search(x)!=NULL)
				cout << "Element " << x << " found" << endl;
			else
				cout << "Element " << x << " not found" << endl;
			break;
		case 3:
			cout << "Enter element to delete" << endl;
			cin >> x;
			bt.del(x);
			break;
		case 4:
			cout << "Inorder treavrsal of tree is " << endl;
			bt.display(bt.head);
			cout << endl;
			break;
		case 5:
			end = 0;
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}
}