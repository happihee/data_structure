#include <iostream>
#include <fstream>
#include "store.h"
#include "String.h"
using namespace std;

void Insert(store* st, int temp)  //Insert 역할을 하는 함수
{

	char arr[100] = { 0 };
	char name[100] = { 0 };
	int price = 0;
	int quantity = 0;

	cout << "** Insert **" << endl;

	cout << ">Item Name:";
	cin.ignore();
	cin.getline(name, 100);
	st[temp].setname(name);

	cout << ">Price:";
	cin >> price;
	st[temp].setprice(price);


	cout << ">Quantity:";
	cin >> quantity;
	st[temp].setquantity(quantity);

}
void Update(store* st) //Update 역할을 하는 함수
{
	char arr[100] = { 0 };
	char name[100] = { 0 };
	int price = 0;
	int quantity = 0;
	int sequence = 0;
	int compare = 0;

	cout << "** Update **" << endl;
	while (1) {
		cout << ">Input sequence:";
		cin >> sequence; //각 줄에 해당하는 값들을 변경해 주면 되기때문에 sequence를 비교값으로 지정  
		if (st[sequence].getname() == NULL)
		{
			cout << "No item" << endl;
			return;

		}
		else {
			cout << ">Item Name:";
			cin.ignore();
			cin.getline(name, 100);
			st[sequence - 1].setname(name);

			cout << ">Price:";
			cin >> price;
			st[sequence - 1].setprice(price);


			cout << ">Quantity:";
			cin >> quantity;
			st[sequence - 1].setquantity(quantity);
			break;
		}
	}
}
void Delete(store* st, int temp) //Delete 해주는 함수
{
	char arr[100] = { 0 };
	char name[100] = { 0 };
	int price = 0;
	int quantity = 0;
	int sequence = 0;
	int compare = 0;
	int temp2 = 0;

	cout << "** Delete **" << endl;
	cout << ">Input sequence :";
	cin >> sequence;

	if (st[sequence - 1].getname() == NULL)
	{
		cout << "No item" << endl;
		return;
	}

	else
	{
		for (int i = sequence - 1; i < temp - 1; i++)
		{
			st[i].setname(st[i + 1].getname());
			st[i].setprice(st[i + 1].getprice());
			st[i].setquantity(st[i + 1].getquantity());

		}
	}
	temp--;
}

void Print(store* st, int temp) //Sort와 함께 콘솔창에 Print해주는 함수
{
	char arr[100] = { 0 };
	char name[100] = { 0 };
	int price = 0;
	int quantity = 0;
	int sequence = 0;
	int compare = 0;
	int temp2 = 0;
	int num = 0;

	cout << "1. Sequence  2. Name  3. Price  4. Quantity" << endl;
	cout << "> Input sorting condition: ";
	cin >> num;

	if (num == 1) //모두 bubble sort를 사용하였으며 sequence 같은 경우는 원래 1번부터 차례로 정렬되어있으므로 따로 정렬하지 않음.
	{
		cout << "** KW Store Item List **" << endl;
		for (int i = 0; i < temp; i++)
		{
			cout << i + 1 << ". " << st[i].getname() << "($" << st[i].getprice() << "," << st[i].getquantity() << ")" << endl;
		}
	}
	if (num == 2)
	{
		for (int i = 0; i < temp; i++) {
			for (int j = i + 1; j < temp; j++) {
				if (my_cmp(st[i].getname(), st[j].getname())>0) {
					store temp;
					temp = st[i];
					st[i] = st[j];
					st[j] = temp;
				}
			}
		}
		for (int i = 0; i < temp; i++)
		{
			cout << i + 1 << ". " << st[i].getname() << "($" << st[i].getprice() << "," << st[i].getquantity() << ")" << endl;
		}
	}
	if (num == 3)
	{
		for (int i = 0; i < temp; i++) {
			for (int j = i + 1; j < temp; j++) {
				if (st[i].getprice() < st[j].getprice()) {
					store temp;
					temp = st[i];
					st[i] = st[j];
					st[j] = temp;
				}
			}
		}
		for (int i = 0; i < temp; i++)
		{
			cout << i + 1 << ". " << st[i].getname() << "($" << st[i].getprice() << "," << st[i].getquantity() << ")" << endl;
		}
	}
	if (num == 4)
	{
		for (int i = 0; i < temp; i++) {
			for (int j = i + 1; j < temp; j++) {
				if (st[i].getquantity() < st[j].getquantity()) {
					store temp;
					temp = st[i];
					st[i] = st[j];
					st[j] = temp;
				}
			}
		}
		for (int i = 0; i < temp; i++)
		{
			cout << i + 1 << ". " << st[i].getname() << "($" << st[i].getprice() << "," << st[i].getquantity() << ")" << endl;
		}
	}
}
void Save(store* st, int temp) //위에서 변경해주거나 새로지정해준 부분들을 텍스트 파일에 저장해주는 역할
{
	cout << " ** Save ** " << endl;
	ofstream save;
	save.open("ItemList.txt");

	for (int i = 0; i < temp; i++)
	{
		save << st[i].getname() << "/" << st[i].getprice() << "/" << st[i].getquantity();
		if (i != temp - 1) {
			save << "\n";
		}
	}
}

int main()
{
	int num = 0;
	int temp = 0;
	char buf[100] = { 0 };
	char deli[] = "/";
	char* arr = NULL;
	char name[100] = { 0 };
	int price = 0;
	int quantity = 0;
	int itemnum = 0;

	ifstream fin; //파일 스트림 객체 생성
	fin.open("ItemList.txt"); //input.txt 파일을 염
	store* st = new store[100];

	if (!fin) { //input 파일이 없을 때 출력
		cout << "파일을 읽을 수 없습니다!" << endl;
	}
	while (1)
	{

		cout << "1. Load  2. Insert  3. Update  4. Delete  5. Print  6. Save  7. Quit " << endl;
		cout << ">Input number:";
		cin >> num;
		if (num == 1)
		{
			while (!fin.eof()) {
				fin.getline(buf, 100);//이미 저장된 값을 store class에 지정해줌 
				itemnum++;
				arr = my_tok(buf, deli); st[temp].setname(arr);
				arr = my_tok(NULL, deli); st[temp].setprice(atoi(arr));
				arr = my_tok(NULL, deli); st[temp].setquantity(atoi(arr));
				temp++;
			}
			fin.seekg(ios::beg);
			itemnum = 0;

			cout << " ** Load Complete ** " << endl;
			continue;
		}
		if (num == 2)
		{
			Insert(st, temp);
			temp++;
			continue;
		}
		if (num == 3)
		{
			Update(st);
			continue;
		}
		if (num == 4)
		{
			Delete(st, temp);
			temp--;
			continue;
		}
		if (num == 5)
		{
			Print(st, temp);

		}
		if (num == 6)
		{
			Save(st, temp);
		}
		if (num == 7)
		{
			return 0;
		}
	}
	return 0;
}