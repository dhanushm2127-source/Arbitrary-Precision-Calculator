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

int list_compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    int List1_count = 0, List2_count = 0;
    list_len(head1, head2, &List1_count, &List2_count);

    if(List1_count > List2_count)
        return 1;
    else if(List1_count < List2_count)
        return 2;
    else if(List1_count == List2_count)
    {
        Dlist *temp1 = *head1;
        Dlist *temp2 = *head2;
        while(temp1 -> data == temp2 -> data)
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
}

void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0, diff = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp1 != NULL && temp2 != NULL)
        {
            if(temp1 -> data < temp2 -> data)
            {
                temp1 -> data = temp1 -> data + 10;
                diff = temp1 -> data - temp2 -> data - borrow;
                borrow = 1;
            }
            else
            {
                diff = temp1 -> data - temp2 -> data - borrow;
                borrow = 0;
            }
            insert_at_first(headR, tailR, diff % 10);
            temp1 = temp1 -> prev;
            temp2 = temp2 -> prev;
        }
        else if(temp1 != NULL && temp2 == NULL)
        {
            diff = temp1 -> data - borrow; 
            if(diff < 0)
            {
                diff = diff + 10;
                borrow = 1;
            } 
            else
            {
                borrow = 0;
            }
            insert_at_first(headR, tailR, diff % 10);
            temp1 = temp1 -> prev;        
        }
        else if(temp1 == NULL && temp2 != NULL)
        {
            diff = temp2 -> data - borrow; 
            if(diff < 0)
            {
                diff = diff + 10;
                borrow = 1;
            } 
            else
            {
                borrow = 0;
            }
            insert_at_first(headR, tailR, diff % 10);
            temp2 = temp2 -> prev;          
        }
    }
}
