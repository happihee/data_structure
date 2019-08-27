#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#pragma warning(disable:4996) //strtok_s 를 strtok로 써주기 위해 사용

void Bubble(int * arr) { //오름차순으로 정렬하는 Bubble 함수
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
	ifstream fin; //파일 스트림 객체 생성
	fin.open("input.txt"); //input.txt 파일을 염
	if (!fin) { //input 파일이 없을 때 출력
		cout << "파일을 읽을 수 없습니다!" << endl;
	}
	while (!fin.eof()) { //파일이 끝이 아닐 때 까지 반복
		fin.getline(arr1, 100);
		token = strtok(arr1, " ");  //공백 기준으로 자름
		token = strtok(NULL, " ");
		num1 = atoi(token); //char 형 함수를 int형 함수로 변환하기 위해 사용
		if (num1<1 || num1>20) //num1이 1보다 작고 20보다 큰 수일 때 error 출력
		{
			cout << "error" << endl;
			break;
		}

		if (num1 % 2 == 0) { //num1 이 짝수일 때
			fin.getline(arr1, 100);
			token = strtok(arr1, " "); //공백 기준으로 자름
			token = strtok(NULL, " ");
			num2 = atoi(token);

			while (token != NULL) //token 값이 NULL이 아닐 때 num2안에 arr2 요소들을 추가
			{
				num2 = atoi(token);
				arr2[k] = num2;
				k++;
				token = strtok(NULL, " ");
			}

			if (num2 < 1 || num2 > 9) //num2 의 값을 1 이상 9이하로 제한
			{
				cout << "error" << endl;
				break;
			}
			if (k % 2 == 1) { //요소들이 짝수 개 일때만으로 제한
				cout << "error" << endl;
				break;
			}

			int countInput = 0;
			for (int z = 0; z < 20; z++) { //처음 입력한 num1 과 arr2에 들어가 있는 요소의 개수를 비교
				if (arr2[z] != 0)
					countInput++;
			}
			if (countInput != num1) {
				cout << "error!" << endl;
				return 0;
			}

			Bubble(arr2); //arr2를 정렬

			cout << "Output: ";

			for (int i = 0; i < num1; i += 2) //작은 숫자부터 2개씩 나눠야 하므로 i+=2
			{
				int multi = 1;
				for (int k = 0; k <i / 2; k++) //10의 배수를 적용해주기 위한 반복문
				{
					multi *= 10;
				}
				arr2[20 + i - num1] *= multi; //2개씩 나눈 값들 중 첫번째요소에 multi를 곱해줌
				arr2[20 + i - num1 + 1] *= multi; //2개씩 나눈 값들 중 두번째요소에 multi를 곱해줌
			}

			for (int i = 0; i < 20; i++) { //결과 값들을 전부 더해줌
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
	fin.close(); //파일 닫기
	return 0;
}