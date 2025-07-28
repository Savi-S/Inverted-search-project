#include "inverted_Search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File : %s is not available \n" , argv[i]);
            printf("hence we are not adding that file\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("File : %s is not have any content in it\n" , argv[i]);
            printf("hence we are not adding that file\n");
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head , argv[i]);

            if(ret_val == SUCCESS)
            {
                printf("Successfull : Inserting the file name %s into the file linked list\n", argv[i]);
            }
            else if (ret_val == REPEATATION)
            {
                printf("This file name : %s is repeated. Do not add more than once\n" , argv[i]);
            }
            else
            {
                printf("Failure\n");
            }
            i++;
            continue;
        }
    }
}

//fun() is used to check file availability and check for file content 
int isFileEmpty(char *filename)
{
    //check for file availability 
    FILE *fptr = fopen(filename , "r");
    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
	return FAILURE;
    }
    // check for content 
    fseek(fptr, 0 , SEEK_END);
    if(ftell(fptr) == 0)
    {
	fclose(fptr);
        return FILE_EMPTY;
    }

    fclose(fptr);
    return SUCCESS;

}

int to_create_list_of_files(Flist **f_head, char *name)
{
	Flist *new = malloc(sizeof(Flist));
	if(new == NULL)
		return FAILURE;

	strcpy(new->file_name, name);
	new->link = NULL;

	Flist *temp = *f_head;

	while(temp)
	{
		if(strcmp(temp->file_name , name) == 0)
		{
			free(new);
			return REPEATATION;
		}
		temp = temp->link;
	}

	if(*f_head == NULL)
	{
		*f_head = new;
	}
	else
	{
		Flist *tail = *f_head;
		while(tail->link)
			tail = tail->link;
		tail->link = new;
	}

	return SUCCESS;



   // 1.  ........TODO.........
    //insert_last() of SLL 
    //check for duplicancy -> 

}
