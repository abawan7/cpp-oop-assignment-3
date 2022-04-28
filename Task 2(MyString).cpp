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
	char Substring(char*&, int, int);
	int Startindex(char*);
	MyString operator=(MyString&);
	MyString operator+(MyString&);
	friend bool operator == (MyString, MyString);
	friend bool operator != (MyString, MyString);
	friend int operator < (MyString, MyString);
	friend int operator > (MyString, MyString);
	~MyString();

private:
	char* str;
	int i;
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
	cout << endl;
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
	cout << endl;
}

char MyString::Index(int index) {
	char c;
	c = str[index - 1];
	return c;
}

char MyString::Substring(char*& substr, int start, int end) {
	i = start;
	for (int i = start - 1; i <= end - 1; i++) {
		substr[i] = str[i];
		cout << substr[i];
	}
	return *substr;
}

int MyString::Startindex(char* substr) {
	int index = i;
	return index;
}

MyString MyString::operator=(MyString& obj1)
{
	MyString temp(strlen(str));
	bool flag = true;
	if (strlen(str) == strlen(obj1.str)) {
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == obj1.str[i]) {
				continue;
			}
			flag = false;
		}
	}
	else {
		flag == false;
	}

	if (flag == true) {
		cout << "Object String are Equal" << endl;
	}
	else {
		cout << "Object String are not Equal " << endl;
	}
	return temp;
}

MyString MyString::operator+(MyString& obj1)
{
	int length = strlen(str) + strlen(obj1.str);
	MyString temp(length);
	temp.str = str;
	int j = 0;
	for (int i = strlen(str) + 1; i <= length; i++) {
		temp.str[i] = obj1.str[j];
		j++;
	}
	for (int i = 0; i <= length; i++) {
		cout << temp.str[i];
	}
	return temp;
}

bool operator== (MyString c1, MyString c2) {
	if (strlen(c1.str) == strlen(c2.str)) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!= (MyString c1, MyString c2) {
	if (strlen(c1.str) == strlen(c2.str)) {
		return false;
	}
	else {
		return true;
	}
}


int operator < (MyString c1, MyString c2) {
	if (strlen(c1.str) < strlen(c2.str)) {
		return 0;
	}
	else if (strlen(c1.str) > strlen(c2.str)) {
		return 1;
	}
	else {
		return 2;
	}
}

int operator > (MyString c1, MyString c2) {
	if (strlen(c1.str) > strlen(c2.str)) {
		return 0;
	}
	else if (strlen(c1.str) < strlen(c2.str)) {
		return 1;
	}
	else {
		return 2;
	}
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
	int x;
	bool flag;
	char* substr;
	int index, start, end, i;
	string str;
	MyString S1(50), S2(50), temp(50);
	S1.setter(50);
	cout << "The Length of the String 1 is:   " << S1.length() << endl;
	S2.setter(50);
	cout << "The Length of the String 2 is:   " << S2.length() << endl;

	cout << "\n--------------------------" << endl;
	cout << "The String 1 in Upper Case is: ";
	S1.Upper_case();
	cout << "The String 2 in Upper Case is: ";
	S2.Upper_case();

	cout << "\n--------------------------" << endl;
	cout << "\nThe String in Lower Case is: ";
	S1.Lower_case();
	cout << "\nThe String in Lower Case is: ";
	S2.Lower_case();

	cout << "\n--------------------------" << endl;
	cout << "Enter Index:   ";
	cin >> index;
	cout << "The Character On the given Index In String 1: " << S1.Index(index) << endl;
	cout << "The Character On the given Index In String 2: " << S2.Index(index) << endl;

	cout << "\n--------------------------" << endl;
	cout << "Enter Start Index String 1:   ";
	cin >> start;
	cout << "Enter End Index of String 1:   ";
	cin >> end;
	substr = new char[end];
	cout << "String 1 Substring: ";
	S1.Substring(substr, start, end);
	cout << "\nString 2 Substring: ";
	S2.Substring(substr, start, end);

	cout << "\n--------------------------" << endl;
	cout << "Starting Index of a Substring:   " << S1.Startindex(substr) << endl;

	cout << "\n--------------------------" << endl;
	cout << "Comparing Object Strings" << endl;
	S1 = S2;

	cout << "\n--------------------------" << endl;
	cout << "Adding Object Strings" << endl;
	S1 + S2;


	cout << "\n--------------------------" << endl;
	flag = operator == (S1, S2);
	if (flag == false) {
		cout << "Object 1 is Not Equal to Object 2: \t" << "False" << endl;
	}
	else {
		cout << "Object 1 is Equal to Object 2: \t" << "True" << endl;
	}

	cout << "-----------------------" << endl << endl;
	flag = operator != (S1, S2);
	if (flag == true) {
		cout << "Object 1 is Not Equal to Object 2: \t" << "True" << endl;
	}
	else {
		cout << "Object 1 is Equal to Object 2: \t" << "False" << endl;
	}

	cout << "-----------------------" << endl << endl;
	x = operator < (S1, S2);
	if (x == 0) {
		cout << "Object 1 is Less Than Object 2: \t" << "True" << endl;
	}
	else if (x == 1) {
		cout << "Object 1 is not Less Than Object 2: \t" << "False" << endl;
	}
	else if (x == 2) {
		cout << "It is neither Greater nor Less: \t" << "Equal" << endl;
	}

	cout << "-----------------------" << endl << endl;
	x = operator > (S1, S2);
	if (x == 0) {
		cout << "Object 1 is Greater Than Object 2: \t" << "True" << endl;
	}
	else if (x == 1) {
		cout << "Object 1 is Not Greater Than Object 2: \t" << "False" << endl;
	}
	else if (x == 2) {
		cout << "It is neither Greater nor Less: \t" << "Equal" << endl;
	}
}