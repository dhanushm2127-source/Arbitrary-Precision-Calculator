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
}