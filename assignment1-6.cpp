#include <iostream>
using namespace std;

int main()
{
	long long int arr[51] = { 0 };
	int j, i;
	int C = 0, n = 0;
	cout << "input:";
	cin >> C; //�� ��� Ȯ������ �Է�

	for (j = 0; j < C; j++) { //�Է��� �� ��ŭ �ݺ�
		cout << "n =";
		cin >> n;
		for (i = 2; i < 51; i++) { //�Ǻ���ġ ������ �����ϱ� ���� �ݺ���
			arr[0] = 1;
			arr[1] = 1;
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		if (n > 50 || n < 1) { //n�� ���� 1�̻� 50���Ϸ� ����
			cout << "input again!" << endl;
			//Ȯ���� �� �ִ� ���ڸ� �ø�
			continue;
		}
		cout << "-> output :" << arr[n] % 1000 << endl; //��� �� ���
	}
	return 0;
}
