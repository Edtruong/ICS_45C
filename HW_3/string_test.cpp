#include "String.h"
#include <iostream>
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
	String s1("String1");
	String s2("Success2");
	s1 = s2;
	cout << "\tAnswer: " << s1 << " --> Should be: 'Success2'" << endl;
	String s3("String3");
	String s4("Sucess4");
	s3 = s4;
	cout << "\tAnswer: " << s3 << " --> Should be: 'Success4'" << endl;
}
void test_index()
{
	cout << "Testing []" << endl;
	String s1("String");
	cout << "\t(1) The String is: " << s1 << endl;
	cout << "\tIndex 0: " << s1[0] << " --> Should be: 'S'" << "\tIndex 1: " << s1[1] << " --> Should be: 't'" << "\tIndex 2: " << s1[2] << " --> Should be: 'r'" << endl;
	String s2("Testing");
	cout << "\t(2) The String is: " << s2 << endl;
	cout << "\tIndex 0: " << s2[0] << " --> Should be: 'T'" << "\tIndex 1: " << s2[1] << " --> Should be: 'e'" << "\tIndex 2: " << s2[2] << " --> Should be: 's'" << endl;
	
}
void test_size()
{
	cout << "Testing size()" << endl;
	String s1("Hello");
	cout << "\t(1) The String is: " << s1 <<endl;
	cout << "\tSize: " << s1.size() << " --> Should be: 5" << endl;
	String s2("Anteater");
	cout << "\t(2) The String is: " << s2 <<endl;
	cout << "\tSize: " << s2.size() << " --> Should be: 8" << endl;
}
void test_reverse()
{
	cout << "Testing reverse()" << endl;
	String s1("Hello");
	cout << "\t(1) The String is: " << s1 <<endl;
	cout << "\tAnswer: " << s1.reverse() << " --> Should be: 'olleH'" << endl;
	String s2("Anteater");
	cout << "\t(2) The String is: " << s2 <<endl;
	cout << "\tAnswer: " << s2.reverse() << " --> Should be: 'retaetnA'" << endl;
}
void test_indexOf1()
{
	cout << "Testing indexOf(const char c)" << endl;
	String s1("Hello");
	cout << "\t(1) The String is: " << s1 << "; and testing index of 'e'" <<endl;
	cout << "\tAnswer: " << s1.indexOf("e") << " --> Should be: 1" << endl;
	String s2("Anteater");
	cout << "\t(2) The String is: " << s2 << "; and testing index of 't'" <<endl;
	cout << "\tAnswer: " << s2.indexOf("t") << " --> Should be: 2" << endl;
}
void test_indexOf2()
{
	cout << "Testing indexOf(const String pattern)" << endl;
	String s1("Hello");
	cout << "\t(1) The String is: " << s1 <<endl;
	cout << "\tAnswer: " << s1.indexOf("llo") << " --> Should be: 2" << endl;
	String s2("Anteater");
	cout << "\t(2) The String is: " << s2 <<endl;
	cout << "\tAnswer: " << s2.indexOf("eat") << " --> Should be: 3" << endl;
}
void test_eq()
{
	cout << "Testing ==" << endl;
	String s1("Hello");
	String s2("Hello");
	bool foo = s1 == s2;
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	if (foo)
		cout << "\tEqual" << endl;
	else
		cout << "\tNot equal" << endl;
	String s3("Anteater");
	String s4("Peter");
	bool foo1 = s3 == s4;
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	if (foo1)
		cout << "\tEqual" << endl;
	else
		cout << "\tNot equal" << endl;
}
void test_not_eq()
{
	cout << "Testing !=" << endl;
	String s1("Hello");
	String s2("Hello");
	bool foo = s1 != s2;
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	if (foo)
		cout << "\tNot equal" << endl;
	else
		cout << "\tEqual" << endl;
	String s3("Anteater");
	String s4("Peter");
	bool foo1 = s3 != s4;
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	if (foo1)
		cout << "\tNot equal" << endl;
	else
		cout << "\tEqual" << endl;
}
void test_gt()
{
	cout << "Testing >" << endl;
	String s1("abcdef");
	String s2("ABCDEF");
	bool foo = s1 > s2;
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	if (foo)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;
	String s3("JUSTIN");
	String s4("Justin");
	bool foo1 = s3 > s4;
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	if (foo1)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;
	String s5("same");
	String s6("same");
	bool foo2 = s5 > s6;
	cout << "\t(3) The String is: " << s5 << " and " << s6 << endl;
	if (foo2)
		cout << "\tSuccess" << endl;
	else
		cout << "\t Fail" << endl;
}
void test_lt()
{
	cout << "Testing <" << endl;
	String s1("HELLO");
	String s2("hello");
	bool foo = s1 < s2;
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	if (foo)
		cout << "\tSucccess" << endl;
	else
		cout << "\tFail" << endl;
	String s3("JUSTIN");
	String s4("Justin");
	bool foo1 = s3 < s4;
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	if (foo1)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;
	String s5("same");
	String s6("same");
	bool foo2 = s5 < s6;
	cout << "\t(3) The String is: " << s5 << " and " << s6 << endl;
	if (foo2)
		cout << "\tSuccess" << endl;
	else
		cout << "\t Fail" << endl;

}
void test_le()
{
	cout << "Testing <=" << endl;
	String s1("UCI");
	String s2("UCI");
	bool foo = s1 <= s2;
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	if (foo)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;
	String s3("uci");
	String s4("UCI");
	bool foo1 = s3 <= s4;
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	if (foo1)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;
	bool foo2 = s4 <= s3;
	cout << "\t(3) The String is: " << s3 << " and " << s4 << endl;
	if (foo2)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;

	
}
void test_ge()
{
	cout << "Testing >=" << endl;
	String s1("abcdef");
	String s2("ABCDEF");
	bool foo = s1 >= s2;
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	if (foo)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;
	String s3("JUSTIN");
	String s4("Justin");
	bool foo1 = s3 >= s4;
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	if (foo1)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;
	bool foo2 = s4 >= s3;
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	if (foo2)
		cout << "\tSuccess" << endl;
	else
		cout << "\tFail" << endl;

}
void test_cat1()
{
	cout << "Testing +" << endl;
	String s1("Hi");
	String s2("Hello");
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	cout << "\tAnswer: " << s1+s2 << " --> Should be 'HiHello'" << endl;
	String s3("Justin");
	String s4("Chung");
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	cout << "\t Answer: " << s3+s4<< " --> Should be 'JustinChung'" << endl;
}
void test_cat2()
{
	cout << "Testing +=" << endl;
	String s1("California");
	String s2("University");
	s2+=s1;
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	cout << "\tAnswer: " << s2 << " --> Should be 'UniversityCalifornia'" << endl;
	String s4("Test");
	String s5("Passed");
	cout << "\t(2) The String is: " << s4 << " and " << s5 << endl;
	s4+=s5;
	cout << "\tAnswer: " << s4 << " --> Should be 'TestPassed'" << endl;
}

int main()
{
	test_constructor_and_print();
	test_assign();
	test_index();
	test_size();
	test_reverse();
	test_indexOf1();
	test_indexOf2();
	test_eq();
	test_not_eq();
	test_gt();
	test_lt();
	test_le();
	test_ge();
	test_cat1();
	test_cat2();
	return 0;
}	
