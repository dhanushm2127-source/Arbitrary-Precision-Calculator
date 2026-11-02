#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
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
            if(insert_at_first(headR, tailR, diff % 10) == FAILURE)
                return FAILURE;
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
            if(insert_at_first(headR, tailR, diff % 10) == FAILURE)
                return FAILURE;
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
            if(insert_at_first(headR, tailR, diff % 10) == FAILURE)
                return FAILURE;
            temp2 = temp2 -> prev;          
        }
    }
    return SUCCESS;
}