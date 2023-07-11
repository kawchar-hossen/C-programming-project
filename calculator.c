#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int n1,n2,add,sub,mul,div;
    char ch;
    while(1){
        printf("Enter first number:\n");
        scanf("%d",&n1);
        fflush(stdin);
        printf("Enter symbol (+ or - or * or /):\n");
        scanf("%c",&ch);
        printf("Enter second number: \n");
        scanf("%d",&n2);
        switch(ch){
            case '+': add = n1+n2;
                      printf("Addition of two number is :%d\n",add);
                      break;
            case '-': sub = n1 - n2;
                      printf("Subtraction of two number is : %d\n",sub);
                      break; 
             
            case '*': mul = n1 * n2;
                      printf("Multiplication of tow number is :%d\n",mul);
                      break; 
             
            case '/': sub = n1 / n2;
                      printf("Division of two number is :%d\n",div);
                      break; 
             
            default : printf("wrong choice.\n");
        }

    }
    return 0;
}