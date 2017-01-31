#include "String.h"
#include <iostream>
using namespace std;

String::String(const char * s)
{
	buf = strdup(s);
}
String::String(const String & s)
{
	buf = strdup(s.buf);
}
String String::operator = ( const String & s )
{
	delete_char_array(buf);
	buf = strdup(s.buf);
	return *this;
}
char & String::operator [] ( int index )
{
	if (!inBounds(index))
	{
		cout << "Error: index not inbounds : " << index << endl;
	}
	else
	{
		return buf[index];
	}
}
int String::size()
{
	return strlen(buf);
}
String String::reverse()
{
	char temp[1000];
	int j = 0;
	for(int i = strlen(buf) - 1; i >= 0; i--)
	{
		temp[j] = buf[i];
		j++;
	}
	temp[j] = '\0';
	return String(temp);
}
int String::indexOf( const char c )
{
	int i;
	for(i = 0; buf[i] != '\0'; i++)
	{
		if(buf[i] == c)
			return i;
	}
	return -1;
}
int String::indexOf( const String pattern )
{
	int i, index;
	int j = 0;
	for(i = 0; buf[i] != '\0'; i++)
	{
		index = i;
		while(buf[i] == pattern.buf[j])
		{
			return index;
		}
	}
	return -1;
}
bool String::operator == ( const String s )
{
	return strcmp(buf, s.buf) == 0;
}
bool String::operator != ( const String s )
{
	if (strcmp(buf, s.buf) == 0)
		return false;
	return true;
}
bool String::operator > ( const String s )
{
	return strcmp(buf, s.buf) == 1;
}
bool String::operator < ( const String s )
{
	return strcmp(buf, s.buf) == -1;
}
bool String::operator <= ( const String s )
{
	if(strcmp(buf, s.buf) == 0 || strcmp(buf, s.buf) == -1)
		return true;
	return false;
}
bool String::operator >= ( const String s )
{
	if(strcmp(buf, s.buf) == 0 || strcmp(buf, s.buf) == 1)
		return true;
	return false;
}
String String::operator + ( const String s )
{
	char temp[strlen(buf) + strlen(s.buf) + 1];
	strcpy(temp, buf);
	return strcat(temp, s.buf);
}
String String::operator += ( const String s )
{
	strcat(buf, s.buf);
	return *this;
}
void String::print( ostream & out )
{
	out << buf;
}
void String::read( istream & in )
{
	char *new_buf = new_char_array(1000);
	in.getline(new_buf, 1000);
	buf = strdup(new_buf);
}
void String::final_report_on_allocations()
{
	if(allocations > 0)
		cout << "Memory leak in class String" << endl;
	if(allocations < 0)
		cout << "Too many delete[]s in class String" << endl;
	if(allocations == 0)
		cout << "Allocations match!" << endl;
}
int String::get_allocations()
{
	return allocations;
}
String::~String()
{
	delete_char_array(buf);
}
//private:
int String::allocations = 0;
char * String::new_char_array(int n_bytes)
{
	++allocations;
	return new char[n_bytes];
}
void String::delete_char_array(char *p)
{
	--allocations;
	if(allocations < 0)
		cout << "Error: more delete[] than new[]" << endl;
	delete[] p;
}
bool String::inBounds(int i)
{
	return i >= 0 && i < strlen(buf);
}
int String::strlen( const char *src )
{
	int count = 0;
	for ( int i = 0; src[i] != '\0'; i++ )
	{
		count++;
	}
	return count;
}
char * String::strcpy( char *dest, const char *src )
{
	int i;
	for ( i = 0; src[i] != '\0' && i <= strlen(src); i++ )
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}
char * String::strcat( char *dest, const char *src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}
int String::strcmp( const char * left, const char * right)
{
	int i;
	for ( i = 0; left[i] != '\0' || right[i] != '\0'; i++)
	{
		if ( left[i] > right[i]) {return 1;}
		else if ( right[i] > left[i] ) {return -1;}
		else if ( left[i] == right[i] ) {continue;}
	}
	return 0;
}
char * String::strdup( const char *src )
{
	char *buf = new_char_array(strlen(src)+1);
	return strcpy(buf, src);
}
ostream & operator << ( ostream & out, String str )
{
	str.print(out);
	return out;
}
istream & operator >> ( istream & in, String & str)
{
	str.read(in);
	return in;
}
