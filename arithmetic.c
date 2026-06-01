#include <stdio.h>
#include <string.h>

typedef char string[124];

int main(){

	string nums;
	fgets(nums, sizeof(nums), stdin);
	
	int number1;
	int number2;
	int parsed = sscanf(nums, "%d %d", &number1, &number2);
	
	if (parsed == 2){
		int sum = number1 + number2;
		int dif = number1 - number2;
		int mult = number1 * number2;
		if (number2 != 0){
			int quo = number1 / number2;
			printf("%d %d %d %d\n", sum, dif, mult, quo);	
		}
		else {
			printf("%d %d %d n/a\n", sum, dif, mult);
		}
	}
	else {
		return 1;
	}
	
	return 0;
}
