#include <iostream>

using namespace std;

bool Prime(int);

int main()
{
	double sum = 0;
	int j = 0;
	for (int i = 2; i < 100; i++ ){
		if (Prime(i)) {
			j++;
			sum += i;
		}
	}
	cout << sum / j;
	return 0;
}

bool Prime(int a)
{
	for (int i = 2; i <= a / 2; i++) {
		if (a % i == 0)return false;
	}
	return true;
}
