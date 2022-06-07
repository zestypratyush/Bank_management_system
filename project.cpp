#include <bits/stdc++.h>

using namespace std;

class account
{
	int acno;
	string name;
	int deposit;
	char type;

public:
	void create_account(); //function to get data from user
	void show_account();   //function to show data on screen
	void modify();		   //function to get new data from user
	void dep(int);		   //function to accept amount and add to balance amount
	void draw(int);		   //function to accept amount and subtract from balance amount
	void report();		   //function to show data in tabular format
	int retacno();		   //function to return account number
	int retdeposit();	   //function to return balance amount
	char rettype();		   //function to return type of account
};

void account::create_account()
{
	cout << "\nEnter The account No. : ";
	cin >> acno;
	cout << "\nEnter The Name of The account Holder : ";
	cin >> name;
	cout << "\nEnter Type of The account (C/S) : ";
	cin >> type;
	cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin >> deposit;
	//system("cls");
	cout << "\n\n                   \t\t\t\t\t      Account Created..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
	cin.get();
}

void account::show_account()
{
	cout << "\nAccount No."
		 << "\t: " << acno;
	cout << "\nAccount Holder Name"
		 << ": ";
	cout << name;
	cout << "\nType of Account"
		 << "\t: " << type;
	cout << "\nBalance amount"
		 << "\t: " << deposit;
	cin.get();
}

void account::modify()
{
	cout << "\nThe account No"
		 << "\t: " << acno;
	cout << "\n\nEnter The Name of The account Holder"
		 << "\t: ";
	cin >> name;
	cout << "\nEnter Type of The account (C/S)"
		 << "\t: ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter The amount"
		 << "\t: ";
	cin >> deposit;
}

void account::dep(int x)
{
	deposit += x;
}

void account::draw(int x)
{
	deposit -= x;
}

void account::report()
{
	cout << acno << "\t\t" << name;
	 
	cout << "\t\t"<<type;
 
	cout << "\t\t"<<deposit << endl;
}

int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}

class node
{
public:
	account data;
	node *next;
};

void insertAtTail(node *&head)
{
	node *n = new node;
	n->data.create_account();

	if (head == NULL)
	{
		head = n;
		return;
	}

	node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}

node *lSearch(node *head, int key)
{
	node *temp = head;
	while (temp != NULL)
	{
		if (temp->data.retacno() == key)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void deposit(node *&head, int key)
{
	node *n = lSearch(head, key);

	if (n != NULL)
	{
		int x;
		cout << "Enter amount to deposit : ";
		cin >> x;
		n->data.dep(x);
	}
}

void withd(node *&head, int key)
{
	node *n = lSearch(head, key);

	if (n != NULL)
	{
		int x;
		cout << "Enter amount to withdraw : ";
		cin >> x;
		n->data.draw(x);
	}
}

void detail(node *&head, int key)
{
	node *n = lSearch(head, key);

	if (n != NULL)
	{
		n->data.show_account();
	}
}

void deleteAtHead(node *&head)
{
	node *todelete = head;
	head = head->next;
	delete todelete;
}

void deletion(node *&head, int val)
{
	if (head == NULL)
	{
		return;
	}
	if (head->next == NULL)
	{
		deleteAtHead(head);
		return;
	}

	node *temp = head;
	while (temp->next->data.retacno() != val)
	{
		temp = temp->next;
	}
	node *todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

void close(node *&head, int key)
{
	deletion(head, key);
}

void modi(node *&head, int key)
{
	node *n = lSearch(head, key);
	if (n != NULL)
	{
		n->data.modify();
	}
}

void accList(node *&head){
	node *temp = head;
	while (temp!=NULL)
	{
		temp->data.report();
		temp= temp->next;
	}
	
}

int main()
{

	node *head = NULL;

	char ch;
	int num;
	do
	{ //system("cls");
		cout << "\n\n\t\t\t\t  ******Bank Management System******";
		cout << "\n\t\t\t\t======================================";
		cout << "\n\n\t\t\t\t  ******ABV-IIITM Bank******";
		cout << "\n\t\t\t\t==========================================";
		cout << "\n\n\t\t\t\t\t**MAIN MENU**";
		cout << "\n\n\t\t\t\t\t1. NEW ACCOUNT";
		cout << "\n\n\t\t\t\t\t2. DEPOSIT AMOUNT";
		cout << "\n\n\t\t\t\t\t3. WITHDRAW AMOUNT";
		cout << "\n\n\t\t\t\t\t4. ACCOUNT DETAILS";
		cout << "\n\n\t\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout << "\n\n\t\t\t\t\t6. CLOSE AN ACCOUNT";
		cout << "\n\n\t\t\t\t\t7. MODIFY AN ACCOUNT";
		cout << "\n\n\t\t\t\t\t8. EXIT";
		cout << "\n\n\t\t\t\t==>>Enter Your Choice: ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			insertAtTail(head);
			break;
		case '2':
			cout << "\n\n\t\t\t\tEnter The account No. : ";
			cin >> num;
			deposit(head,num);
			break;
		case '3':
			cout << "\n\n\t\t\t\tEnter The account No. : ";
			cin >> num;
			withd(head,num);
			break;
		case '4':
			cout << "\n\n\t\t\t\tEnter The account No. : ";
			cin >> num;
			detail(head,num);
			break;
		case '5':
			accList(head);
			break;
		case '6':
			cout << "\n\n\t\t\t\tEnter The account No. : ";
			cin >> num;
			close(head,num);
			break;
		case '7':
			cout << "\n\n\t\t\t\tEnter The account No. : ";
			cin >> num;
			modi(head,num);
			break;
		case '8':
			//system("cls");
			cout << "\n\n       \t\t\t\t\t      Thank You For Using Automatic Banking System" << endl;
			//getch();
			//system("cls");
			exit(0);

		default:
			cout << "wrong choice" << endl;
		}
		//getch();
	} while (ch != '8');
	return 0;
}