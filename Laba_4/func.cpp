﻿#include "header.h"



int Numeral_16::turnDecimal() {
	int decimal = stoi(hexadecimal, nullptr, 16);
	return decimal;
};


string Numeral_16::turnHexa(long n) {
	string hexa;
	while (n != 0) {
		int rem = n % 16;
		if (rem < 10)
			hexa.insert(0, 1, '0' + rem);
		else
			hexa.insert(0, 1, 'A' + rem - 10);
		n /= 16;
	};

	return hexa;
}


Numeral_16 Numeral_16::inc() {
	int decimal = turnDecimal();
	decimal++;
	hexadecimal = turnHexa(decimal);
	return *this;
};


Numeral_16 Numeral_16::sum(Numeral_16& other) {
	int decimal1 = turnDecimal();
	int decimal2 = other.turnDecimal();
	int suma = decimal1 + decimal2;
	return Numeral_16(turnHexa(suma));
};


Numeral_16 Numeral_16::operator++() {
	return inc();
};


Numeral_16 Numeral_16::operator++(int) {
	Numeral_16 temp = *this;
	inc();
	return *this;
};


Numeral_16 Numeral_16::operator+(Numeral_16& other) {
	return sum(other);
};


Numeral_16 Numeral_16::operator+=(int other) {
	int decimal = turnDecimal();
	decimal += other;
	hexadecimal = turnHexa(decimal);
	return *this;
}