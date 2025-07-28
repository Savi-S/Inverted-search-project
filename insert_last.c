#include "inverted_Search.h"

int insert_at_last(Wlist **head, data_t *data, char *fname)
{
    //create node
    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->file_count = 1;
    strcpy(new->word , data);
    new->Tlink = NULL;
    new->link = NULL;

    //call fun() to update Ltable node

    if(update_link_table(new,fname) == FAILURE)
    {
	    free(new);
	    return FAILURE;
    }
    //check list is empty or not 

    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    //not empty
    Wlist *temp = *head;
    //traverse 
    while(temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}


int update_link_table(Wlist *head, char *fname)
{
    //create a node
    Ltable *new = malloc(sizeof(Ltable));

    if(new == NULL)
    {
        return FAILURE;
    }

    new->word_count = 1;
    strcpy(new->file_name , fname); // check on this
    new->table_link = NULL;

    if(head->Tlink == NULL)
    {
	    head->Tlink = new;
    }
    else
    {
	    Ltable *temp; 
	    temp = head->Tlink;
	    while(temp->table_link)
	    {
		    temp = temp->table_link;
	    }
	    temp->table_link = new;
    }
    return SUCCESS; 
}
