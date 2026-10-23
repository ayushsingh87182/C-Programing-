#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define MAX 100

int *stack=NULL;
int top= -1;

void createStack(){
    stack= (int *)malloc(MAX * sizeof(int));
    if(stack==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
}
    
void push(int x){
    if (top==MAX - 1){
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top]=x;
}
int pop(){
    if (top== -1){
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *exp){
    createStack();
    int i;
    for (i=0; exp[i] !='\0'; i++){
        char ch = exp[i];
        if (ch ==' ' ||ch =='\t')
           continue; //skip spaces
        if (isdigit(ch)){//convert character digit to integer 
            push(ch  - '0');
            
        }
        else{//operator encountered - pop two elements
            int val2 = pop();
            int val1 = pop();
            int result;
            
            switch(ch){
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '^': result = pow(val1, val2);break;
                default:
                    printf("Invalid operator: %c\n",ch);
                    exit(1);
            }
            push(result);
        }
    }
    int finalResult = pop();
    free(stack); //free allocated memory
    return finalResult;
}

int main() {
    char exp[MAX];
    printf("Enter a postfix expression (use single-digit operands):");
    fgets(exp,MAX,stdin);
    exp[strcspn(exp,"\n")]='\0';
    int result = evaluatePostfix(exp);
    printf("Result = %d\n",result);
    return 0;
}
