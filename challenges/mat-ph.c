/******************************************************************************
                                     MAT CHALLENGE
Author:      Prakash Hegade
Email:       prakash.hegade@gmail.com
University:  KLE Technological University
Date:        31 August 2019

******************************************************************************/


/***-----------------------------------------------------------------------***/
                      /** Global Declaration Space **/

/// Standard library files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Defined constants
#define KB 1024
#define HEAP_SPACE 100 * KB * KB

/// Structure to the MAT entries for each user
struct memory_alloacation_table
{
    char  user_name[10];
    long  bytes;
    char  *start_address;
    struct memory_alloacation_table *next_mat_entry;
};
typedef struct memory_alloacation_table MAT;


/// Global variables
char  *block;             /// Global pointer to hold MAT starting address
char  *block_backup;      /// Global pointer to hold MAT starting address (backup)
MAT   *start = NULL;      /// Start address of MAT table
int   user_id;            /// Global user name assignment number
long  size_in_bytes;      /// 100MB expressed in bytes
long  available_size;     /// Maintains the available size for the moment
long  mat_entry_count;    /// Number of MAT table entries


/// Function prototypes
void get_heap_memory();
void welcome_menu();
void operate();
void allocate();
void free_memory();
void print_MAT();
void initialize();
void insert_at_mat(MAT *);
void rearrange_mat();


/***-----------------------------------------------------------------------***/


///Function:     main
///Description:  Calls the setup and executes the MAT
///Input param:  NIL
///Return Type:  integer indicating the status
int main()
{
    get_heap_memory();
    initialize();
    welcome_menu();
    operate();
    return 0;
}


/***-----------------------------------------------------------------------***/


///Function:     get_heap_memory
///Description:  allocates 100MB space from heap memory
///Input param:  NIL
///Return Type:  NIL
void get_heap_memory()
{
    block = (char *)malloc(sizeof(HEAP_SPACE));
    if(block == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    /// Keep a backup of block address
    block_backup = block;
}


///Function:     initialize
///Description:  initializes the global variables
///Input param:  NIL
///Return Type:  NIL
void initialize()
{
    user_id = 1;
    size_in_bytes = 10000000;
    available_size = 10000000;
    mat_entry_count = 0;
}


///Function:     welcome_menu
///Description:  prints the welcome menu and starting address of allocated memory
///Input param:  NIL
///Return Type:  NIL
void welcome_menu()
{
    printf("*---------------------------------------------------------*\n");
    printf("*                   WELCOME TO MAT                        *\n");
    printf("*---------------------------------------------------------*\n");
    printf("You have 10000000 Bytes to use starting at %p\n",block);
}


///Function:     operate
///Description:  menu options to operate on MAT
///Input param:  NIL
///Return Type:  NIL
void operate()
{
    int choice = 0;
    while(1)
    {
        printf("\n\n* MAT MENU *\n");
        printf("1-Allocate memory\n");
        printf("2-Free Memory\n");
        printf("3-Print MAT table\n");
        printf("4-Exit\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: /// Allocates the user requested number of bytes. The code does not deal with user data.
                    /// A sequential user id is assigned to each request. All the data are of type - char.
                    allocate();
                    break;

            case 2: /// Prints the MAT table and asks user to enter the user id to be deleted.
                    /// After deletion rearranges all the addresses. This method is inefficient.
                    /// A better method is to use the calloc approach.
                    free_memory();
                    break;

            case 3: /// Prints the MAT Table.
                    print_MAT();
                    break;

            case 4: printf("Freeing MAT Table memory\n");
                    free(block);
                    exit(1);
        }
    }
}


///Function:     allocate
///Description:  allocates the user requested number of bytes
///Input param:  NIL
///Return Type:  NIL
void allocate()
{
    long user_size;
    printf("Enter the memory you need in terms of bytes\n");
    scanf("%ld", &user_size);

    /// Check if the given user size is valid
    if(user_size > available_size)
    {
        printf("The requested size is not available.\n");
        printf("The available memory is %ld", available_size);
        return;
    }

    /// Reduce the available size
    available_size -= user_size;

    /// Create a MAT table node
    MAT * new_entry = (MAT *)malloc(sizeof(MAT));
    if(new_entry == NULL) {
        printf("Heap Full\n");
    }

    /// Gather all the user request data
    /// Create a user id by appending id number to string - user
    strcpy(new_entry->user_name, "user");
    char id[4];
    sprintf(id, "%d", user_id);
    strcat(new_entry->user_name, id);
    user_id++;

    /// Load the bytes and start address
    /// Set the next entry pointing address to NULL
    new_entry->bytes = user_size;
    new_entry->start_address = block;
    block = block + user_size;
    new_entry->next_mat_entry = NULL;

    /// Insert the MAT entry at the end of the table
    insert_at_mat(new_entry);

    /// Increase the MAT entry count
    mat_entry_count++;
}


///Function:     insert_at_mat
///Description:  add to the end of the list
///Input param:  The starting address of node to be inserted at MAT
///Return Type:  NIL
void insert_at_mat(MAT * new_entry)
{
    /// Creating the first node in the list
    if(start == NULL)
        start = new_entry;
    /// Add the node in the end
    else{
        MAT * temp;
        temp = start;
        while(temp->next_mat_entry != NULL)
            temp = temp->next_mat_entry;
        temp->next_mat_entry = new_entry;
    }
}


///Function:     free_memory
///Description:  free the user requested memory based on id
///Input param:  NIL
///Return Type:  NIL
void free_memory()
{
    /// Print the MAT table
    print_MAT();

    /// Exit if the list is empty
    if(start == NULL){
        return;
    }

    /// Collect the user id to be deleted
    char user_name[20];
    printf("Enter the user name that needs to be deleted\n");
    scanf("%s", user_name);

    /// Search the user input id through the list
    MAT  *temp = start;     /// Temporary pointer to traverse MAT
    int  status = 0;        /// User id comparison status
    long count = 0;         /// Tracks the node number to be deleted
    int  flag = 0;          /// Flag to track if node is found or not

    while(temp->next_mat_entry != NULL) {
        status = strcmp(temp->user_name, user_name);
        if(status == 0){
            flag = 1;
            break;
        }
        else{
            count++;
            temp = temp->next_mat_entry;
        }
    }

    /// Check the match in last node entry
    status = strcmp(temp->user_name, user_name);
    if(status == 0){
        count++;
        flag = 1;
    }

    /// User id not found
    if(flag == 0) {
        printf("Invalid User\n");
        return;
    }

    MAT *next, *prev;
    int position = 1;

    /// Delete the first node
    if(count == 1)
    {
        next = start;
        start=start->next_mat_entry;
        free(next);
    }
    /// Delete the appropriate node
    else
    {
        prev = NULL;
        next = start;
        while(position != count) {
            prev = next;
            next = next->next_mat_entry;
            position++;
        }
        prev->next_mat_entry = next->next_mat_entry;
    }
    printf("User Deleted Successfully.\n");

    /// Free the node
    free(next);

    /// Reduce the node count
    mat_entry_count--;

    /// Rearrange the MAT table with new addresses
    rearrange_mat();
}


///Function:     rearrange_mat
///Description:  reassigns the addresses after a node deletion
///Input param:  NIL
///Return Type:  NIL
void rearrange_mat()
{
    MAT * temp = start;
    available_size = 10000000;
    block = block_backup;

    /// When the MAT table becomes empty
    if(temp == NULL) {
        user_id = 1;
        return;
    }

    /// Rearrange all the addresses
    while(temp != NULL) {
        temp->start_address = block;
        block = block + temp->bytes;
        available_size -= temp->bytes;
        temp = temp->next_mat_entry;
    }
}


///Function:     print_MAT
///Description:  prints the MAT Table
///Input param:  NIL
///Return Type:  NIL
void print_MAT()
{
    if(start == NULL)
        printf("No Allocations Yet\n");
    else{
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nUser\t\tBytes\t\tStart Address\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        MAT *temp = start;
        while(temp!=NULL)
        {
            printf("%s\t\t%ld\t\t%p\n", temp->user_name, temp->bytes, temp->start_address);
            temp = temp->next_mat_entry;
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}
