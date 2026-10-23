#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) { stack[++top] = x; }
int  pop()       { return stack[top--]; }

int main() {
    char postfix[MAX];

    printf("Enter postfix expression (single digits, no spaces): ");
    scanf("%s", postfix);

    int len = strlen(postfix);
    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else {

            int b = pop();
            int a = pop();
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = (int)pow(a, b); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 1;
            }
            push(result);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
