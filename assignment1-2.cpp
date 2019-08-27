#include <iostream> //헤더파일 선언
#include <ctime> //srand를 위한 헤더파일 선언
#include <cstdlib> //rand를 위한 헤더파일 선언
using namespace std;

int main() //main함수의 시작
{
	int num, i, j;
	int arr[100]; //random으로 출력 될 숫자가 저장되는 배열 arr
	int arr_count[20] = { 0 }; //중복 된 숫자가 따로 저장되는 배열 arr_count

	srand((unsigned)time(NULL));
	cout << "Input N : ";
	cin >> num; //랜덤으로 몇개의 숫자가 출력될 지를 정함.
	if (num < 1 || num>20) {
		cout << "error!" << endl;
		return 0;
	}
	cout << "random number:";
	for (i = 0; i < num; i++) { //0부터 num이 입력한 숫자 만큼 반복해서 arr안에 랜덤으로 숫자가 들어갈 수 있도록 하는 반복문
		arr[i] = rand() % 20 + 1; //arr의 i번째 순서에 랜덤 숫자를 넣어줌
		cout << arr[i] << ' '; //저장된 숫자를 출력
	}

	cout << endl;

	for (i = 0; i < num; i++) { //arr에 저장된 값들을 정렬하기 위한 2중 반복문
		for (j = i + 1; j < num; j++) {
			if (arr[i] == arr[j]) { //배열의 i값과 그다음 값이 같을 때 arr_count에 값을 추가하는 if문
				arr_count[i]++;
				arr[j] = 0; //arr[j]를 초기화
			}
		}
	}
	for (i = 0; i < num; i++) { //arr_count에 추가된 숫자들을 큰 순서대로 정렬해주는 2중 반복문
		for (j = 0; j < num - 1; j++) {
			if (arr_count[j] < arr_count[j + 1]) { //arr_count에 j번째와 j+1번째를 비교했을 때 j+1이 더 크면 큰순서대로 정렬하는 if문
				int tmp = arr_count[j];
				arr_count[j] = arr_count[j + 1];
				arr_count[j + 1] = tmp;

				int tmp2 = arr[j]; //arr_count를 비교함과 동시에, arr안의 요소들도 같이 변경
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp2;
			}
		}
	}
	for (i = 0; i < num; i++) { //arr_count가 같을 때 같은 수만큼 정렬된 것 끼리 큰 순서대로 정렬하는 2중 반복문
		for (j = 0; j < num - 1; j++) {
			if (arr_count[j] == arr_count[j + 1]) {
				if (arr[j] < arr[j + 1]) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}

	for (i = 0; i < num; i++) { //정렬이 끝난 arr와 arr_count 를 출력해주기 위한 반복문
		if (arr[i] != 0) {
			cout << arr[i] << '-' << arr_count[i] + 1 << endl;
		}
	}
	return 0;
}