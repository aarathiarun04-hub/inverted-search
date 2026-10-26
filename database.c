#include"main.h"

//Creating a data base 
int database(flist**head,hash_t arr[])
{
    
    flist*temp=*head;
    while(temp)
    {
        
        FILE *fptr =fopen(temp->file_name,"r");
        char s[20];
        int index;
        while(fscanf(fptr,"%s",s)!=EOF)
        {
            if(s[0] >='a' && s[0]<='z')
            {
                index=s[0]-'a';
            }
             else if(s[0] >='A' && s[0]<='Z')
            {
                index=s[0]-'A';
            }
             else
            {
                index=26;
            }
            upload_to_hash_t(arr,s,temp->file_name,index);
        }
        temp=temp->link;
    }
    return SUCCESS;
}
//updating the hash table
int upload_to_hash_t(hash_t arr[],char*s,char*file_name,int index)
{
    m_node *m_new=malloc(sizeof(m_node));
    s_node*s_new=malloc(sizeof(s_node));
    s_new->slink=NULL;
    m_new->mlink=NULL;

    if(arr[index].mlink==NULL)
    {
        strcpy(m_new->word,s);
        m_new->slink=s_new;
        m_new->fcount=1;
        s_new->wcount=1;
        strcpy(s_new->file_name,file_name);
        arr[index].mlink=m_new;
        return SUCCESS;
        
    }
        m_node*mtemp=arr[index].mlink;
        while(mtemp)
        {
            if(strcmp(mtemp->word,s)==0)
            {
                    s_node*stemp=mtemp->slink;
                    while(stemp)
                    {
                          if(strcmp(stemp->file_name,file_name)==0)
                          {
                             stemp->wcount++;
                             return SUCCESS;
                          }
                          if(stemp->slink==NULL)
                            break;
                          stemp=stemp->slink;
                    }
                        strcpy(s_new->file_name,file_name);
                        s_new->wcount=1;
                        stemp->slink=s_new;
                        mtemp->fcount++;
                        return SUCCESS;
            }
            if(mtemp->mlink==NULL)
                break;
            mtemp=mtemp->mlink;
        }
        strcpy(m_new->word,s);
        m_new->slink=s_new;
        m_new->fcount=1;
        s_new->wcount=1;
        strcpy(s_new->file_name,file_name);
         mtemp->mlink=m_new;
        return SUCCESS;

}