#include <iostream> //헤더파일 선언
#include <ctime>
#include <cstdlib>
using namespace std;

int turn = 0;
void InputUserNum(int *num) //user의 숫자를 입력하는 함수
{
	int i;

	while (1) {
		int check = 0; //이미 입력한 숫자를 판별하기 위한 변수

		cout << "Call a number(1~25) : ";
		int input;
		cin >> input; //찾을 빙고 숫자를 입력

		if (input < 1 || input>25) { //input이 1보다 작거나, 25보다 크면 재입력 하도록 함.
			cout << "input again !" << endl;
			continue;
		}
		else {
			for (int i = 0; i < 25; i++) {
				if (num[i] == input) { //입력한 숫자가 한번 더 입력되지 않도록 중복 체크하는 반복문
					check++;
				}
			}
		}

		if (check != 0) { //만약 num[i]의 요소와 input이 같아 check에 ++이 되면 재 입력을 하도록 하는 if문
			cout << "this number is already input. input again!" << endl;
		}
		else {
			num[turn++] = input; //배열 num에 입력한 값을 저장하도록 함
			break;
		}

	}

}
void InputComNum(int *num) //computer의 숫자를 입력하는 함수
{
	srand((unsigned)time(NULL));

	while (1) {
		int check = 0;
		cout << "Computer calls: ";
		int input;
		input = rand() % 25 + 1; //1~25까지의 숫자를 랜덤으로 호출

		for (int i = 0; i < 25; i++) {
			if (num[i] == input) //입력한 숫자가 한번 더 입력되지 않도록 중복 체크하는 반복문
			{
				check++;
			}
		}

		if (check != 0) { //만약 num[i]의 요소와 input이 같아 check에 ++이 되면 재 입력을 하도록 하는 if문
			cout << input << "this number is already input. input again!" << endl;
		}
		else {
			cout << input << endl;
			num[turn++] = input;//배열 num에 computer가 부른 랜덤 input 값을 저장하도록 함
			break;
		}
	}
	cout << endl;
}
void CheckExistNum(int(*arr)[5]) //빙고판에 숫자가 생성될 때 중복없이 생성되도록 만드는 함수
{
	int Max_temp[25];
	int i, j, temp1, temp2, count;
	int SaveArray[50];
	count = 0;

	for (i = 0; i < 25; i++) {
		Max_temp[i] = i + 1; //Max_temp 배열을 1 부터 25로 초기화
	}
	for (i = 0; i < 5; i++) { //각 배열에 해당되는 칸을 차례로 0으로 초기화
		for (j = 0; j < 5; j++) {
			arr[i][j] = 0;
		}
	}
	while (count != 25) { //count가 25가 되기 전까지 반복
		temp1 = rand() % 5;
		temp2 = rand() % 5;
		if (arr[temp1][temp2] == 0) { //배열의 해당하는 칸인 temp1 과 temp2를 랜덤으로 잡고 Max_temp의 값을 넣어줌
			arr[temp1][temp2] = Max_temp[count];
			count++;
		}
		else {
			temp1 = rand() % 5;
			temp2 = rand() % 5;
		}
	}
}

void MakeArray(int(*arr)[5]) // 5X5 랜덤 빙고판을 생성하는 함수
{
	int i, j;
	CheckExistNum(arr); //중복되는 숫자가 없도록 생성.
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void FindSameNum(int(*arr)[5], int *num) //똑같은 숫자를 찾아, 그 숫자를 '#' 이라는 문자로 변경시켜주는 함수
{
	int i, j;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 25; k++) {
				if (num[k] == arr[i][j]) //num 배열안의 값과 arr 배열안의 값이 같으면 그값을 -1로 변경
					arr[i][j] = -1;
			}
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == -1) //-1로 변경된 값을 #로 다시 바꿔줌
				cout << '#' << ' ';
			else
				cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
int FindUserBingo(int(*arr)[5]) //User의 Bingo 여부를 판단하여, User가 Bingo면 "User BINGO!"를 출력하도록 하는 함수
{
	int i, j, cnt1 = 0, cnt2 = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == -1) { //가로 빙고 판정 
				cnt1++;
			}
			if (arr[j][i] == -1) { //세로 빙고 판정
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

int FindComBingo(int(*arr)[5]) // Com의 Bingo 여부를 판단하여, Com이 Bingo면 "Com BINGO!"를 출력하도록 하는 함수
{
	int i, j, cnt1 = 0, cnt2 = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[i][j] == -1) { //가로 빙고 판정
				cnt1++;
			}
			if (arr[j][i] == -1) { //세로 빙고 판정
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
	MakeArray(user); //user의 5X5 랜덤 함수 생성
	cout << endl;
	cout << "<computer bingo board>" << endl;
	MakeArray(com); //com의 5X5 랜덤 함수 생성
	cout << endl;

	while (1)
	{
		InputUserNum(exist_num); //user가 숫자 입력

		cout << "<user bingo board>" << endl;
		FindSameNum(user, exist_num); //같은 num을 찾아 #으로 바꿔주는 함수
		cout << "<computer bingo board>" << endl;
		FindSameNum(com, exist_num); //같은 num을 찾아 #으로 바꿔주는 함수
		cout << endl;

		if (FindUserBingo(user) == 1) { //user가 빙고 혹은 com도 동시에 빙고일 때 빙고임을 출력

			if (FindComBingo(com) == 1)
			{
				return 1;
			}
			return 1;
		}
		if (FindComBingo(com) == 1) { //com이 빙고임을 출력
			return 1;
		}

		InputComNum(exist_num); //com의 숫자 입력

		cout << "<user bingo board>" << endl;
		FindSameNum(user, exist_num); //같은 num을 찾아 #으로 바꿔주는 함수
		cout << "<computer bingo board>" << endl;
		FindSameNum(com, exist_num); //같은 num을 찾아 #으로 바꿔주는 함수

		if (FindUserBingo(user) == 1) { //user가 빙고 혹은 com도 동시에 빙고일 때 빙고임을 출력

			if (FindComBingo(com) == 1)
			{
				return 1;
			}
			return 1;
		}
		if (FindComBingo(com) == 1) { //com이 빙고임을 출력
			return 1;
		}

	}
	return 0;
	
}
