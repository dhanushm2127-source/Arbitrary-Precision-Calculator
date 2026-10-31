#include "apc.h"

void multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *headR1 = NULL;
    Dlist *tailR1 = NULL;
    Dlist *headR2 = NULL;
    Dlist *tailR2 = NULL;

    Dlist *temp2 = *tail2;
    int count = 0;
    while(temp2 != NULL)
    {
        Dlist *temp1 = *tail1;
        int carry = 0;
        while(temp1 != NULL)
        {
            int multi = temp1 -> data * temp2 -> data + carry;
            carry = multi / 10;
            if(count == 0)
            {
                insert_at_first(&headR1, &tailR1, multi % 10);
            }
            else
            {
                insert_at_first(&headR2, &tailR2, multi % 10);
            }
            temp1 = temp1 -> prev;
        }
        if(carry > 0)
        {
            if(count == 0)
            {
                insert_at_first(&headR1, &tailR1, carry);
            }
            else
            {
                insert_at_first(&headR2, &tailR2, carry);
            }
        }
        
        if(count > 0)
        {
            for(int i = 0; i < count; i++)
            {
                insert_at_last(&headR2, &tailR2, 0);
            }
            addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);
            delete_list(&headR1, &tailR1);
            delete_list(&headR2, &tailR2);
            headR1 = *headR;
            tailR1 = *tailR;

            *headR = NULL;
            *tailR = NULL;
        }
        temp2 = temp2 -> prev;
        count++;
    }

    *headR = headR1;
    *tailR = tailR1;
}