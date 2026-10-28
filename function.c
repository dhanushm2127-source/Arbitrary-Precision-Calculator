#include "apc.h"

void create_node(Dlist **head, Dlist **tail, char *str)
{
    int i = 0, data;
    while(str[i] != '\0')
    {
        data = str[i] - 48;
        insert_last(head, tail, data);
        i++;
    }
}

int insert_last(Dlist **head, Dlist **tail, int data1)
{
    Dlist *newNode = malloc(sizeof(Dlist));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }
    
    newNode -> data = data1;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return SUCCESS;
    }
    
    newNode -> prev = *tail;
    
    (*tail) -> next = newNode;
    
    *tail = newNode;
    
    return SUCCESS;
}

void print_list(Dlist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    printf("%d <-", head -> data);
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}