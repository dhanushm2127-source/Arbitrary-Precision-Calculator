#ifndef MAIN_H
#define MAIN_H

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

void create_node(Dlist **head, Dlist **tail, char *str);
int insert_last(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
#endif