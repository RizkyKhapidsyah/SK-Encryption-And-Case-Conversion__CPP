#pragma once
#include <iostream>

using namespace std;

class Filter {
public:
	void doFilter(fstream& in_stream, fstream& out_stream);

protected:
	virtual char transform(char ch) = 0;
};

class UpperCaseFilter : public Filter {

protected:

	char transform(char ch) {
		return islower(ch) ? (ch - 32) : ch;
	}
};

void Filter::doFilter(fstream& in, fstream& out) {
	char ch;
	while (in.get(ch)) {
		ch = transform(ch);
		out << ch;
	}
}

class EncryptionFilter : public Filter {
private:
	int encryptionkey;

protected:
	char transform(char ch) {
		return ch + encryptionkey;
	}

public:
	EncryptionFilter() {
		encryptionkey = 5;
	}
};