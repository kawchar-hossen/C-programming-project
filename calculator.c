#include<stdio.h>
#include<conio.h>
int main(){
    int n1,n2,add,sub,mul,div;
    char ch;
    while(1){
        printf("Enter first number:\n");
        scanf("%d",&n1);
        printf("Enter symbol (+ or - or * or /):\n");
        scanf("%c",&ch);
        printf("Enter second number: \n");
        scanf("%d",&n2);
        switch(ch){
            case '+': add = n1+n2;
                      printf("%d",add);
                      break;
            default : printf("wrong choice.");
        }

    }
}