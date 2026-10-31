#include "apc.h"

int create_node(Dlist **head, Dlist **tail, char *str)
{
    int i = 0, data;
    while(str[i] != '\0')
    {
        data = str[i] - 48;
        insert_at_last(head, tail, data);
        i++;
    }
    return SUCCESS;
}

/*------------------------------------------------------------------------------------------------------------------------------*/
int insert_at_last(Dlist **head, Dlist **tail, int data1)
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

/*------------------------------------------------------------------------------------------------------------------------------*/
void print_list(Dlist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    printf("%d", head -> data);
		    head = head -> next;
	    }
    }
    printf("\n");
}

/*------------------------------------------------------------------------------------------------------------------------------*/
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newNode = malloc(sizeof(Dlist));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }

    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return SUCCESS;
    }

    newNode -> next = *head;
    (*head) -> prev = newNode;
    *head = newNode;
    return SUCCESS;
}

/*------------------------------------------------------------------------------------------------------------------------------*/
void list_len(Dlist **head1, Dlist **head2, int *List1_count, int *List2_count)
{
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    while(temp1 != NULL)
    {
        (*List1_count)++;
        temp1 = temp1 -> next;
    }

    while(temp2 != NULL)
    {
        (*List2_count)++;
        temp2 = temp2 -> next;
    }
}

/*------------------------------------------------------------------------------------------------------------------------------*/
int list_compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    int List1_count = 0, List2_count = 0;
    list_len(head1, head2, &List1_count, &List2_count);

    if(List1_count > List2_count)
        return 1;
    else if(List1_count < List2_count)
        return 2;
    
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    while(temp1 != NULL && temp2!= NULL)
    {
        if(temp1 -> data > temp2 -> data)
            return 1;
        else if(temp1 -> data < temp2 -> data)
            return 2;

        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------*/
int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }

    if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }

    Dlist *temp = *head;
    while(temp != NULL)
    {
        *head = (*head) -> next;
        free(temp);
        temp = *head;
    }
    *tail = NULL;
    return SUCCESS;
}

/*------------------------------------------------------------------------------------------------------------------------------*/
int remove_zero(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }

    while((*head) != NULL && (*head)-> data == 0)
    {
        Dlist *temp = *head;
        *head = (*head) -> next;
        if(*head != NULL)
        {
            (*head) -> prev = NULL;
        }
        else
        {
            *tail = NULL;
        }
        free(temp);
    }
    return SUCCESS;
}