#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float getRate(char method[]);
void buildLowest(float *lowest, int len, float variableRate);

int main(int argc, char **argv) {
	int amount = atoi(argv[1]);
	float lowest[amount];
	buildLowest(lowest, amount, getRate(argv[2]));
	printf("£%d would:"
	" cost £%0.2f in fees which is %0.2f%%\n",
	amount, 
	lowest[amount-1], 
	(lowest[amount-1] / amount)*100);
	return 0;
}

float getRate(char method[]) {
	if (strcmp(method, "debit") == 0) {
		return 0.0399;
	}
	else if (strcmp(method, "standard") == 0) {
		return 0.0149;
	}
	return 0;
}

void buildLowest(float *lowest, int len, float variableRate) {
	for (int i=1; i <= len; i++) { // Set cost in £ for investment of amount i
		if (i <= 10) {
			*lowest = 0.99;
		}
		else if (i <= 25) {
			*lowest = 1.49;
		}
		else if (i <= 50) {
			*lowest = 1.99;
		}
		else if (i <= 200) {
			*lowest = 2.99;
		} else {
			printf("Cannot handle more than 200!\n"); // rate is unknown for values over 200
			return;
		}
		if (*lowest < i * variableRate) { // Get the highest value to be charged
			*lowest = i * variableRate;
		}
		lowest++;
	}
}
