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
void addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int carry = 0;
    int sum = 0;
    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp1 != NULL && temp2 != NULL)
        {
            sum = temp1 -> data + temp2 -> data + carry;
            carry = sum / 10;
            insert_at_first(headR, tailR, sum % 10);
            temp1 = temp1 -> prev;
            temp2 = temp2 -> prev;
        }
        else if(temp1 != NULL && temp2 == NULL)
        {
            sum = temp1 -> data + carry;
            carry = sum / 10;
            insert_at_first(headR, tailR, sum % 10);
            temp1 = temp1 -> prev;            
        }
        else if(temp1 == NULL && temp2 != NULL)
        {
            sum = temp2 -> data + carry;
            carry = sum / 10;
            insert_at_first(headR, tailR, sum % 10);
            temp2 = temp2 -> prev;            
        }
    }
    if(carry == 1)
    {
        insert_at_first(headR, tailR, carry);
    }
}

void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    
}
