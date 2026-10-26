#include"main.h"

int search_database(hash_t arr[])
{
    char s[20];
    printf("Enter the Word to search :\n");
    scanf("%s",s);

    int index;
    if(s[0] >='a' && s[0]<='z')
    {
        index=s[0]-'a';
    }
    else if(s[0] >='A' && s[0]<='Z')
    {
        index=s[0]-'A';
    }
    else
        index=26;

    if(arr[index].mlink==NULL)
    {
        printf("Word is not present\n");
        return FAILURE;
    }
    m_node*mtemp=arr[index].mlink;

    while(mtemp)
    {
        if(strcmp(mtemp->word,s)==0)
        {
            printf("\n====================== DATABASE ======================\n");
             printf("%-6s %-15s %-12s %-15s %-10s\n","INDEX", "WORD", "FILE COUNT", "FILE NAME", "WORD COUNT");
            printf("------------------------------------------------------\n");

             printf("%-6d %-15s %-12d", index, mtemp->word, mtemp->fcount);
             s_node*stemp=mtemp->slink;

            while(stemp)
            {
            printf(" %-15s %-10d",stemp->file_name, stemp->wcount);
            if(stemp->slink==NULL)
                break;
            printf("\n%-6s %-15s %-12s","", "", "");
            stemp=stemp->slink;
            }
            printf("\n");
            return SUCCESS;
        }
       
        
        if(mtemp->mlink==NULL)
            break;
        mtemp=mtemp->mlink;
    }
    printf("Word not found\n");
    return FAILURE;
    
}