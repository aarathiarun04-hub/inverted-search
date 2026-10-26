#include "main.h"

int display_database(hash_t arr[])
{   
    printf("\n====================== DATABASE ======================\n");
    printf("%-6s %-15s %-12s %-15s %-10s\n","INDEX", "WORD", "FILE COUNT", "FILE NAME", "WORD COUNT");
    printf("------------------------------------------------------\n");

    for(int i = 0; i < 27; i++)
    {
        if(arr[i].mlink != NULL)
        {
            m_node *mtemp = arr[i].mlink;
            while(mtemp)
            {
                printf("%-6d %-15s %-12d", i, mtemp->word, mtemp->fcount);

                s_node *stemp = mtemp->slink;
                while(stemp)
                {
                    printf(" %-15s %-10d",stemp->file_name, stemp->wcount);

                    if(stemp->slink == NULL)
                        break;

                    printf("\n%-6s %-15s %-12s","", "", "");
                    stemp = stemp->slink;
                }
                printf("\n");

                if(mtemp->mlink == NULL)
                    break;
                mtemp = mtemp->mlink;
            }
        }
    }
    return SUCCESS;
}