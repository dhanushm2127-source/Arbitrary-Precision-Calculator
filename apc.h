#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int create_node(Dlist **head, Dlist **tail, char *str);
int insert_at_last(Dlist **head, Dlist **tail, int data);
int insert_at_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
void addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
void list_len(Dlist **head1, Dlist **head2, int *List1_count, int *List2_count);
int list_compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int delete_list(Dlist **head, Dlist **tail);
void multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
#endif