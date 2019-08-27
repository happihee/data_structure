#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#pragma warning(disable:4996) //strtok_s �� strtok�� ���ֱ� ���� ���

void Bubble(int * arr) { //������������ �����ϴ� Bubble �Լ�
	int temp;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19 - i; j++) {
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	char arr1[100];
	int arr2[20] = { 0 };
	char *token;
	int num1, num2 = 0, num3;
	int k = 0;
	int result = 0;
	int count = 0;
	ifstream fin; //���� ��Ʈ�� ��ü ����
	fin.open("input.txt"); //input.txt ������ ��
	if (!fin) { //input ������ ���� �� ���
		cout << "������ ���� �� �����ϴ�!" << endl;
	}
	while (!fin.eof()) { //������ ���� �ƴ� �� ���� �ݺ�
		fin.getline(arr1, 100);
		token = strtok(arr1, " ");  //���� �������� �ڸ�
		token = strtok(NULL, " ");
		num1 = atoi(token); //char �� �Լ��� int�� �Լ��� ��ȯ�ϱ� ���� ���
		if (num1<1 || num1>20) //num1�� 1���� �۰� 20���� ū ���� �� error ���
		{
			cout << "error" << endl;
			break;
		}

		if (num1 % 2 == 0) { //num1 �� ¦���� ��
			fin.getline(arr1, 100);
			token = strtok(arr1, " "); //���� �������� �ڸ�
			token = strtok(NULL, " ");
			num2 = atoi(token);

			while (token != NULL) //token ���� NULL�� �ƴ� �� num2�ȿ� arr2 ��ҵ��� �߰�
			{
				num2 = atoi(token);
				arr2[k] = num2;
				k++;
				token = strtok(NULL, " ");
			}

			if (num2 < 1 || num2 > 9) //num2 �� ���� 1 �̻� 9���Ϸ� ����
			{
				cout << "error" << endl;
				break;
			}
			if (k % 2 == 1) { //��ҵ��� ¦�� �� �϶������� ����
				cout << "error" << endl;
				break;
			}

			int countInput = 0;
			for (int z = 0; z < 20; z++) { //ó�� �Է��� num1 �� arr2�� �� �ִ� ����� ������ ��
				if (arr2[z] != 0)
					countInput++;
			}
			if (countInput != num1) {
				cout << "error!" << endl;
				return 0;
			}

			Bubble(arr2); //arr2�� ����

			cout << "Output: ";

			for (int i = 0; i < num1; i += 2) //���� ���ں��� 2���� ������ �ϹǷ� i+=2
			{
				int multi = 1;
				for (int k = 0; k <i / 2; k++) //10�� ����� �������ֱ� ���� �ݺ���
				{
					multi *= 10;
				}
				arr2[20 + i - num1] *= multi; //2���� ���� ���� �� ù��°��ҿ� multi�� ������
				arr2[20 + i - num1 + 1] *= multi; //2���� ���� ���� �� �ι�°��ҿ� multi�� ������
			}

			for (int i = 0; i < 20; i++) { //��� ������ ���� ������
				result += arr2[i];
			}
			cout << result << endl;
			break;
		}
		else if (num1 % 2 == 1) {
			cout << "error" << endl;
			break;
		}

	}
	fin.close(); //���� �ݱ�
	return 0;
}