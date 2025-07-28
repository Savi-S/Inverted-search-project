#include "inverted_Search.h"

char *fname;

int create_database(Flist *f_head, Wlist *head[])
{
    //traverse through the FLL
    while(f_head)
    {
        read_datafile(f_head , head , f_head->file_name);
	printf("Database is created successfully for : %s\n", f_head->file_name); 
        f_head = f_head->link;
    }
    return SUCCESS;
}

// fun() is to read the content of each file 
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    int flag;
    // open file in read mode
    FILE *fptr = fopen(filename , "r");

    if(fptr == NULL)
    {
	    printf("Error: Unable to open file %s\n",filename);
	    return NULL;
    }

    //declare an array to store word 

    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
        //find index

        int index =  tolower(word[0]) % 97;
        //other than alphabets 
        if(!(index >= 0 && index <= 25))
        {
            index = 26;
        }

	flag = 1;

        if(head[index] != NULL)
        {
            Wlist *temp = head[index];
            // compare each node word with new word 
            while(temp)
            {
                if(strcmp(temp->word , word) == 0)
                {
                    update_word_count(&temp , filename);
                    flag = 0;
                    break;
                }
		temp = temp->link;
            }
        }

        // insert last will be called only when words are not repeated 
        if(flag == 1)
        {
            insert_at_last(&head[index] , word, filename);
        }
    }

    fclose(fptr);
    return *head;
}


int update_word_count(Wlist ** head, char * file_name)
{
	Wlist *temp = *head;
	
	while(temp)
	{
		Ltable *lt = temp->Tlink;

	while(lt)
	{
		if(strcmp(lt->file_name, file_name) == 0)
		{
			lt->word_count++;
			return SUCCESS;
		}

		lt = lt->table_link;
	}

	temp = temp->link;
	}

	Ltable *new_node = malloc(sizeof(Ltable));
	if(!new_node)
		return FAILURE;

	strcpy(new_node->file_name, file_name);
	new_node->word_count = 1;
	new_node->table_link = NULL;

	if((*head)->Tlink == NULL)
	{
		(*head)->Tlink = new_node;
		(*head)->file_count = 1;
	}
	else
	{
		Ltable *tail = (*head)->Tlink;
		while(tail->table_link)
		{
			if(strcmp(tail->file_name, file_name) == 0)
				return SUCCESS;
			tail = tail->table_link;
		}
		tail->table_link = new_node;
		(*head)->file_count++;
	}

	return SUCCESS;

}
