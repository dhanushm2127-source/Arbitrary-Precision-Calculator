#include<stdio.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        printf("Please enter:  ./a.out <number1> <op> <number2>");
        return FAILURE;
    }
    //Operand 1 (argv[1])
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    char *str1 = argv[1];
    int data1, i = 0;
    create_node(&head1,&tail1,str1);
    printf("Num 1 = ");
    print_list(head1);

    //Operand 2 (argv[3])
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;
    char *str2 = argv[3];
    int data2, j = 0;
    create_node(&head2,&tail2,str2);
    printf("Num 2 = ");
    print_list(head2);

    Dlist *headR = NULL;
    Dlist *tailR = NULL;
    char op = argv[2][0];
    switch(op)
    {
        case '+':
            addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Addition of two number : ");
            print_list(headR);
            break;
        case '-':
            int ret = list_compare(&head1, &tail1, &head2, &tail2);
            if(ret == 1)
                subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            else
                subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
            printf("Subtraction of two number : ");
            if(ret == 2)
                printf("-");
            print_list(headR);
            break;
        case 'x':
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Multiplication of two number : ");
            print_list(headR);
            break;
        case '/':
            division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Division of two number : ");
            print_list(headR);
            break;
        default:
            printf("Invalid operation\n");
    }
}