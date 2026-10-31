#include "apc.h"

void division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *head1;
    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;
    Dlist *res_head=NULL;
    Dlist *res_tail=NULL;

    while(temp1!=NULL)
    {
        int ret,count=0;
        Dlist *temp2 = *head2;

        insert_at_last(&head3,&tail3,temp1->data);
        temp1 = temp1->next;
        
        remove_zero(&head3, &tail3);

        ret = list_compare(&head3,&tail3,head2,tail2);
        while(ret == 1 || ret == 0)
        {
            subtraction(&head3,&tail3,head2,tail2,&res_head,&res_tail);
            count++;
            delete_list(&head3,&tail3);

            head3 = res_head;
            tail3 = res_tail;
            res_head = NULL;
            res_tail = NULL;

            remove_zero(&head3, &tail3);
            ret = list_compare(&head3,&tail3,head2,tail2);
        }
        insert_at_last(headR,tailR,count);
    }
    remove_zero(headR, tailR);
    delete_list(&head3, &tail3);
}