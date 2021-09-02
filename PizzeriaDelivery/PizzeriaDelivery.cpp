#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct account
{
	char firstname[101];
	char lastname[101];
	char emailaddress[101];
	char homeaddress[101];
	char phonenumber[101];
	char password[101];
	account* urm;
};

struct pizza
{
	char name[101];
	int price;
}p[101];

struct cart
{
	char pizzaname[101]{};
	int pizzaprice{};
	int cntr = 0;
	cart* urm2{};
};

void pizzas()
{
	//Margherita
	strcpy_s(p[1].name, "Margherita");
	p[1].price = 8;
	//Quattro Stagioni
	strcpy_s(p[2].name, "Quattro Stagioni");
	p[2].price = 10;
	//Diavola
	strcpy_s(p[3].name, "Diavola");
	p[3].price = 9;
	//Veggie
	strcpy_s(p[4].name, "Veggie");
	p[4].price = 9;
	//Frutti di Mare
	strcpy_s(p[5].name, "Frutti di Mare");
	p[5].price = 11;
}

int n, x, y, a, b, c;
char first[101], last[101], email[101], address[101], phone[101], pass[101];
account* prim, * sf;
cart* prim2, * sf2;
account* client;

void remove(cart*& prim2, int poz)
{
	if (poz == 1)
	{
		cart* aux = prim2;
		prim2 = prim2->urm2;
		delete aux;
	}
	else
	{
		cart* aux = prim2;
		int j = 1;
		while (aux != NULL && j != poz - 1)
		{
			aux = aux->urm2;
			j++;
		}
		if (aux)
		{
			if (aux->urm2->urm2 == NULL)
			{
				cart* aux1 = aux->urm2;
				aux->urm2 = NULL;
				delete(aux1);
				sf2 = aux;
			}
			else
			{
				cart* aux1 = aux->urm2;
				aux->urm2 = aux1->urm2;
				delete(aux1);
			}
		}
	}
}

void remove_pizza()
{
	int total = 0;
	cout << '\n' << '\n' << "** Remove pizza **" << '\n' << '\n';
	cart* aux = prim2;
	int i = 1;
	while (aux != NULL)
	{
		cout << i << ". " << aux->cntr << "x " << aux->pizzaname << " $" << aux->pizzaprice << '\n' << '\n';
		total = total + aux->pizzaprice;
		aux = aux->urm2;
		i++;
	}
	cout << "TOTAL: $" << total << '\n' << '\n';
	cout << "Select pizza to remove: ";
	cin >> b;
	remove(prim2, b);
}

int cart_page()
{
	int total = 0;
	cout << '\n' << '\n' << "** Cart **" << '\n' << '\n';
	if (prim2 == NULL)
	{
		cout << "* No pizza in cart *" << '\n' << '\n';
		return 0;
	}
	else
	{
		cart* aux = prim2;
		while (aux != NULL)
		{
			cout << aux->cntr << "x " << aux->pizzaname << '\n' << "price: $" << aux->pizzaprice << '\n' << '\n';
			total = total + aux->pizzaprice;
			aux = aux->urm2;
		}
		cout << "TOTAL: $" << total << '\n' << '\n';
	}
}

void add_to_cart(cart*& prim2, cart*& sf2, int x)
{
	if (prim2 == NULL)
	{
		prim2 = new(cart);
		strcpy_s(prim2->pizzaname, p[x].name);
		prim2->pizzaprice = p[x].price;
		prim2->cntr++;
		prim2->urm2 = NULL;
		sf2 = prim2;
	}
	else
	{
		cart* aux;
		aux = new(cart);
		strcpy_s(aux->pizzaname, p[x].name);
		aux->pizzaprice = p[x].price;
		aux->cntr++;
		aux->urm2 = NULL;
		sf2->urm2 = aux;
		sf2 = aux;
	}
}

void delivery_info_page(account* client)
{
	cout << "** Delivery details **" << '\n' << '\n';
	cout << "Address: " << client->homeaddress << '\n';
	cout << "Full name: " << client->firstname << " " << client->lastname << '\n';
	cout << "Phone number: " << client->phonenumber << '\n' << '\n';
}

void checkout_page()
{
	cout << '\n' << "*** Checkout ***";
	cart_page();
	delivery_info_page(client);
	cout << "1. Confirm delivery" << '\n' << '\n';
	cout << "Select: ";
	cin >> c;
	if (c == 1)
	{
		cout << '\n' << '\n' << "** Thank you! **" << '\n' << '\n' << "Your order will arrive soon!" << '\n' << '\n' << "* Enjoy your tasty pizza :) *" << '\n' << '\n';
	}
}

void menu_page()
{
	cout << '\n' << '\n' << "** Pizza Menu **" << '\n' << '\n';
	cout << "1. Margherita $8" << '\n';
	cout << "2. Quattro Stagioni $10" << '\n';
	cout << "3. Diavola $9" << '\n';
	cout << "4. Veggie $9" << '\n';
	cout << "5. Frutti di Mare $11" << '\n';
	cout << '\n' << "Add pizza to cart: ";
	cin >> x;
	add_to_cart(prim2, sf2, x);
	cart_page();
	cout << "1. Continue shopping" << '\n';
	cout << "2. Remove pizza" << '\n';
	cout << "3. Proceed to checkout" << '\n' << '\n';
	cout << "Select: ";
	cin >> x;
	if (x == 1)
	{
		x = 0;
		menu_page();
	}
	if (x == 2)
	{
		x = 0;
		remove_pizza();
		cart_page();
		cout << "1. Continue shopping" << '\n';
		cout << "2. Proceed to checkout" << '\n' << '\n';
		cout << "Select: ";
		cin >> a;
		if (a == 1)
		{
			a = 0;
			menu_page();
		}
		if (a == 2)
		{
			a = 0;
			if (prim2 == NULL)
			{
				cout << '\n' << '\n' << "* No pizza in cart *" << '\n';
				menu_page();
			}
			else checkout_page();
		}
	}
	if (x == 3)
	{
		x = 0;
		checkout_page();
	}
}

void main_page(account* aux)
{
	cout << '\n' << '\n' << "*** Main Menu ***" << '\n';
	cout << '\n' << "** Welcome " << aux->firstname << "! **" << '\n' << '\n';
	cout << "1. Menu" << '\n';
	cout << "2. Cart" << '\n';
	cout << '\n' << "Select: ";
	cin >> y;
	if (y == 1)
	{
		menu_page();
	}
	if (y == 2)
	{
		if (cart_page() == 0) main_page(aux);
	}
}

account* search_account(account* prim, char email[101])
{
	account* nod = prim;
	while (nod != NULL && strcmp(nod->emailaddress, email) != 0)
	{
		nod = nod->urm;
	}
	return nod;
}

int login_page()
{
	cout << '\n' << '\n' << "** Login Page **" << '\n' << '\n';
	cout << "Email address: ";
	cin >> email;
	cout << "Password: ";
	cin >> pass;
	account* aux = search_account(prim, email);
	if (aux != NULL)
	{
		if (strcmp(aux->emailaddress, email) == 0)
		{
			if (strcmp(aux->password, pass) != 0)
			{
				cout << '\n' << "* Incorrect password *" << '\n' << '\n';
				login_page();
			}
			else
			{
				client = aux;
				main_page(aux);
			}
		}
	}
	else
	{
		cout << '\n' << "* Account doesn't exist *" << '\n' << '\n';
		return 0;
	}
}

void create_users_list(account*& prim, account*& sf, char first[101], char last[101], char email[101], char address[101], char phone[101], char pass[101])
{
	ifstream users("users.txt");
	while (users >> first >> last >> email >> address >> phone >> pass) {
		if (prim == NULL)
		{
			prim = new (account);
			strcpy_s(prim->firstname, first);
			strcpy_s(prim->lastname, last);
			strcpy_s(prim->emailaddress, email);
			strcpy_s(prim->homeaddress, address);
			strcpy_s(prim->phonenumber, phone);
			strcpy_s(prim->password, pass);
			prim->urm = NULL;
			sf = prim;
		}
		else
		{
			account* aux;
			aux = new(account);
			strcpy_s(aux->firstname, first);
			strcpy_s(aux->lastname, last);
			strcpy_s(aux->emailaddress, email);
			strcpy_s(aux->homeaddress, address);
			strcpy_s(aux->phonenumber, phone);
			strcpy_s(aux->password, pass);
			aux->urm = NULL;
			sf->urm = aux;
			sf = aux;
		}
	}
	users.close();
}

void create_account(char first[101], char last[101], char email[101], char address[101], char phone[101], char pass[101])
{
	ofstream users("users.txt", ios::app);
	users << first << ' ' << last << ' ' << email << ' ' << address << ' ' << phone << ' ' << pass << '\n';
	users.close();
}

void create_account_page()
{
	cout << '\n' << '\n' << "** Create account **" << '\n' << '\n';
	cout << "DO NOT USE SPACE WHEN TYPING!" << '\n' << '\n';
	cout << "First name: ";
	cin >> first;
	cout << "Last name: ";
	cin >> last;
	cout << "Email address: ";
	cin >> email;
	cout << "Home address: ";
	cin >> address;
	cout << "Phone number: ";
	cin >> phone;
	cout << "Password: ";
	cin >> pass;
	create_account(first, last, email, address, phone, pass);
	cout << '\n' << "* Account successfully created *" << '\n' << '\n';
}

void welcome_page()
{
	cout << '\n' << "*** Welcome to Pizzeria Delivery ***" << '\n' << '\n';
	cout << "1. Log in" << '\n' << "2. Create account" << '\n' << '\n' << "Select: ";
	cin >> n;
	if (n == 2)
	{
		n = 0;
		create_account_page();
		welcome_page();
	}
	if (n == 1)
	{
		n = 0;
		create_users_list(*&prim, *&sf, first, last, email, address, phone, pass);
		if (login_page() == 0) welcome_page();
	}
}

int main()
{
	pizzas();
	welcome_page();
	return 0;
}