#include <iostream>
using namespace std;

int CalcLength(char *str) //str �� ���̸� ����ϴ� �Լ�
{
	int len;
	for (len = 0; str[len] != NULL; len++) {
		return len;
	}
}
bool CompareString(const char *str1, const char *str2) //str1�� str2 �ΰ��� ������ ���ϴ� �Լ�
{
	for (int i = 0; i < 65; i++) {
		if (str1[i] != str2[i]) { //�ΰ��� ��� ���� �ٸ��� false �� ��ȯ
			return false;
		}
		return true;
	}
}
bool CompareWord(char *str1, char *str2) //��ҹ��� ������� ���� ������ ������ ������ �˷��ִ� �Լ�
{
	for (int i = 0; i < 65; i++) { //�ҹ����� �� �빮�ڷ� �ٲ��ִ� �ݺ���
		if (96 < str1[i] && 123 > str1[i]) {
			str1[i] -= 32;
		}
		if (96 < str2[i] && 123 > str2[i]) {
			str2[i] -= 32;

		}
		if (str1[i] != str2[i]) { //�ҹ��ڿ��� �빮�ڷ� ���� ���� �ٸ��� false�� ��ȯ
			return false;
		}
	}
	return true;
}

int main()
{
	char str1[65] = { NULL }, str2[65] = { NULL }; //str1�� str2�� �ʱ�ȭ
	int len1, len2;

	cout << "str1:";
	cin.getline(str1, 65);
	cout << "str2:";
	cin.getline(str2, 65);

	while (1) {
		if (CompareWord(str1, str2) == false) { //��ҹ��� ������� ���ڿ��� �ٸ��� different���� ���
			cout << "They are different" << endl;
			break;
		}
		else if (CompareWord(str1, str2) == true) { //��ҹ��� ������� ���ڿ� ������ equal���� ���
			cout << "They are equal" << endl;
			break;
		}
		if (CompareString(str1, str2) == false) { //���ڿ� ���̸� ������ �� ���̰� �ٸ��� different���� ���
			cout << "They are different" << endl;
			break;
		}
		else if (CompareString(str1, str2) == true) { //���ڿ� ���̸� ������ �� ���̰� �ٸ��� equal���� ���
			if (CalcLength(str1) != CalcLength(str2)) {
				cout << "They are different" << endl;
				break;
			}
			cout << "They are equal" << endl;
			break;
		}
	}
	return 0;
}