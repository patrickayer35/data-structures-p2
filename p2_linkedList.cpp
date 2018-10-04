#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

template<class T>
class LinkedList
{
private:
	node* head;
	node* tail;
    int length;
    int MaxSize;

public:
    //LinearList(int MaxLinearSize = 10);
	LinkedList(int m = 10);
    ~LinkedList() {};//{ delete[] element; }
    int isEmpty() const { return length == 0; }
    int Length() const { return length;}
    void Delete(int k);
	void Insert(int k, T& x);
    void Output() const;
};

template<class T>
LinkedList<T>::LinkedList(int m)
{
	head = NULL;
	tail = NULL;
	length = 0;
	MaxSize = m;
}

template<class T>
void LinkedList<T>::Insert(int k, T& x)
{
	if (length == MaxSize)
	{
		cout << "list is at maximum length\n";
		return;
	}
	
	node* newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	
	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	if (k >= length)
	{
		tail->next = newNode;
		tail = newNode;
	}
	else
	{
		if (k == 0 && length > 1)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			node* prev = new node;
			node* curr = new node;
			curr = head;
			for (int i = 1; i < k; i++)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = newNode;
			newNode->next = curr;
		}
	}
	length++;
}

template<class T>
void LinkedList<T>::Delete(int k)
{
	if (isEmpty())
	{
		cout << "list is empty\n";
		return;
	}
	
	if (k == 0)
	{
		node* curr = new node;
		curr = head;
		head = head->next;
		delete curr;
	}
	else
	{
		node* curr = new node;
		node* prev = new node;
		curr = head;
		if (k >= length)
		{
			while (curr->next != NULL)
			{
				prev = curr;
				curr = curr->next;
			}
			tail = prev;
			prev->next = NULL;
			delete curr;
		}
		else
		{
			for (int i = 1; i < k; i++)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = curr->next;
		}
	}
	length--;
}

template<class T>
void LinkedList<T>::Output() const
{
	if (isEmpty())
	{
		cout << "list is empty\n";
		return;
	}
	node *curr = new node;
	curr = head;
	while (curr != NULL)
	{
		cout << curr->data << "\n";
		curr = curr->next;
	}
}

int main()
{
	int x = 10, y = 17;
	LinkedList<int> obj(11);
	for (int i = 0; i < 5; i++)
	{
		cout << i << endl;
		if (i == 3)
		{
			obj.Insert(i, x);
		}
		else
		{
			obj.Insert(i, i);
		}
	}
	obj.Insert(0, x);
	obj.Insert(2, y);
	obj.Output();
	cout << "now deleting data...\n";
	obj.Delete(0);
	obj.Output();
	cout << "-------------\n";
	obj.Delete(1);
	obj.Output();
	cout << "-------------\n";
	obj.Delete(20);
	obj.Output();
	
	return 0;
}



















