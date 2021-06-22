
// JULIO 2020. CÉSAR BORAO MORATINOS: stack.c (II)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include "stack.h"

Node *
createnode(char *data) {
	Node *new;
	if ((new = malloc(sizeof(Node))) == NULL)
		errx(EXIT_FAILURE,"error: malloc failed");

	strncpy(new->Data,data,strlen(data)+1);
	new->Next = NULL;
	return new;
}

void freenode(Node *node) {
	node->Next = NULL;
	free(node);
}

int
push(char *str, Stack *s) {
	int status = -1;
	if (*s == NULL) {
		*s = createnode(str);
	}else{
		Node *aux = createnode(str);
		aux->Next = *s;
		*s = aux;
	}
	status = 1;
	return status;
}

char *
pop(Stack *s) {

	Node *aux = *s;
	char *value;
	if (*s == NULL)
		return NULL;

	if ((value = malloc(strlen(aux->Data)+1)) == NULL)
		errx(EXIT_FAILURE,"error: malloc failed");

	strncpy(value,aux->Data,strlen(aux->Data)+1);
	*s = aux->Next;
	freenode(aux);
	return value;
}

int
isempty(Stack *s) {
	if (*s == NULL)
		return 1;
	return 0;
}

int
drop(Stack *s, int n) {

	if (isempty(s))
		return -1;

	Node *aux;
	for (size_t i = 0; i < n; i++) {
		aux = *s;
		*s = aux->Next;
		freenode(aux);
	}
	return 1;
}
