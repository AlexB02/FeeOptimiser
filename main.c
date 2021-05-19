#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float getRate(char method[]) {
	if (strcmp(method, "debit") == 0) {
		return 3.99;
	}
	else if (strcmp(method, "standard") == 0) {
		return 1.49;
	}
	return 0;
}

int main(int argc, char **argv) {
	int amount = atoi(argv[1]);
	float lowest[amount];
	float variableRate = getRate(argv[2]);
	for (int i=0; i < amount; i++) {
		if (i <= 9) {
			lowest[i] = 0.99;
		}
		else if (i <= 24) {
			lowest[i] = 1.49;
		}
		else if (i <= 49) {
			lowest[i] = 1.99;
		}
		else if (i <= 199) {
			lowest[i] = 2.99;
		} else {
			printf("Cannot handle more than 200!\n");
			return 0;
		}
	}
	printf("Rate: %f", lowest[amount - 1]);
	return 0;
}
