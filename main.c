#include "inverted_Search.h"

int main(int argc , char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};
    //validate CLA 
    if( argc <= 1 )
    {
        printf(RED"Enter the valid no. of arguments\n"RESET);
        printf(RED"./a.out file1.txt file2.txt .......\n"RESET);
        return 1;
    }

    //create file linked list 
    //declare head pointer 
    Flist *f_head = NULL;

    //validation of files 
    file_validation_n_file_list(&f_head ,argv);

    if(f_head == NULL)
    {
        printf(RED"No files added to file linked list\n"RESET);
        printf(RED"Hence the process got terminated\n"RESET);
        return 2;
    }
	char choice;
	do
	{
		int option;
		printf(LIGHT_BLUE"\nSelect your choice among the following options :\n"RESET);
		printf(LIGHT_BLUE"1. CREATE DATABASE\n2. DISPLAY DATABASE\n3. UPDATE DATABASE\n4. SEARCH\n5. SAVE DATABASE\n6. EXIT\nEnter your choice: "RESET);
		scanf("%d", &option);



	switch(option)
	{
        	case 1: 
        	    create_database(f_head , head);
		    break;
        	case 2:
        	    display_database(head);
		    break;
        	case 3:
        	    update_database(head , &f_head);
		    break;
        	case 4:
		    {
        	    char word[WORD_SIZE];
        	    printf("Enter the search word\n");
        	    scanf("%s" , word);
	
        	    int index = tolower(word[0]) % 97;

        	    search(head[index] , word);
		    break;
	    	}
	        case 5:
	            save_database(head);
		    break;
		case 6:
		    printf(YELLOW"Exiting the program...\n"RESET);
		    return 0;
		default:
		    printf(RED"Invalid choice! Please enter a number between 1-6\n"RESET);
	}
	printf(GREEN"\nDo you want to continue?(Y/y for Yes, N/n for No): "RESET);
	scanf(" %c", &choice);
	
	}while(choice == 'Y' || choice == 'y');

	printf("Exiting program...\n");
	    return 0;
}
