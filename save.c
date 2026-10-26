#include"main.h"

int save_database(hash_t arr[])
{
    char s[20];
    printf("Enter the name of file:");
    scanf(" %s",s);
    FILE*fptr=fopen(s,"w");
    if(strstr(s,".txt")==NULL)
    {
        printf("file  has not .txt extension\n");
        return FAILURE;
    }
    fprintf(fptr,"\n====================== DATABASE ======================\n");
    fprintf(fptr,"%-6s %-15s %-12s %-15s %-10s\n","INDEX", "WORD", "FILE COUNT", "FILE NAME", "WORD COUNT");
    fprintf(fptr,"------------------------------------------------------\n");
    for(int i=0;i<27;i++)
    {
        if(arr[i].mlink!=NULL)
        {
            m_node*mtemp=arr[i].mlink;
            while(mtemp)
            {
                fprintf(fptr,"%-6d %-15s %-12d", i, mtemp->word, mtemp->fcount);
                s_node*stemp=mtemp->slink;

                while(stemp)
                {
                    fprintf(fptr," %-15s %-10d",stemp->file_name, stemp->wcount);
                    if(stemp->slink==NULL)
                        break;
                    fprintf(fptr,"\n%-6s %-15s %-12s","", "", "");
                    stemp=stemp->slink;
                }
                fprintf(fptr,"\n");
                if(mtemp->mlink==NULL)
                    break;
                mtemp=mtemp->mlink;
            }
        }
    }
    fclose(fptr);
    return SUCCESS;
}