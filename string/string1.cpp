#include <string.h>

#include <iostream>

using std::cout;
using std::endl;

class String {
public:
	String(const char* str = ""); // default constructor

	String(const String& copy); // copy constructor

	String& operator=(const String& assign); // assign constuctor

	~String(); // destructor
private:
	size_t m_size;
	char* m_data;
};

String::String(const char* str)
{
	cout << "String default constructor!" << endl;
	if (str == NULL) {
		m_data = new char[1];
		*m_data = '\0';
		m_size = 0;

	} else {
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
		m_size = length;
	}
}

String::String(const String& other)
{
	cout << "String copy constuctor!" << endl;
	size_t len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);
	m_size = len;
}

String& String::operator=(const String& other)
{
	cout << "String assign constructor!" << endl;
	if (this != &other) {
		char* temp = new char[strlen(other.m_data) + 1];
		strcpy(temp, other.m_data);

		delete[] m_data;
		m_data =temp;
		m_size = strlen(other.m_data);
	}
	return *this;
}

String::~String(void)
{
	delete[] m_data;
}

int main(int argc, char* argv[])
{
	String a;

	cout << "===================" << endl;

	String b("Hello, ");

	cout << "===================" << endl;

	String c = "World!";

	cout << "===================" << endl;

	//String d = b;
	String d(b);

	cout << "===================" << endl;

	a = c;

	cout << "===================" << endl;
}