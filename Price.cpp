#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Price.h"

Price::Price() {
	setProduct();
	setShop();
	setRubles();
}
void Price::setProduct() {
	cout << "\033[1mProduct`s name: \033[0m";
	getline(cin, product);
}
void Price::setShop() {
	cout << "\033[1mShop: \033[0m";
	getline(cin, shop);
}
void Price::setRubles() {
	cout << "\033[1mPrice in rubles: \033[0m";
	cin >> rubles;
	cin.get();
}
string Price::getShop() {
	return this->shop;
}
int Price::getRubles() {
	return this->rubles;
}
void Price::printData()
{
	cout << "\033[1mProduct`s name: \033[0m";
	cout << product << endl;
	cout << "\033[1mShop: \033[0m";
	cout << shop << endl;
	cout << "\033[1mPrice in rubles: \033[0m";
	cout << rubles << endl;
	cout << endl;
}

void Price::edit() {
	setProduct();
	setShop();
	setRubles();
}
void Price::writeToFile(ofstream& file) {
	file << product << "\n";
	file << shop << "\n";
	file << rubles << "\n";
}
