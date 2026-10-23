#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop()        { return stack[top--]; }
char peek()       { return stack[top]; }

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int j = 0;

    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);

    int len = strlen(infix);
    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {

            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {

            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else {

            while (top != -1 && (priority(peek()) > priority(ch) ||
                  (priority(peek()) == priority(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
