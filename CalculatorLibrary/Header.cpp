#include "Header.h"
#include <string>
#define CALC_API extern "C" __declspec(dllexport)

using namespace std;

CALC_API double dAdd(double a, double b) {
	cout << a << "+" << b << "=" << a + b;
	return a + b;
}
CALC_API double dSubstrct(double a, double b) {
	cout << a << "-" << b << "=" << a - b;
	return a - b;
}
CALC_API double dMult(double a, double b) {
	cout << a << "*" << b << "=" << a * b;
	return a * b;
}
CALC_API double dDiv(double a, double b) {
	if (b != 0) {
		cout << a << "/" << b << "=" << a / b;
		return a / b;
	}
	cout << a << "/" << b << "=" << " ERROR";
	return -1;
}

CALC_API char chGetOperation(const char* str) {
	size_t length = strlen(str);
	for (int i = 0; i < length; i++) {
		switch (str[i]) {
			case '+': {	return '+'; }
			case '-': { return '-'; }
			case '/': { return '/'; }
			case '*': { return '*'; }
			default: { continue;}
		}
	}
	return ' ';
}

CALC_API double* dptrGetOperands(const char* str) {
	char chA[10], chB[10];
	string sA, sB;
	double operands[2];
	int i = 0, j=0;
	while (str[i] >= 48 && str[i] <= 57 || str[i] == '.') {
		chA[i] = str[i];
		i++;
	}
	chA[i] = '\0';
	i++;
	sA = chA;
	while (str[i] >= 48 && str[i] <= 57 || str[i] == '.') {
		chB[j] = str[i];
		j++;
		i++;
	}
	chB[j] = '\0';
	sB = chB;
	operands[0]=stod(sA);
	operands[1] = stod(sB);
	return operands;
}

CALC_API void CalcBody() {
	char operation = ' ';
	char expression[50]={};
	double* operands;

	while (true) {
		cout << "Enter expression:\t";
		cin >> expression;
		operation = chGetOperation(expression);
		operands = dptrGetOperands(expression);
		switch (operation) {
		case '+': {
			dAdd(operands[0], operands[1]);
			break;
		}
		case '-': {
			dSubstrct(operands[0], operands[1]);
			break;
		}
		case '*': {
			dMult(operands[0], operands[1]);
			break;
		}
		case '/': {
			dDiv(operands[0], operands[1]);
			break;
		}
		default: break;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
}