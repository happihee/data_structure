#include <iostream> //헤더파일 선언
using namespace std;

int main()
{
	int num = 0;
	int i, j, k, x;

	cout << "input number:";
	cin >> num;
	x = num / 2;

	while (1) {
		if (num % 2 == 0) { // 입력한 숫자가 짝수 일 때
			cout << "error!";
			break; //반복문을 끝냄. 
		}
		for (i = 0; i <= x + 1; i++) { //입력한 수를 0부터 입력한 수를 반으로 나눈 값에서 1을 더한만큼 반복 ( 다이아몬드의 1사분면과 2사분면 )
			for (j = 0; j <= x - i; j++) {  //공백 출력을 위한 반복문 
				cout << " "; //공백 출력
			}
			for (j = 0; j < i - 1; j++) { //다이아몬드의 1사분면으로, 0부터 차례로 x를 반으로 나눈 값에서 1을 뺀 부분이 증가하는 것을 표현하기 위해 범위설정을 함.
				cout << j;
			}
			for (k = i - 1; k >= 0; k--) { //다이아몬드의 2사분면으로, i에서 -1을 뺀 값에서 0까지 숫자를 감소시키면서 k 값을 출력하도록 함.
				cout << k;
			}
			cout << endl;
		}
		for (i = x; i > 0; i--) { //입력한 수를 반으로 나눈 값부터 차례로 줄어들어 0보다 클 때까지 반복 ( 다이아몬드의 3사분면과 4사분면 )
			for (j = 0; j <= x - i; j++) { //공백 출력을 위한 반복문
				cout << " ";
			}
			for (j = 0; j < i - 1; j++) {//다이아몬드의 3사분면으로 0부터 i-1까지 j값을 출력하도록 함.
				cout << j;
			}
			for (k = i - 1; k >= 0; k--) {//다이아몬드의 4사분면으로 i-1부터 0까지 숫자를 감소시키면서 k값을 출력하도록 함.
				cout << k;
			}
			cout << endl;
		}
		break; //위 반복문들을 모두 거치면 반복문을 끝냄
	}
	return 0;
	
}
