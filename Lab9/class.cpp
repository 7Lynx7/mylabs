#include <stdlib.h>
#include <iostream>


int pow(int o, int e) {
	if (e == 0) return 1;
	if (e == 1) return o;
	int a = o;
	for (int i = 1; i < e; i++)
		a *= o;
	return a;
}
int res[32] = { 0 };
void add(int i) {
	if (res[i]) {
		if (i > 0) {
			res[i] = 0;
			add(i - 1);
		}
	}
	else {
		res[i] = 1;
	}
}

void setBinForm(int a) {

	for (int i = 0; i < 32; i++)
		res[i] = 0;
	bool isNegative = false;
	if (a < 0) {
		isNegative = true;
		a *= -1;
	}
	int lres[32] = { 0 };
	int i = 0;
	while (a > 0) {
		lres[i] = a % 2;
		a = a / 2;
		i++;
	}
	//for (int i = 0; i < 32; i++)
	//	std::cout << lres[i];
	//std::cout << std::endl;
	int k = 31;
	for (int j = 0; j < i; j++) {
		res[k] = lres[j];
		k--;
	}
	if (isNegative) {
		for (int i = 0; i < 32; i++)
			res[i] ? res[i] = 0 : res[i] = 1;
		add(31);
	}
}

int getDecForm() {
	bool isNegative = false;
	if (res[0]) {
		isNegative = true;
		for (int i = 0; i < 32; i++) {
			res[i] ? res[i] = 0 : res[i] = 1;
		}
		add(31);
	}
	int a = 0;
	int j = 31;
	for (int i = 0; i < 32; i++) {
		a += res[j] * pow(2, i);
		j--;
	}
		
	return isNegative ? -a : a;

}

void showBin() {
	for (int i = 0; i < 32; i++)
		//i + 1 % 4 == 0 ? std::cout << res[i] << ' ' : std::cout << res[i];
		 std::cout << res[i];
	std::cout << std::endl;
}

void invert(int offset) {
	for (int i = 0; i < 32; i++) {
		if ((i + 1) % offset == 0)
		res[i] ? res[i] = 0 : res[i] = 1;
	}
}