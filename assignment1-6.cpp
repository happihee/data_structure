#include <iostream>
using namespace std;

int main()
{
	long long int arr[51] = { 0 };
	int j, i;
	int C = 0, n = 0;
	cout << "input:";
	cin >> C; //총 몇개를 확인할지 입력

	for (j = 0; j < C; j++) { //입력한 수 만큼 반복
		cout << "n =";
		cin >> n;
		for (i = 2; i < 51; i++) { //피보나치 수열을 실행하기 위한 반복문
			arr[0] = 1;
			arr[1] = 1;
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		if (n > 50 || n < 1) { //n의 값을 1이상 50이하로 고정
			cout << "input again!" << endl;
			//확인할 수 있는 숫자를 늘림
			continue;
		}
		cout << "-> output :" << arr[n] % 1000 << endl; //결과 값 출력
	}
	return 0;
}
