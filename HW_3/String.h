#include <iostream>
using namespace std;
#define MAXLEN 128
class String
{
public:
	String( const char * s = "");
	String( const String & s );
	String operator  = ( const String & s );
	char & operator [] ( int index );
	int size();
	String reverse(); // does not modify this String
	int indexOf( const char c );
	int indexOf( const String pattern );
	bool operator == ( const String s );
	bool operator != ( const String s );
	bool operator > ( const String s );
	bool operator < ( const String s );
	bool operator <= ( const String s );
	bool operator >= ( const String s );
	/// concatenates this and s to return result
	String operator + ( const String s );
	/// concatentates s onto end of this
	String operator += ( const String s );
	void print( ostream & out );
	void read( istream & in );
	~String();

private:
	bool inBounds( int i );
	// HINT: some C string primitives you should define and use
	static int strlen( const char *s);
	static char * strcpy( char *dest, const char *src );
	static char * strcat( char *dest, const char *src);
	static int strcmp( const char *left, const char *right );
	static int strncmp( const char *left, const char *right, int n );
	static const char * strchr( const char *str, int c );
	static char * strstr( const char *haystack, const char *needle );
	char buf[MAXLEN];
};
ostream & operator << ( ostream & out, String str );
istream & operator >> ( istream & in, String & str );
