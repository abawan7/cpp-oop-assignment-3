#include <iostream>
#include <string>
using namespace std;

class MyString
{
public:
	MyString(int);
	void setter(int);
	int length();
	void Upper_case();
	void Lower_case();
	void Display();
	char Index(int);
	char Substring(char*, int,int);
	int Startindex(char*);
	~MyString();

private:
	char* str;
};

MyString::MyString(int size)
{
	str = new char[size];
}

void MyString::setter(int size) {
	cout << "Enter String: ";
	cin.getline(str, size);
}

int MyString::length() {
	int size = strlen(str);
	return size;
}

void MyString::Upper_case() {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
			cout << str[i];
		}
		else {
			cout << str[i];
		}
	}
}

void MyString::Lower_case() {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
			cout << str[i];
		}
		else {
			cout << str[i];
		}
	}

}

char MyString::Index(int index) {
	char c;
	c = str[index - 1];
	return c;
}

char MyString::Substring(char *substr, int start, int end) {
	for (int i = start-1; i <= end-1; i++) {
		substr[i] = str[i];
		cout << substr[i];
	}
	return *substr;
}

int MyString::Startindex(char*substr) {
	int count = 0;
	
}

void MyString::Display() {
	for (int i = 0; i < strlen(str); i++) {
		cout << str[i];
	}
}



MyString::~MyString()
{
}

int main() {
	char* substr;
	int index, start, end;
	string str;
	MyString S1(50);
	S1.setter(50);
	cout << "The Length of the String is:   " << S1.length() << endl;

	cout << "\n--------------------------" << endl;
	cout << "The String in Upper Case is: ";
	S1.Upper_case();

	cout << "\n--------------------------" << endl;
	cout << "\nThe String in Lower Case is: ";
	S1.Lower_case();

	cout << "\n--------------------------" << endl;
	cout << "Enter Index:   ";
	cin >> index;
	cout << "The Character On the given Index Is: " << S1.Index(index) << endl;

	cout << "\n--------------------------" << endl;
	cout << "Enter Start Index:   ";
	cin >> start;
	cout << "Enter End Index:   ";
	cin >> end;
	substr = new char[end];
	S1.Substring(substr,start,end);
}