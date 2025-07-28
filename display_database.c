#include"inverted_Search.h"

void display_database( Wlist *head[])
{
    printf(BOLD"\n%-8s %-15s %-20s %-15s %-10s\n"RESET,"[INDEX]","[WORD]","[FILE_COUNT]","[FILE_NAME]","[WORD_COUNT]\n");

    for(int i = 0 ; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}
int print_word_count(Wlist *head)
{
    //traverse through Wlist
    while(head != NULL)
    {
        printf("[%-5d]  %-15s  %-10d file/s " , tolower(head->word[0]) % 97 , head->word , head->file_count);

        Ltable *Thead = head->Tlink;

        //traverse 
        while(Thead)
        {
            printf("File : %-15s   %-5d", Thead->file_name , Thead->word_count);
            Thead = Thead->table_link;
        }
        printf("\n");
        head = head->link;
    }
}
