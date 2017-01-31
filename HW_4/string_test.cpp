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
	cout << "\tIndex 0: " << s2[0] << " --> Should be: 'T'" << "\tIndex 3: " << s2[3] << " --> Should be: 't'" << "\tIndex 4: " << s2[4] << " --> Should be: 's'" << endl;
	
}
void test_size()
{
	cout << "Testing size()" << endl;
	String s1("Test1");
	cout << "\t(1) The String is: " << s1 <<endl;
	cout << "\tSize: " << s1.size() << " --> Should be: 5" << endl;
	String s2("Testing2");
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
	cout << "Testing indexOf(char)" << endl;
	String s1("Hello");
	cout << "\t(1) The String is: " << s1 << "; and testing index of 'e'" <<endl;
	cout << "\tAnswer: " << s1.indexOf("e") << " --> Should be: 1" << endl;
	String s2("Anteater");
	cout << "\t(2) The String is: " << s2 << "; and testing index of 't'" <<endl;
	cout << "\tAnswer: " << s2.indexOf("t") << " --> Should be: 2" << endl;
}
void test_indexOf2()
{
	cout << "Testing indexOf(String)" << endl;
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
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	cout << "\tAnswer: " << (s1 == s2) << " --> Should be: 1" << endl;
	String s3("Anteater");
	String s4("Peter");
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	cout << "\tAnswer: " << (s3 == s4) << " --> Should be: 0" << endl;
}
void test_not_eq()
{
	cout << "Testing !=" << endl;
	String s1("Justin");
	String s2("Justin");
	cout << "\t(1) The String is: " << s1 << " and " << s2 << endl;
	cout << "\tAnswer: " << (s1 != s2) << " --> Should be: 0" << endl;
	String s3("Justin");
	String s4("Chung");
	cout << "\t(2) The String is: " << s3 << " and " << s4 << endl;
	cout << "\tAnswer: " << (s3 != s4) << " --> Should be: 1" << endl;
}
void test_gt()
{
	cout << "Testing >" << endl;
	String s1("abcdef");
	String s2("ABCDEF");
	cout << "\t(1) Comparing: " << s1 << " > " << s2 << endl;
	cout << "\tAnswer: " << (s1 > s2) << " --> Should be: 1" << endl;
	String s3("JUSTIN");
	String s4("Justin");
	cout << "\t(2) Comparing: " << s3 << " > " << s4 << endl;
	cout << "\tAnswer; " << (s3 > s4) << " --> Should be: 0" << endl;
	String s5("same");
	String s6("same");
	cout << "\t(3) Comparing: " << s5 << " > " << s6 << endl;
	cout << "\tAnswer: " << (s5 > s6) << " --> Should be: 0" << endl;
}
void test_lt()
{
	cout << "Testing <" << endl;
	String s1("HELLO");
	String s2("hello");
	cout << "\t(1) Comparing: " << s1 << " < " << s2 << endl;
	cout << "\tAnswer: " << (s1 < s2) << " --> Should be: 1" << endl;
	String s3("JUSTIN");
	String s4("Justin");
	cout << "\t(2) Comparing: " << s3 << " < " << s4 << endl;
	cout << "\tAnswer: " << (s3 < s4) << " --> Should be: 1" << endl;
	String s5("same");
	String s6("same");
	cout << "\t(3) Comparing: " << s5 << " < " << s6 << endl;
	cout << "\tAnswer: " << (s5 < s6) << " --> Should be: 0" << endl;
}
void test_le()
{
	cout << "Testing <=" << endl;
	String s1("UCI");
	String s2("UCI");
	cout << "\t(1) Comparing: " << s1 << " <= " << s2 << endl;
	cout << "\tAnswer: " << (s1 <= s2) << " --> Should be: 1" << endl;
	String s3("uci");
	String s4("UCI");
	cout << "\t(2) Comparing: " << s3 << " <= " << s4 << endl;
	cout << "\tAnswer: " << (s3 <= s4) << " --> Should be: 0" << endl;
	cout << "\t(3) Comparing: " << s4 << " <= " << s3 << endl;
	cout << "\tAnswer: " << (s4 <= s3) << " --> Should be: 1" << endl;
}
void test_ge()
{
	cout << "Testing >=" << endl;
	String s1("abcdef");
	String s2("abcdef");
	cout << "\t(1) Comparing: " << s1 << " >= " << s2 << endl;
	cout << "\tAnswer: " << (s1 >= s2) << " --> Should be: 1" << endl;
	String s3("JUSTIN");
	String s4("Justin");
	cout << "\t(2) Comparing: " << s3 << " >= " << s4 << endl;
	cout << "\tAnswer: " << (s3 >= s4) << " --> Should be: 0" << endl;
	cout << "\t(3) Comparing: " << s4 << " >= " << s3 << endl;
	cout << "\tAnswer: " << (s4 >= s3) << " --> Should be: 1" << endl;
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
	String::final_report_on_allocations();
	cout << "Number of new allocations minus number of delete deallocations is " << String::get_allocations() << endl;
	return 0;
}
