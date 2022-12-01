#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Price {
public:
	Price();
	void setProduct();
	void setShop();
	void setRubles();
	void printData();
	string getShop();
	int getRubles();
	void edit();
	void writeToFile(ofstream& file);
	Price(string valueProduct, string valueShop, int valueRubles) {
		product = valueProduct;
		shop = valueShop;
		rubles = valueRubles;
	};
private:
	string product;
	string shop;
	int rubles;
};