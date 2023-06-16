#include "Stack.h"
#include <iostream>

struct Stack* buffer = new struct Stack;

using namespace std;

// backend
void stack::Init(int data) // �������� �����
{
	Node* node = new Node;
	node->Next = node->Prev = nullptr;
	buffer->Head = buffer->Tail = node;
	node->Data = data;
}

void stack::Push(int data) // ���������� � ����
{
	Node* newNode = new Node;
	Node* node = new Node;
	node = buffer->Tail;
	newNode->Data = data;
	newNode->Next = nullptr;
	newNode->Prev = node;
	node->Next = newNode;
	buffer->Tail = newNode;
}

int stack::Pop()// �������� �� �����
{
	Node* node = new Node;
	node = buffer->Tail;

	if (buffer->Tail == buffer->Head)
	{
		int data = buffer->Tail->Data;
		buffer->Head = buffer->Tail = nullptr;
		delete node;
		return data;
	}

	int data = buffer->Tail->Data;
	node->Prev->Next = nullptr;
	buffer->Tail = node->Prev;
	delete node;
	return data;
}

void stack::Clear() // ������� �����
{
	Node* node = buffer->Tail->Prev;
	while (node != nullptr)
	{
		Pop();
		node = node->Prev;
	}
	Pop();
}

// frontend
void stack::Output() // ����� � ������� �����
{
	cout << "����: ";
	Node* node = buffer->Head;
	while (node != nullptr)
	{
		cout << node->Data << " ";
		node = node->Next;
	}
	cout << endl;
}

int stack::Menu()
{
	cout << "���� �����" << endl;
	cout << "1. ������� ����� ����" << endl;
	cout << "2. �������� ����� ������� �� �����" << endl;
	cout << "3. ������� ����� ����� ������� �� �����" << endl;
	cout << "4. �������� ����" << endl;
	cout << "5. ����� � ������� ����" << endl;
	Output();
	cout << "������� �������: ";

	int act = -1; cin >> act;
	return act;
}

void stack::Stack()
{
	bool work = true;
	while (work == true)
	{
		switch (Menu())
		{
		case 1:
		{
			cout << "������� �������, ������� �� ������ ��������: ";
			int act = -1; cin >> act;
			Init(act);
			break;
		}
		case 2:
		{
			if (IsInit() == false)
			{
				cout << "������� �������, ������� �� ������ ��������: ";

				int act = -1; cin >> act;
				Init(act);
			}
			else
			{
				cout << "������� �������, ������� �� ������ ��������: ";

				int act = -1; cin >> act;
				Push(act);
			}
			break;
		}
		case 3:
		{
			if (IsInit() == true)
			{
				Pop();
			}
			break;
		}
		case 4:
		{
			if (IsInit() == true)
			{
				Clear();
			}
			cout << "���� ��� ������." << endl;
			break;
		}
		default:
		{
			cout << "�� ������ ���������� � ������� ����. . ." << endl;
			return;
		}
		}
	}
	cout << endl;
}

void stack::AutoInit() // �������������� �������� �����
{
	if (IsInit() == false)
	{
		cout << "���� ��� ������ �������������!" << endl;
		cout << "������� �������, ������� �� ������ ��������: ";

		int act = -1; cin >> act;
		Init(act);
	}
}

bool stack::IsInit() // �������� �� ������� �����
{
	Node* node = new Node;
	node = buffer->Head;
	if (node == nullptr)
	{
		return false;
	}
	return true;
}