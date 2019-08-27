#include <iostream>
using namespace std;

int CalcLength(char *str) //str 의 길이를 계산하는 함수
{
	int len;
	for (len = 0; str[len] != NULL; len++) {
		return len;
	}
}
bool CompareString(const char *str1, const char *str2) //str1과 str2 두개의 문장을 비교하는 함수
{
	for (int i = 0; i < 65; i++) {
		if (str1[i] != str2[i]) { //두개의 요소 값이 다르면 false 를 반환
			return false;
		}
		return true;
	}
}
bool CompareWord(char *str1, char *str2) //대소문자 관계없이 문장 내용이 같으면 같음을 알려주는 함수
{
	for (int i = 0; i < 65; i++) { //소문자일 때 대문자로 바꿔주는 반복문
		if (96 < str1[i] && 123 > str1[i]) {
			str1[i] -= 32;
		}
		if (96 < str2[i] && 123 > str2[i]) {
			str2[i] -= 32;

		}
		if (str1[i] != str2[i]) { //소문자에서 대문자로 변한 값이 다르면 false를 반환
			return false;
		}
	}
	return true;
}

int main()
{
	char str1[65] = { NULL }, str2[65] = { NULL }; //str1과 str2를 초기화
	int len1, len2;

	cout << "str1:";
	cin.getline(str1, 65);
	cout << "str2:";
	cin.getline(str2, 65);

	while (1) {
		if (CompareWord(str1, str2) == false) { //대소문자 관계없이 문자열이 다르면 different임을 출력
			cout << "They are different" << endl;
			break;
		}
		else if (CompareWord(str1, str2) == true) { //대소문자 관계없이 문자열 같으면 equal임을 출력
			cout << "They are equal" << endl;
			break;
		}
		if (CompareString(str1, str2) == false) { //문자열 길이를 비교했을 때 길이가 다르면 different임을 출력
			cout << "They are different" << endl;
			break;
		}
		else if (CompareString(str1, str2) == true) { //문자열 길이를 비교했을 때 길이가 다르면 equal임을 출력
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