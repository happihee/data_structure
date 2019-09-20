#include "String.h"
#include<iostream>
using namespace std;

int my_len(char *str1) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		count++;
		if (str1[i] == NULL) {
			return count;
		}
	}
}

char *my_cpy(char *str2, char *str1) {
	for (int i = 0; i < my_len(str1); i++) {
		str2[i] = str1[i];
		if (str1[i] == NULL) {
			return str2;
		}
	}
}
int my_cmp(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL) {
		return -1;
	}
	for (; (*str1) != '\n' || (*str2) != '\n'; str1++, str2++) {
		if ((*str1) > (*str2)) return 1;
		if ((*str1) < (*str2)) return -1;
		if ((*str1) = (*str2)) return 0;
	}
	return 0;
}
char *my_tok(char *str1, char *delemeter) {
	static char * str2 = NULL;

	if (str1 != NULL) {
		str2 = new char[my_len(str1) + 1];
		my_cpy(str2, str1);
	}
	for (int i = 0; str2[i] != NULL; i++) {
		if (check_del(str2[i], delemeter)) { //첫 delemeter 를 찾음
			str2[i] = NULL; //delemeter 을 NULL로 만듬.
			for (int j = 1; str2[i + j] != NULL; j++) { //반복되는 del을 찾음
				if (!check_del(str2[i + j], delemeter)) { //반복되는 del 이 끝남 
					char *save = str2;
					str2 = &str2[i + j];
					return save;
				}
				else
					str2[i + j] = NULL;
			}
		}
	}
	char *save = str2;
	str2 = NULL;
	return save;
}

bool check_del(char ch, char *del) { //delemeter를 종류별로 check 하기 위해 
	for (int i = 0; del[i] != NULL; i++) {
		if (ch == del[i]) {
			return true;
		}
	}
	return false;
}
