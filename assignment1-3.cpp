#include <iostream> //������� ����
#include <ctime>
#include <cstdlib>
using namespace std;

int turn = 0;
void InputUserNum(int *num) //user�� ���ڸ� �Է��ϴ� �Լ�
{
	int i;

	while (1) {
		int check = 0; //�̹� �Է��� ���ڸ� �Ǻ��ϱ� ���� ����

		cout << "Call a number(1~25) : ";
		int input;
		cin >> input; //ã�� ���� ���ڸ� �Է�

		if (input < 1 || input>25) { //input�� 1���� �۰ų�, 25���� ũ�� ���Է� �ϵ��� ��.
			cout << "input again !" << endl;
			continue;
		}
		else {
			for (int i = 0; i < 25; i++) {
				if (num[i] == input) { //�Է��� ���ڰ� �ѹ� �� �Էµ��� �ʵ��� �ߺ� üũ�ϴ� �ݺ���
					check++;
				}
			}
		}

		if (check != 0) { //���� num[i]�� ��ҿ� input�� ���� check�� ++�� �Ǹ� �� �Է��� �ϵ��� �ϴ� if��
			cout << "this number is already input. input again!" << endl;
		}
		else {
			num[turn++] = input; //�迭 num�� �Է��� ���� �����ϵ��� ��
			break;
		}

	}

}
void InputComNum(int *num) //computer�� ���ڸ� �Է��ϴ� �Լ�
{
	srand((unsigned)time(NULL));

	while (1) {
		int check = 0;
		cout << "Computer calls: ";
		int input;
		input = rand() % 25 + 1; //1~25������ ���ڸ� �������� ȣ��

		for (int i = 0; i < 25; i++) {
			if (num[i] == input) //�Է��� ���ڰ� �ѹ� �� �Էµ��� �ʵ��� �ߺ� üũ�ϴ� �ݺ���
			{
				check++;
			}
		}

		if (check != 0) { //���� num[i]�� ��ҿ� input�� ���� check�� ++�� �Ǹ� �� �Է��� �ϵ��� �ϴ� if��
			cout << input << "this number is already input. input again!" << endl;
		}
		else {
			cout << input << endl;
			num[turn++] = input;//�迭 num�� computer�� �θ� ���� input ���� �����ϵ��� ��
			break;
		}
	}
	cout << endl;
}
void CheckExistNum(int(*arr)[5]) //�����ǿ� ���ڰ� ������ �� �ߺ����� �����ǵ��� ����� �Լ�
{
	int Max_temp[25];
	int i, j, temp1, temp2, count;
	int SaveArray[50];
	count = 0;

	for (i = 0; i < 25; i++) {
		Max_temp[i] = i + 1; //Max_temp �迭�� 1 ���� 25�� �ʱ�ȭ
	}
	for (i = 0; i < 5; i++) { //�� �迭�� �ش�Ǵ� ĭ�� ���ʷ� 0���� �ʱ�ȭ
		for (j = 0; j < 5; j++) {
			arr[i][j] = 0;
		}
	}
	while (count != 25) { //count�� 25�� �Ǳ� ������ �ݺ�
		temp1 = rand() % 5;
		temp2 = rand() % 5;
		if (arr[temp1][temp2] == 0) { //�迭�� �ش��ϴ� ĭ�� temp1 �� temp2�� �������� ��� Max_temp�� ���� �־���
			arr[temp1][temp2] = Max_temp[count];
			count++;
		}
		else {
			temp1 = rand() % 5;
			temp2 = rand() % 5;
		}
	}
}

void MakeArray(int(*arr)[5]) // 5X5 ���� �������� �����ϴ� �Լ�
{
	int i, j;
	CheckExistNum(arr); //�ߺ��Ǵ� ���ڰ� ������ ����.
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void FindSameNum(int(*arr)[5], int *num) //�Ȱ��� ���ڸ� ã��, �� ���ڸ� '#' �̶�� ���ڷ� ��������ִ� �Լ�
{
	int i, j;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 25; k++) {
				if (num[k] == arr[i][j]) //num �迭���� ���� arr �迭���� ���� ������ �װ��� -1�� ����
					arr[i][j] = -1;
			}
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == -1) //-1�� ����� ���� #�� �ٽ� �ٲ���
				cout << '#' << ' ';
			else
				cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
int FindUserBingo(int(*arr)[5]) //User�� Bingo ���θ� �Ǵ��Ͽ�, User�� Bingo�� "User BINGO!"�� ����ϵ��� �ϴ� �Լ�
{
	int i, j, cnt1 = 0, cnt2 = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == -1) { //���� ���� ���� 
				cnt1++;
			}
			if (arr[j][i] == -1) { //���� ���� ����
				cnt2++;
			}
			if (cnt1 == 5) {
				cout << "User BINGO!!";
				return 1;
			}
			else if (cnt2 == 5) {
				cout << "User BINGO!!";
				return 1;
			}
			else if (cnt1 == 5 && cnt2 == 5) {
				cout << "User BINGO!!";
				return 1;
			}
		}
		cnt1 = 0; cnt2 = 0;
	}
	cout << endl;
	return 0;
}

int FindComBingo(int(*arr)[5]) // Com�� Bingo ���θ� �Ǵ��Ͽ�, Com�� Bingo�� "Com BINGO!"�� ����ϵ��� �ϴ� �Լ�
{
	int i, j, cnt1 = 0, cnt2 = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == -1) { //���� ���� ����
				cnt1++;
			}
			if (arr[j][i] == -1) { //���� ���� ����
				cnt2++;
			}
			if (cnt1 == 5) {
				cout << "Computer BINGO!!";
				return 1;
			}
			else if (cnt2 == 5) {
				cout << "Computer BINGO!!";
				return 1;
			}
			else if (cnt1 == 5 && cnt2 == 5) {
				cout << "Computer BINGO!!";
				return 1;
			}
		}
		cnt1 = 0; cnt2 = 0;
	}
	cout << endl;
	return 0;
}


int main()
{
	srand((unsigned)time(NULL));

	int user[5][5], com[5][5];
	int exist_num[25];


	cout << "<user bingo board>" << endl;
	MakeArray(user); //user�� 5X5 ���� �Լ� ����
	cout << endl;
	cout << "<computer bingo board>" << endl;
	MakeArray(com); //com�� 5X5 ���� �Լ� ����
	cout << endl;

	while (1)
	{
		InputUserNum(exist_num); //user�� ���� �Է�

		cout << "<user bingo board>" << endl;
		FindSameNum(user, exist_num); //���� num�� ã�� #���� �ٲ��ִ� �Լ�
		cout << "<computer bingo board>" << endl;
		FindSameNum(com, exist_num); //���� num�� ã�� #���� �ٲ��ִ� �Լ�
		cout << endl;

		if (FindUserBingo(user) == 1) { //user�� ���� Ȥ�� com�� ���ÿ� ������ �� �������� ���

			if (FindComBingo(com) == 1)
			{
				return 1;
			}
			return 1;
		}
		if (FindComBingo(com) == 1) { //com�� �������� ���
			return 1;
		}

		InputComNum(exist_num); //com�� ���� �Է�

		cout << "<user bingo board>" << endl;
		FindSameNum(user, exist_num); //���� num�� ã�� #���� �ٲ��ִ� �Լ�
		cout << "<computer bingo board>" << endl;
		FindSameNum(com, exist_num); //���� num�� ã�� #���� �ٲ��ִ� �Լ�

		if (FindUserBingo(user) == 1) { //user�� ���� Ȥ�� com�� ���ÿ� ������ �� �������� ���

			if (FindComBingo(com) == 1)
			{
				return 1;
			}
			return 1;
		}
		if (FindComBingo(com) == 1) { //com�� �������� ���
			return 1;
		}

	}
	return 0;
}
