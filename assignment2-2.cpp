#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int my_len(char *str1) { //배열의 길이를 계산하는 함수
	int count = 0;
	for (int i = 0; i < 100; i++) {
		count++;
		if (str1[i] == NULL) { //배열의 끝을 만났을 때 변수에 저장된 값을 반환
			return count;
		}
	}
}
char *my_cpy(char *str2, char *str1) { //배열의 요소를 복사하는 함수
	for (int i = 0; i < my_len(str1); i++) {
		str2[i] = str1[i];
		if (str1[i] == NULL) { //배열의 끝을 만났을 때 복사된 요소의 값을 반환
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

	fstream fin; //파일 스트림 객체 생성
	fin.open("input.txt"); //input.txt 파일을 염
	if (!fin) { //input 파일이 없을 때 출력
		cout << "파일을 읽을 수 없습니다!" << endl;
	}
	cout << "Output:" << endl;
	fin.getline(str1, 100); //파일 스트림의 요소를 불러들임 
	while (!fin.eof()) { //파일의 마지막일때 까지
		for (int i = 0; i < my_len(str1); i++) {
			cout << my_cpy(str2, str1) << "-" << my_len(str1) << endl; //문장의 요소 복사값과 길이값 출력
			count++;
			num += my_len(str1);
			temp = my_len(str1);
			if (temp > longestline) { //temp를 선언함으로써 길이가 가장 긴 문장이 나오면 longestline을 변경
				longestline = temp;
				line = count;
			}
			fin.getline(str1, 100);
		}



		cout << "The average length is " << (double)num / (double)count << endl; //평균길이 계산
		cout << "The longest line is line " << line << endl; //가장 긴 문장 출력
		return 0;
	}
}