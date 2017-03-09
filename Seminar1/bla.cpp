//
// Created by Sorin Sebastian Mircea on 07/03/2017.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int aranjamente(int, int);
void main(void)
{
	int n, k;
	cin >> n >> k;
	cout << "\n"<< aranjamente(n, k);
}

int aranjamente(int n, int k)
{
	if (k == 0)
		return 1;
	return (n-k+1)*aranjamente(n, k - 1);
}