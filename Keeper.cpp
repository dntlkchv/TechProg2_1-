#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Price.h"
#include "Keeper.h"

using namespace std;

Keeper:: ~Keeper() {
	delete[]listOfProducts;
	delete[]shoppingCart;
}
int Keeper::getSize()
{
	return this->size;
}

bool Keeper::isEmpty() {
	if (size > 0) return true;

	cout << "\033[34mThere are no products yet. \033[0m" << endl;
	return false;
}
void Keeper::showListOfProducts() {
	if (!isEmpty()) return;
	for (int i = 0; i < size; i++) {
		listOfProducts[i]->printData();
	}
}
void Keeper::sortShopByAlphabet() {
	if (!isEmpty()) return;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (_stricmp(listOfProducts[j]->getShop().c_str(), listOfProducts[j + 1]->getShop().c_str()) > 0) {
				Price* tmp = listOfProducts[j];
				listOfProducts[j] = listOfProducts[j + 1];
				listOfProducts[j + 1] = tmp;

			}

		}
		listOfProducts[i]->printData();
	}
}
int Keeper::getCartSize()
{
	return this->cartSize;
}

void Keeper::showCart() {
	if (!isEmpty()) return;
	for (int i = 0; i < cartSize; i++) {
		shoppingCart[i]->printData();

	}
	calculatePrice();
}
void Keeper:: calculatePrice()
{
	int sum = 0; 
	for (int i = 0; i < cartSize; ++i) {
		sum += shoppingCart[i]->getRubles();
	}
	
	cout <<"\033[1mTotal price: \033[0m"<< sum<<" rubles"<<endl;
}
void Keeper::addToCart(Price* price)
{
	Price** dest = new Price * [cartSize + 1];
	for (int i = 0; i < cartSize; i++) {
		dest[i] = shoppingCart[i];
	}
	dest[cartSize++] = price;
	delete[]shoppingCart;
	shoppingCart = dest;

}
void Keeper::searchShop() {
	string shopName;
	cout<< "Enter shop: ";
	getline(cin, shopName);
	int hits = 0;
	for (int i = 0; i < size; i++) {

		if (shopName == listOfProducts[i]->getShop())
		{
			listOfProducts[i]->printData();
			hits++;
		}
	}
	if (hits==0){
			cout << "\033[31mWe can`t find that shop\033[0m"<<endl;
		
	}
}

Keeper& Keeper::operator+=(Price* price)
{
	Price** dest = new Price * [size + 1];
	for (int i = 0; i < size; i++) {
		dest[i] = listOfProducts[i];
	}
	dest[size++] = price;
	delete[]listOfProducts;
	listOfProducts = dest;

	return *this;
}

void Keeper::removeProduct(int ID) {
	Price** dest = new Price * [size - 1];
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (i == ID) continue;
		dest[index] = listOfProducts[i];
		index++;
	}
	delete[]listOfProducts;
	listOfProducts = dest;
	size--;
}


void Keeper::saveProduct() {
	ofstream fout;

	fout.open("F1.txt");

	if (fout.is_open())
	{
		fout << size << "\n";
		for (int i = 0; i < size; i++) {
			listOfProducts[i]->writeToFile(fout);
		}

		cout << "\033[34mSuccessfully saved!\033[0m" << endl;
	}
	else {
		cout << "\033[31mCan`t open file\033[0m" << endl;
	}

	fout.close();
}

void Keeper::loadProduct() {
	string buffer;
	ifstream fin("F1.txt");
	try {
		if (!fin.is_open()) throw runtime_error("\033[31mError:can`t open file!\033[0m");

		int size;
		fin >> size;


		if (size <= 0) throw runtime_error("\033[31mError:file damage!\033[0m");

		int cnt = 0;
		Price** dest = new Price * [size];

		while (getline(fin, buffer) && cnt<size) {
	
				string valueProduct;
				string valueShop;
				int rubles;
			
				getline(fin, valueProduct);
				getline(fin, valueShop);
				fin >> rubles;

				dest[cnt++] = new Price(valueProduct, valueShop, rubles);
		
		}

		this->size = size;
		delete[]listOfProducts;
		listOfProducts = dest;
		cout << "\033[34mSuccessfully loaded!\033[0m" << endl;

	}
	catch (runtime_error error) {
		cout << error.what() << endl;
	}
	catch (...) {
		cout << "\033[31mUnknow error!\033[0m" << endl;
	}
	fin.close();
}
