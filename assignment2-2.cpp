#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int my_len(char *str1) { //�迭�� ���̸� ����ϴ� �Լ�
	int count = 0;
	for (int i = 0; i < 100; i++) {
		count++;
		if (str1[i] == NULL) { //�迭�� ���� ������ �� ������ ����� ���� ��ȯ
			return count;
		}
	}
}
char *my_cpy(char *str2, char *str1) { //�迭�� ��Ҹ� �����ϴ� �Լ�
	for (int i = 0; i < my_len(str1); i++) {
		str2[i] = str1[i];
		if (str1[i] == NULL) { //�迭�� ���� ������ �� ����� ����� ���� ��ȯ
			return str2;
		}
	}
}
int main()
{
	char *str1 = new char[100];
	char *str2 = new char[100];
	char *str3 = new char[100];
	int num = 0;
	int count = 0;

	int temp = 0;
	int longestline = 0;
	int line = 0;

	fstream fin; //���� ��Ʈ�� ��ü ����
	fin.open("input.txt"); //input.txt ������ ��
	if (!fin) { //input ������ ���� �� ���
		cout << "������ ���� �� �����ϴ�!" << endl;
	}
	cout << "Output:" << endl;
	fin.getline(str1, 100); //���� ��Ʈ���� ��Ҹ� �ҷ����� 
	while (!fin.eof()) { //������ �������϶� ����
		for (int i = 0; i < my_len(str1); i++) {
			cout << my_cpy(str2, str1) << "-" << my_len(str1) << endl; //������ ��� ���簪�� ���̰� ���
			count++;
			num += my_len(str1);
			temp = my_len(str1);
			if (temp > longestline) { //temp�� ���������ν� ���̰� ���� �� ������ ������ longestline�� ����
				longestline = temp;
				line = count;
			}
			fin.getline(str1, 100);
		}



		cout << "The average length is " << (double)num / (double)count << endl; //��ձ��� ���
		cout << "The longest line is line " << line << endl; //���� �� ���� ���
		return 0;
	}
}