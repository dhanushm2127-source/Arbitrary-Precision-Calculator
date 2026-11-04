#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define NOSWAP 1
#define SWAP 2
#define EQUAL 3


typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

/* Create nodes from the inputs */
int create_node(Dlist **head, Dlist **tail, char *str);

/* Check whether the input numbers valid or not */
int valid_arg(char *str1, char *str2);

/*Insert node at end of the list */
int insert_at_last(Dlist **head, Dlist **tail, int data);

/*Insert node at first of the list */
int insert_at_first(Dlist **head, Dlist **tail, int data);

/* Print the linked list */
int print_list(Dlist *head);

/* Identifies the operation and signs of the numbers */
char operation_type(Dlist **head1, Dlist ** head2, char op, char *sign);

/* Perform Addition of two numbers */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* Count number of nodes in the list */
int list_len(Dlist **head1, Dlist **head2, int *List1_count, int *List2_count);

/* Compare two numbers */
int list_compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

/* Perform Subtraction of two numbers */
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* Delete all nodes from the list */
int delete_list(Dlist **head, Dlist **tail);

/* Perform Multiplication of two numbers */
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* Remove leading zeros from the list */
int remove_zero(Dlist **head, Dlist **tail);

/* Perform Division of two numbers */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Perform operation and display the result */
int do_operation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char operator);

#endif