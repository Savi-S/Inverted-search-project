#include "inverted_Search.h"

int save_database( Wlist *head[])
{
    char file_name[FNAME_SIZE];
    printf(GREEN"Enter the file name\n"RESET);
    scanf("%s" , file_name);

    //open file
    FILE *fptr = fopen(file_name , "w");

    for(int i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            write_databasefile(head[i] , fptr);
        }
    }
    fclose(fptr);
    return 0;

}

void write_databasefile(Wlist *head, FILE *databasefile)
{
	while(head)
	{
		fprintf(databasefile, "#[%d] : %s : %d",tolower(head->word[0])%97, head->word, head->file_count);
				Ltable *ltable = head->Tlink;
				while(ltable)
				{
				fprintf(databasefile, " : %s : %d", ltable->file_name, ltable->word_count);
				ltable = ltable->table_link;
				}
				fprintf(databasefile, "\n");

				head = head->link;
	}

}
