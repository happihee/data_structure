#include <iostream>
#pragma once
using namespace std;
class store
{
private:
	char *name;
	int price;
	int quantity;
	int sequence;
public:

	void setname(char *name);
	void setprice(int price);
	void setquantity(int quantity);

	char *getname();
	int getprice();
	int getquantity();

	store();
	~store();
};

