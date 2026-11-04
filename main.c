#include<stdio.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        printf("Please enter:  ./a.out <number1> <op> <number2>");
        return FAILURE;
    }

    if(valid_arg(argv[1], argv[3]) == FAILURE)
    {
        printf("ERROR... Invalid Input\n");
        return SUCCESS;
    }

    //Operand 1 (argv[1])
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    if(create_node(&head1,&tail1,argv[1]) == FAILURE)
    {
        return FAILURE;
    }
    printf("Num 1 = ");
    print_list(head1);

    //Operand 2 (argv[3])
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;
    if(create_node(&head2,&tail2,argv[3]) == FAILURE)
    {
        return FAILURE;
    }
    printf("Num 2 = ");
    print_list(head2);

    do_operation(&head1, &tail1, &head2, &tail2, argv[2][0]);
}