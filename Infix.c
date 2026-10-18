#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
char stack[MAX];
int top = -1;
void push(char oper) {
    if (top == MAX - 1) {
        printf("Stack Full!!!!");
    } else {
        top++;
        stack[top] = oper;
    }
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        char ch = stack[top];
        top--;
        return ch;
    }
}
char peek() {
    return stack[top];
}
int isEmpty() {
    return top == -1;
}
void convertInfixToPostfix(char* expression) {
    int i, j = 0;
    char postfix[MAX];
    for (i = 0; expression[i]; ++i) {
        char ch=expression[i];
        if (checkIfOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() != '(') {
                printf("Invalid expression");
            } else {
                pop();
            }
        } else {
            while (!isEmpty()&&precedence(peek())>=precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}
int main() {
    char expression[MAX];
    printf("enter infix Expression\n");
    fgets(expression,MAX,stdin);
    printf("Infix Expression: %s\n", expression);
    convertInfixToPostfix(expression);
return 0;
}