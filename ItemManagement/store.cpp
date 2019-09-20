#include <iostream>
#include "store.h"
#include "String.h"
using namespace std;


store::store()
{
	name = NULL;
	price = 0;
	quantity = 0;

}

void store::setname(char *_name)
{
	name = new char[10];
	my_cpy(name, _name);
}
void store::setprice(int _price)
{
	price = _price;
}
void store::setquantity(int _quantity)
{
	quantity = _quantity;
}

char *store::getname()
{
	return name;
}
int store::getprice()
{
	return price;
}
int store::getquantity()
{
	return quantity;
}

store::~store()
{

}
