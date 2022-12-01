#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Price.h"
#include "Keeper.h"
using namespace std;

Keeper keeper;

void remove() {
	if (!keeper.isEmpty()) return;

	int number;
	cout << "Enter ID:";
	cin >> number;
	if (number < 0 || number>keeper.getSize()) {
		cout << "\033[31mError:that product does not exist!\033[0m" << endl;
		return;
	}
	keeper.removeProduct(number);
	cout << "\033[34mThe product is removed successfully!\033[0m" << endl;

}

void editProduct() {

	if (!keeper.isEmpty()) return;

	int number;
	cout << "Enter ID:";
	cin >> number;
	cin.ignore();
	if (number < 0 || number>keeper.getSize()) {
		cout << "\033[31mError:that product does not exist!\033[0m" << endl;
		return;
	}

	keeper.listOfProducts[number]->edit();
}

void addToCart() {

	if (!keeper.isEmpty()) return;

	int num;
	cout << "Enter ID:";
	cin >> num;
	cin.ignore();
	if (num < 0 || num>keeper.getSize()) {
		cout << "\033[31mError:that product does not exist!\033[0m" << endl;
		return;
	}

	keeper.addToCart(keeper.listOfProducts[num]);
}


int menu() {
	int stop = 0;
	int command = 0;
	while (!stop) {

		cout << "Choose number of command: " << endl;
		cout << "1. Show the list of products. " << endl;
		cout << "2. Add product. " << endl;
		cout << "3. Remove product. " << endl;
		cout << "4. Edit product. " << endl;
		cout << "5. Save product.  " << endl;
		cout << "6. Load product. " << endl;
		cout << "7. Sort Shops by Alphabet. " << endl;
		cout << "8. Search the shop. " << endl;
		cout << "9. Add product to cart" << endl;
		cout << "10. Show the cart" << endl;
		cout << "0. Exit " << endl;
		cout << endl;

		cout << "Number of a command: ";

		cin >> command;
		cin.ignore();
		switch (command)
		{
		case 0:
			stop = 1;
			break;
		case 1:
			keeper.showListOfProducts();
			break;

		case 2:
			keeper += new Price();
			break;

		case 3:
			remove();
			break;

		case 4:
			editProduct();
			break;
		case 5:
			if (!keeper.isEmpty()) continue;
			keeper.saveProduct();
			break;

		case 6:
			keeper.loadProduct();
			break;
		case 7:
			keeper.sortShopByAlphabet();
			break;
		case 8:
			keeper.searchShop();
			break;

		case 9:
			addToCart();
			break;
		case 10:
			keeper.showCart();
			break;
		default:
			cout << "\033[31mError\033[0m" << endl;
			break;
		}
	}
	return 0;
}

int main() {
	srand(time(NULL));
	menu();
	return 0;
}