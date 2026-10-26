#include"main.h"
/*In validation we are validating each CLA and adding to a SLL by updating by inserting at last*/
int validation(int argc,char*argv[],flist**head)
{
    int i;
    if(argc==1)
    {
        printf(RED"ERROR ! Please enter the correct argumenets\n"RESET);
    }
    for(i=1;i<argc;i++)
    {
        FILE*fptr=fopen(argv[i],"r");
        if(fptr==NULL)
        {
            printf(RED"%s is not present\n"RESET,argv[i]);
            continue;        
        }
        if(strstr(argv[i],".txt")==NULL)
        {
            printf(RED"%s has not .txt extension\n"RESET,argv[i]);
            continue;
        }
        fseek(fptr,0,SEEK_END);
        if(ftell(fptr)==0)
        {
            printf(RED"File is empty\n"RESET);
            continue;
        }
        if(insert_at_last(head,argv[i])==FAILURE)
        {
            printf(RED"%s is a Duplicate file \n"RESET,argv[i]);
            continue;
        }
    }
    return SUCCESS;
}
int insert_at_last(flist**head,char*argv)
{
        flist*new=malloc(sizeof(flist));
        if(new==NULL)
            return FAILURE;
        strcpy(new->file_name,argv);
        new->link=NULL;
        if(*head==NULL)
        {
            *head=new;
            return SUCCESS;
        }
        flist*temp=*head;
        while(temp)
        {
            if(strcmp(temp->file_name,argv)==0)
            {
                free(new);
                return FAILURE;
            }
            if(temp->link==NULL)
                break;
                
            temp=temp->link;
        }
        temp->link=new;
        return SUCCESS;
}
int print_list(flist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf(BLUE"%s -> "RESET, head -> file_name);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}