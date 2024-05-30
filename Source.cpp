#include<iostream>
#include<conio.h>
struct node
{
	int key = 0;
	node* prev = nullptr, * next = nullptr;
};
struct lista
{
	node* head = nullptr, * tail = nullptr;
	int Size = 0;
	void push_front(int value)
	{
		node* newNode = new node;
		newNode->key = value;
		newNode->next = head;
		if (head)
			head->prev = newNode;
		else
			tail = newNode;
		head = newNode;
		++Size;
	}
	void push_back(int value)
	{
		node* newNode = new node;
		newNode->key = value;
		newNode->prev = tail;
		if (tail)
			tail->next = newNode;
		else
			head = newNode;
		tail = newNode;
		++Size;
	}
	void pop_front()
	{
		if (Size == 0)
			return;
		if (Size == 1)
		{
			node* aux = head;
			head = tail = nullptr;
			delete aux;
		}
		else
		{
			node* aux = head;
			head = aux->next;
			delete aux;
		}
		if (head)
			head->prev = nullptr;
		else
			tail = nullptr;
		--Size;
	}
	void pop_back()
	{
		if (Size == 0)
			return;
		if (Size == 1)
		{
			node* aux = tail;
			head = tail = nullptr;
			delete aux;
		}
		else
		{
			node* aux = tail;
			tail = aux->prev;
			delete aux;
		}
		if (tail)
			tail->next = nullptr;
		else
			head = nullptr;
		--Size;
	}
	node* find(int value)
	{
		for (node* i = head; i; i = i->next)
			if (i->key == value)
				return i;
		return nullptr;
	}
	void erase(node* Nod)
	{
		if (Nod == nullptr)
			return;
		if (Nod == head)
		{
			pop_front();
			return;
		}
		if (Nod == tail)
		{
			pop_back();
			return;
		}
		Nod->prev->next = Nod->next;
		Nod->next->prev = Nod->prev;
		delete Nod;
		--Size;
	}
	void remove(int value)
	{
		for (node* i = head; i;)
			if (i->key == value)
				erase(i);
			else
				i = i->next;
	}
	void insert(node* Nod, int value)
	{
		if (Nod == nullptr)
			return;
		if (Nod == head || Size == 0)
		{
			push_front(value);
			return;
		}
		node* newNode = new node;
		newNode->key = value;
		newNode->prev = Nod->prev;
		newNode->next = Nod;
		Nod->prev = newNode;
		++Size;
	}
	bool empty()
	{
		return !Size;
	}
	void clear()
	{
		while (head)
			pop_front();
	}
	void print()
	{
		node* current = head;
		while (current)
		{
			std::cout << current->key << ' ';
			current = current->next;
		}
		std::cout << '\n';
	}
	int size()
	{
		return Size;
	}
};
bool palindrom(lista L)
{
	if (L.size() < 2)
		return 1;
	for (node* i = L.head, *j = L.tail; (i != j) && (i->prev != j); i = i->next, j = j->prev)
		if (i->key != j->key)
			return 0;
	return 1;
}
bool compare(lista L1, lista L2)
{
	if (L1.size() != L2.size())
		return 0;
	for (node* i = L1.head, *j = L2.head; i && j; i = i->next, j = j->next)
		if (i->key != j->key)
			return 0;
	return 1;
}
bool alegeLista()
{
	int x=0;
	std::cout << "Alegeti lista pe care operati:\n1. Lista 1\n2. Lista 2\n";
	do 
	{
		std::cin >> x;
		if (x != 1 && x != 2)
			std::cout << "Input invalid. Alegeti o optiune.";
	} while (x != 1 && x != 2);
	return x % 2;

}
int main()
{
	lista L1, L2;
	int x=-1,value;
	do
	{
		std::cout << "Alegeti o optiune:\n";
		std::cout << "1. Introduceti un element la inceputul listei\n";
		std::cout << "2. Introduceti un element la sfarsitul listei\n";
		std::cout << "3. Eliminati elementul de la inceputul listei\n";
		std::cout << "4. Eliminati elementul dela sfaritul listei\n";
		std::cout << "5. Stergeti toate elementele care au o valoare data\n";
		std::cout << "6. Inserati un element inaintea unei valori date\n";
		std::cout << "7. Stergeti total o lista\n";
		std::cout << "8. Verificati daca o lista este palindrom\n";
		std::cout << "9. Comparati cele 2 liste\n";
		std::cout << "10. Afisati o lista\n";
		std::cout << "0. Iesiti din program\n";
		std::cin >> x;
		switch (x)
		{
		case 1:
			std::cout << "Introduceti valoarea: ";
			std::cin >> value;
			if (alegeLista())
				L1.push_front(value);
			else
				L2.push_front(value);
			break;
		case 2:
			std::cout << "Introduceti valoarea: ";
			std::cin >> value;
			if (alegeLista())
				L1.push_back(value);
			else
				L2.push_back(value);
			break;
		case 3:
			if (alegeLista())
				L1.pop_front();
			else
				L2.pop_front();
			break;
		case 4:
			if (alegeLista())
				L1.pop_back();
			else
				L2.pop_back();
			break;
		case 5:
			std::cout << "Introduceti valoarea: ";
			std::cin >> value;
			if (alegeLista())
				L1.remove(value);
			else
				L2.remove(value);
			break;
		case 6:
			std::cout << "Introduceti valoarea: ";
			std::cin >> value;
			if (alegeLista())
			{
				std::cout << "Alegeti in fata carei valori inserati: \n";
				int key;
				std::cin >> key;
				node* aux = L1.find(key);
				L1.insert(aux, value);
			}
			else
			{
				std::cout << "Alegeti in fata carei valori inserati: \n";
				int key;
				std::cin >> key;
				node* aux = L2.find(key);
				L2.insert(aux, value);
			}
			break;
		case 7:
			if (alegeLista())
				L1.clear();
			else
				L2.clear();
			break;
		case 8:
			if (alegeLista())
			{
				if (palindrom(L1))
					std::cout << "Lista 1 este o lista palindrom.\n";
				else
					std::cout << "Lista 1 nu este o lista palindrom.\n";
			}
			else
			{
				if (palindrom(L2))
					std::cout << "Lista 2 este o lista palindrom.\n";
				else
					std::cout << "Lista 2 nu este o lista palindrom.\n";
			}
			break;
		case 9:
			if (compare(L1, L2))
				std::cout << "Cele 2 liste sunt identice.\n";
			else
				std::cout << "Cele 2 liste nu sunt identice.\n";
			break;
		case 10:
			if (alegeLista())
				L1.print();
			else
				L2.print();
		case 0:
			break;
		default:
			std::cout << "Input invalid.\n";
			break;
		}
		if (x) x = -1;
		system("pause");
		system("cls");
	} while (x != 0);
	return 0;
}
