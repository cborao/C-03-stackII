
// JULIO 2020. CÉSAR BORAO MORATINOS: main.c (II)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include "stack.h"

int
main(int argc, char *argv[]) {

	Stack list = NULL;
	char word[Maxstr];
	char *Nextc;
	char *output;
	char i,j = 'a';

	// Insert in list
	for (i='a';i<='z'; i++) {
		word[0] = i;
		for (j = 'a'; j <= 'z'; j++) {
			word[1]= j;
			word[2]='\0';

			if(push(word, &list) < 0)
				errx(EXIT_FAILURE,"error: adding element in stack");
		}
	}

	// Take out from list
	output = pop(&list);

	while (output != NULL) {
		Nextc = output + 1;

		if (*output == *Nextc) {
			if (drop(&list, 4) < 0)
				fprintf(stderr, "warn: cannot drop\n");
		}else{
			printf("%s\n",output);
		}
		free(output);
		output = pop(&list);
	}

	if (output == NULL) {
		free(output);
		errx(EXIT_FAILURE,"Stack empty");
	}

	exit(EXIT_SUCCESS);
}
