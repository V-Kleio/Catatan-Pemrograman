#include <stdio.h>

#include "mesinkata.h"

void printWord(Word word) {
	int i;
	for (i = 0; i < word.Length; ++i) {
		printf("%c", word.TabWord[i]);
	}
}

Word reverseWord(Word word) {
	int i;
	Word word2;
	word2.Length = word.Length;
	for (i = 0; i < word.Length; ++i) {
		word2.TabWord[i] = word.TabWord[word.Length - 1 - i];
	}
	return word2;
}

int main() {
	STARTWORD();
	unsigned c = 0;
	while (!EndWord) {
		if (c & 1) {
			printWord(currentWord);
		} else {
			printWord(reverseWord(currentWord));
		}
		ADVWORD();

		if (!EndWord) {
			printf(" ");
		}
		c++;
	}

	printf("\n");

	return 0;
}