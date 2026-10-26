#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

// Text color macros
#define RESET   "\033[0m"
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

//Structure for single link list for storing file name
typedef struct node
{
    char file_name[20];
    struct node *link;
}flist;
//Structure for sub node
typedef struct sub_node
{
    int wcount;
    char file_name[20];
    struct sub_node *slink;
}s_node;
//Structure for main  node
typedef struct main_node
{
    char word[20];
    int fcount;
    s_node *slink;
    struct main_node *mlink;
}m_node;
//Structure for hash table
typedef struct hash
{
    int index;
    m_node *mlink;
}hash_t;

//Function for validating command line args and files
int validation(int argc,char*argv[],flist**head);

//Inserting at last in SLL
int insert_at_last(flist**head,char*argv);

//Printing single link list
int print_list(flist *head);

//Creating a database
int database(flist**head,hash_t arr[]);

//Updating the datas in hash table
int upload_to_hash_t(hash_t arr[],char*s,char*file_name,int index);

//Displaying of database
int display_database(hash_t arr[]);

//Searching of word in a database
int search_database(hash_t arr[]);

//Saving database into another file
int save_database(hash_t arr[]);

//Updating the existing database while adding and validating another file
int update_database(flist**head,hash_t arr[]);
#endif