#include <iostream>
using namespace std;
class String
{
public:
	String( const char * s = "");
	String( const String & s);
	String operator = ( const String & s);
	char & operator [] ( int index );
	int size();
	String reverse();
	int indexOf( const char c);
	int indexOf( const String pattern );
	bool operator == ( const String s );
	bool operator != ( const String s );
	bool operator > ( const String s );
	bool operator < ( const String s );
	bool operator <= ( const String s );
	bool operator >= ( const String s );
	String operator + ( const String s );
	String operator += ( const String s );
	void print( ostream & out );
	void read( istream & in );
	static void final_report_on_allocations();
	static int get_allocations();
	~String();
private:
	static int allocations;
	static char * new_char_array(int n_bytes);
	static void delete_char_array(char *p);
	bool inBounds( int i );
	static int strlen( const char *src );
	static char * strcpy( char *dest, const char *src );
	static int strcmp( const char *left, const char *right);
	static char * strcat( char *dest, const char *src);
	static char *strdup( const char *src );
	/// More methods if needed
	char * buf;
};
ostream & operator << ( ostream & out, String str );
istream & operator >> ( istream & in , String & str );
