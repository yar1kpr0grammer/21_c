#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char string[124];

bool isint(double num){
	double int_part;
	
	if (modf(num, &int_part) == 0.0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	double number1;
	double number2;
	string str;
	
	fgrts(str, sizeof(str), stdin);
	int parded = sscanf("%f %f", &number1, &number2);
	if (parsed != 2){
		return 1;
	}
	if (!isint(number1) || !isint())
	

	return 0;
}q
