#include <iostream> //������� ����
#include <ctime> //srand�� ���� ������� ����
#include <cstdlib> //rand�� ���� ������� ����
using namespace std;

int main() //main�Լ��� ����
{
	int num, i, j;
	int arr[100]; //random���� ��� �� ���ڰ� ����Ǵ� �迭 arr
	int arr_count[20] = { 0 }; //�ߺ� �� ���ڰ� ���� ����Ǵ� �迭 arr_count

	srand((unsigned)time(NULL));
	cout << "Input N : ";
	cin >> num; //�������� ��� ���ڰ� ��µ� ���� ����.
	if (num < 1 || num>20) {
		cout << "error!" << endl;
		return 0;
	}
	cout << "random number:";
	for (i = 0; i < num; i++) { //0���� num�� �Է��� ���� ��ŭ �ݺ��ؼ� arr�ȿ� �������� ���ڰ� �� �� �ֵ��� �ϴ� �ݺ���
		arr[i] = rand() % 20 + 1; //arr�� i��° ������ ���� ���ڸ� �־���
		cout << arr[i] << ' '; //����� ���ڸ� ���
	}

	cout << endl;

	for (i = 0; i < num; i++) { //arr�� ����� ������ �����ϱ� ���� 2�� �ݺ���
		for (j = i + 1; j < num; j++) {
			if (arr[i] == arr[j]) { //�迭�� i���� �״��� ���� ���� �� arr_count�� ���� �߰��ϴ� if��
				arr_count[i]++;
				arr[j] = 0; //arr[j]�� �ʱ�ȭ
			}
		}
	}
	for (i = 0; i < num; i++) { //arr_count�� �߰��� ���ڵ��� ū ������� �������ִ� 2�� �ݺ���
		for (j = 0; j < num - 1; j++) {
			if (arr_count[j] < arr_count[j + 1]) { //arr_count�� j��°�� j+1��°�� ������ �� j+1�� �� ũ�� ū������� �����ϴ� if��
				int tmp = arr_count[j];
				arr_count[j] = arr_count[j + 1];
				arr_count[j + 1] = tmp;

				int tmp2 = arr[j]; //arr_count�� ���԰� ���ÿ�, arr���� ��ҵ鵵 ���� ����
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp2;
			}
		}
	}
	for (i = 0; i < num; i++) { //arr_count�� ���� �� ���� ����ŭ ���ĵ� �� ���� ū ������� �����ϴ� 2�� �ݺ���
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

	for (i = 0; i < num; i++) { //������ ���� arr�� arr_count �� ������ֱ� ���� �ݺ���
		if (arr[i] != 0) {
			cout << arr[i] << '-' << arr_count[i] + 1 << endl;
		}
	}
	return 0;
}