
// JULIO 2020. CÉSAR BORAO MORATINOS: stack.h (II)

enum {
	Maxstr = 30
};

typedef struct Node Node;
typedef struct Node *Stack;

struct Node
{
	char Data[Maxstr];
	struct Node *Next;
};

int push(char *str , Stack *s);
char *pop(Stack *s);
int drop(Stack *s, int n);
int isempty(Stack *s);
