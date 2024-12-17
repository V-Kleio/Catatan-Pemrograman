#include <stdio.h>

#include "mesinkata.h"

boolean cekAlay() {
	Word *cw = &currentWord;
	unsigned char i;
	short sum = -1;
	unsigned char ctr = 0;
	for (i = 0; i < cw->Length; ++i) {
		if (sum > 255) {
			return false;
		}

		char cc = cw->TabWord[i];

		if (cc == '@') {
			if (sum < 0) {
				return false;
			}
			ctr++;
			sum = -1;
			continue;
		}

		if (cc < 48 || cc > 57) {
			return false;
		}
		cc -= 48;

		if (sum < 0) {
			sum = cc;
		} else if (sum == 0 && cc != 0) {
			return false;
		} else {
			sum = sum * 10 + cc;
		}
	}

	if (ctr != 3 || sum < 0 || sum > 255) {
		return false;
	}

	return true;
}

int main() {
	STARTWORD();
	while (!EndWord) {
		if (cekAlay()) {
			printf("4Lay");
		} else {
			printf("ewh");
		}
		ADVWORD();

		if (!EndWord) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}