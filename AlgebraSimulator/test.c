#include"parser.h"

int main(void) {
	printPromptMessage();

	char *buffer = NULL;
	int read;
	size_t len;

	read = getline(&buffer, &len, stdin);

	if (-1 != read) {
		printTokens(buffer);
  } else {
		printf("No line entered.");
  }
	return 0;
}
