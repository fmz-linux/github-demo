#include<stdio.h>

float jsq(char a,float x,float y)
{
    switch (a) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/':
            if (y == 0) {
                printf("bro除数不能为零！\n");
                return 0;  
            }
            return x / y;
        default:
            printf("???\n");
            return 0;
    }
       
}

int main()
{   float x,y;
    char a;
    while (1)
    {
        printf("输入要计算的式子，例如：x+y，\n");
        scanf("%f%c%f",&x,&a,&y);
        printf("%g\n",jsq(a,x,y));
    }
    return 0;

}