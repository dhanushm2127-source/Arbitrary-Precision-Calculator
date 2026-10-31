#include "apc.h"

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