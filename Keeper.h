#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Keeper {
public:

	void showListOfProducts();
	Keeper& operator += (Price* price);
	void removeProduct(int ID);
	void saveProduct();
	void loadProduct();
	void sortShopByAlphabet();
	void searchShop();
	void showCart();
	void calculatePrice();
	void addToCart(Price* price);
	bool isEmpty();
	~Keeper();

	Price** listOfProducts;
	int getSize();

	Price** shoppingCart;
	int getCartSize();

	Keeper() {
		listOfProducts = new Price * [0];
		shoppingCart = new Price * [0];
	};

	//Keeper() {
	//	shoppingCart = new Price * [0];
	//};

private:
	int size = 0;
	int cartSize = 0;
};
