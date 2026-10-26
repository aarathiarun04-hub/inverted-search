
#include "main.h"

int main(int argc,char*argv[])
{
    flist *head=NULL;
    hash_t arr[27];

    //Creating the hash table with values
    for(int i=0;i<27;i++)
    {
        arr[i].index=i;
        arr[i].mlink=NULL;
    }
    char choice;
    if(validation(argc,argv,&head)==SUCCESS)
    {
        printf(GREEN"Validation of all files is successfully done!\n"RESET);
    }
    else
    {
         printf(RED"Validation of all files is not successfully done!\n"RESET);
    }
    print_list(head);
    printf("\n");

    printf(CYAN"-----------MENU---------------\n"RESET);
    printf("1.Create Database\n2.Display Database\n3.Search Database\n4.Save Database\n5.Update Database\n6.Exit\n");
    do
    {
        printf("Enter Your Choice : \n");
            scanf(" %c",&choice);
        switch(choice)
        {
            case '1':
                if(database(&head,arr)==SUCCESS)
                    printf(GREEN"Database created successfully\n"RESET);
                else
                    printf(RED"Database not created successfully\n"RESET);
                break;
            case '2':
                if(display_database(arr)==SUCCESS)
                    printf(GREEN"\t\tDisplay done successfully\n"RESET);
                else
                    printf(GREEN"Display not done successfully\n"RESET);
                break;
            case '3':
                if(search_database(arr)==SUCCESS)
                    printf(GREEN"Searching successfully done\n"RESET);
                break;
            case'4':
                if(save_database(arr)==SUCCESS)
                    printf(GREEN"Database saved successfully\n"RESET);
                else
                    printf(RED"Database not saved successfully\n"RESET);
                break;
            case '5':
                if(update_database(&head,arr)==SUCCESS)
                    printf(GREEN"Database updated successfully\n"RESET);
                else
                    printf(RED"Database not updated\n"RESET);
                break;
            case '6':
                printf(YELLOW"EXITING.....\n"RESET);
                break;
            default:
                printf(RED"Please enter the correct choice !\n"RESET);
                
        }
    }while(choice < '6');
    return SUCCESS;
    
   


}