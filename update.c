#include"main.h"

int update_database(flist**head,hash_t arr[])
{
    char s[20];
    printf("Enter the name of file:");
    scanf(" %s",s);
    FILE*fptr=fopen(s,"r");
    if(fptr==NULL)
    {
        printf("%s is not present\n",s);   
        return FAILURE;     
    }
    if(strstr(s,".txt")==NULL)
    {
        printf("%s has not .txt extension\n",s);
        return FAILURE;  
    }
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr)==0)
    {
        printf("File is empty");
        return FAILURE;  
    }
    if(insert_at_last(head,s)==FAILURE)
    {
        printf("%s is a Duplicate file \n",s);
        return FAILURE;  
    }
    database(head,arr);
    return SUCCESS;


}