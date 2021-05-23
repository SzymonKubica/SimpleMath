#include"parser.h"

int main(void) {
	char * buffer = "2 + 2 * 34";
	printTokens(buffer);
	return 0;
}
