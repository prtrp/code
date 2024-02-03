#include <stdio.h>
#include <stdbool.h>

int main() {
	// single characters
	char a = 'C'; // single character %c
	char b[] = "bro"; // array of characters %s
	
	// not integer numbers
	float c = 3.141592; 	      // 4 bytes (32 bits of precision) 6-7 digiys %f
	double d = 3.141592663689792; // 8 bytes (64 bits of precision) 15-17 digits %lf

	// booleans
	bool e = true;                // 1 byte (true or false) %d
	
	// char in an outher 2 points of view
	char f = 100;                 // 1 byte (-128 to + 127) %c or %d -> with [%c] will display the number, but with c in this exemple is [d] for the ascii table
	unsigned char g = 255;        // 1 byte (0 to +255) %d or %c
	
	// sort
	short h = 32767;               // 2 bytes (-32767 to +32.767) %d          
	unsigned short i = 65532;      // 2 bytes (0 to +65.535) %d

	// int
	int j = 2147483647;            // 4 bytes (-2.147.483.647 to +2.147.483.647) %d
	unsigned int k = 424967295;    // 4 bytes (0 to +4.249.967.295) %u

	// long is really long
	long long int l = 922337036854775807LL; // 8 bytes (-9 quintillion to + 9 quintillion) %lld
	unsigned long long int m = 18446744073709551610ULL; // 8 bytes (0 to + 18 quintillion) %llu

	printf("%ud\n", i);
	printf("%lu", sizeof(long double));
	return 0;
} 

//		k
//  h   l
//		j
 
