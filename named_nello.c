#include <stdio.h>

typedef char string[124];

int main(){

	string name;
	fgets(name, sizeof(name), stdin);
	printf("Hello, %s", name);

	return 0;
}
