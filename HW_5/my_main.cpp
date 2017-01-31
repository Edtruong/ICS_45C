#include <iostream>
#include "String.h"
using namespace std;

void test_constructor_and_print()
{
	cout << "Testing constuctor and print" << endl;
	String s1("Test 1");
	cout << "\tAnswer: " << s1 << " --> Should be: 'Test 1'" << endl;
	String s2("Test 2");
	cout << "\tAnswer: " << s1 << " --> Should be: 'Test 2'" << endl;
}
void test_assign()
{
	cout << "Testing =" << endl;
	String s1("Test1");
	String s2("Test2");
	s1 = s2;
	cout << "\tAnswer: " << s1 << " --> Should be: 'Test2'" << endl;
	String s3("Test3");
	String s4("Test4");
	s3 = s4;
	cout << "\tAnswer: " << s3 << " --> Should be: 'Test4'" << endl;
}
void test_index()
{
	cout << "Testing []" << endl;
	String s1("Test1");
	cout << "\t(1) The String is: " << s1 << endl;
	cout << "\tIndex 0: " << s1[0] << " --> Should be: 'T'" << "\tIndex 1: " << s1[1] << " --> Should be: 'e'" << "\tIndex 2: " << s1[2] << " --> Should be: 's'" << endl;
	String s2("Test2");
	cout << "\t(2) The String is: " << s2 << endl;
	cout << "\tIndex 0: " << s2[0] << " --> Should be: 'T'" << "\tIndex 3: " << s2[3] << " --> Should be: 't'" << "\tIndex 4: " << s2[4] << " --> Should be: '2'" << endl;
}
void test_length()
{
	cout << "Testing lenth()" << endl;
	String s1("Test1");
	cout << "\t(1) The String is: " << s1 << endl;
	cout << "\tLength: " << s1.length() << " --> Should be: 5" << endl;
	String s2("Testing2");
	cout << "\t(2) The String is: " << s2 << endl;
	cout << "\tLength: " << s2.length() << " --> Should be: 8" << endl;
}
void test_indexOf()
{
	cout << "Testing indexOf(char)" << endl;
	String s1("First");
	cout << "\t(1) The String is: " << s1 << endl;
	cout << "\tIndex of \"i\": " << s1.indexOf('i') << " --> Should be: 1" << endl;
	String s2("Second");
	cout<< "\t(2) The String is: " << s2 << endl;
	cout << "\tIndex of \"o\": " << s2.indexOf('o') << " --> Should be: 3" << endl;
}
void test_eq()
{
	cout << "Testing ==" << endl;
	String s1("First");
	String s2("Second");
	String s3(s1);
	cout << "\t(1) Testing: " << s1 << " == " << s2 << endl;
	cout << "\tAnswer: " << (s1 == s2) << " --> Should be: 0" << endl;
	cout << "\t(2) Testing: " << s1 << " == " << s3 << endl;
	cout << "\tAnswer: " << (s1 == s3) << " --> Should be: 1" << endl;
}
void test_lt()
{
	cout << "Testing <" << endl;
	String s1("justin");
	String s2("JUSTIN");
	cout << "\t(1) Testing: " << s1 << " < " << s2 << endl;
	cout << "\tAnswer: " << (s1 < s2) << " --> Should be: 0" << endl;
	cout << "\t(2) Testing: " << s2 << " < " << s1 << endl;
	cout << "\tAnswer: " << (s2 < s1) << " --> Should be: 1" << endl;
}
void test_cat1()
{
	cout << "Testing +" << endl;
	String s1("Hi");
	String s2("Hello");
	cout << "\t(1) Testing: " << s1 << " + " << s2 << endl;
	cout << "\tAnswer: " << s1+s2 << " --> Should be 'HiHello'" << endl;
	String s3("Justin");
	String s4("Chung");
	cout << "\t(2) Testing: " << s3 << " + " << s4 << endl;
	cout << "\t Answer: " << s3+s4<< " --> Should be 'JustinChung'" << endl;
}
void test_cat2()
{
	cout << "Testing +=" << endl;
	String s1("California");
	String s2("University");
	cout << "\t(1) Testing: " << s1 << " += " << s2 << endl;
	cout << "\tAnswer: " << (s1+=s2) << " --> Should be 'CaliforniaUniversity'" << endl;
	String s3("Test");
	String s4("Passed");
	cout << "\t(2) Testing: " << s3 << " += " << s4 << endl;
	cout << "\tAnswer: " << (s3+=s4) << " --> Should be 'TestPassed'" << endl;
}

int main()
{
	test_constructor_and_print();
	test_assign();
	test_index();
	test_length();
	test_indexOf();
	test_eq();
	test_lt();
	test_cat1();
	test_cat2();
	return 0;
}
