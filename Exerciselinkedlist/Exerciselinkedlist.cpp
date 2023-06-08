#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** satria, Node** abrar);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { 
}
bool CircularLinkedList::search(int rollno, Node** satria, Node** abrar) {
	*satria = LAST->next;
	*abrar = LAST->next;
	while (*abrar != LAST) {
		if (rollno == (*abrar)->rollNumber) {
			return true;
		}
		*satria = *abrar;
		*abrar = (*abrar)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { 
	if (listEmpty()) {
		return false;
	}

	if (LAST->next == LAST) {
		delete LAST;
		LAST = NULL;
		return true;
	}

	Node* satria = LAST->next;
	Node* abrar = LAST->next->next;

	while (abrar != LAST) {
		satria = abrar;
		abrar = abrar->next;
	}

	satria->next = abrar->next;
	delete abrar;

	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* abrarNode = LAST->next;
		while (abrarNode != LAST) {
			cout << abrarNode->rollNumber << " " << abrarNode->name << endl;
			abrarNode = abrarNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;								//menampilkan menu
			cout << "1. Add a record to the list" << endl;			//pilihan menu 1
			cout << "2. Delete a record from the list" << endl;		//pilihan menu 2
			cout << "3. View all the records in the list" << endl;	//pilihan menu 3
			cout << "4. Exit" << endl;								//pilihan menu 4
			cout << "\nEnter your choice (1-5): ";					//pengguna memilih menu 1 sampai 4
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;	//menampilkan pesan invalid option
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}