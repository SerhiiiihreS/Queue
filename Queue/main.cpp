#include <iostream>
using namespace std;


struct Element
{
	char data;
	Element* Next;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;

public:
	List();
	~List();

	void Add(char data);

	void Del();
	void DelAll();
	void Print();

	int GetCount();

	void AddIndex(char data, int index)// Z, 2
	{
		Element* temp = Head;
		int i = 1;
		while (i < index)
		{
			temp = temp->Next;
			i++;
		}
		Element* NewNode = new Element;
		NewNode->data = data;

		NewNode->Next = temp->Next;
		temp->Next = NewNode;
	}

	void DelIndex(int index)
	{
		Element* prevdel = Head;
		int i = 1;
		while (i < index)
		{
			prevdel = prevdel->Next;
			i++;
		}
		Element* del = prevdel->Next;
		prevdel->Next = del->Next;
		delete del;
	}

	int FindElement(char dt)
	{
		Element* temp = Head;
		int i = 0;
		int e = 0;
		while (temp!=NULL)
		{
			temp = temp->Next;

			if (temp->data == dt) {
				i++;
				cout << "index ->" << i;
				cout<<endl;
				return i;
				e = 1;
			}
			
			i++;
		}
		if ( e == 0) {
			cout << "Item not found."; 
			return NULL;
			

			}
	}
};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}

void List::Add(char data)
{
	Element* temp = new Element;

	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
}

void List::DelAll()
{
	while (Head != 0)
		Del();
}

void List::Print()
{
	Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}

	cout << "\n\n";
}

void main()
{
	List lst;
	lst.Add('A');
	lst.Add('B');
	lst.Add('C');
	lst.Add('D');
	lst.Add('E');
	lst.Add('F');
	lst.Print();

	lst.AddIndex('r', 3);
	lst.Print();
	lst.DelIndex(2);
	lst.Print(); 
	lst.FindElement('r');
}
