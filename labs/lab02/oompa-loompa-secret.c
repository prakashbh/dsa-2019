#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct choc_fantasy
{
    char choc_name[20];
    int quantity;
    struct choc_fantasy * prev;
    struct choc_fantasy * next;
};
typedef struct choc_fantasy CF;

CF * gather_requirements(CF *);
void melt_and_prepare(CF *);


/**
Function Name: gather_requirements
Input Params: The starting address of the node where collected chocolates will be added
              one by one as collected
Return Type: Updated starting address
Description: Collect the input one by one and add the node to the end of the list.
             You need to add a routine that will check if we have required quantity
             of desired chocolates. Till then keep collecting the input.
**/
CF * gather_requirements(CF * process )
{

    return process;
}



/**
Function Name: melt_and_prepare
Input Params: The starting address of the node where collected chocolates are available
Return Type: NILL
Description: Melt the chocolates in order as specified:
             200 KitKat
             10 Silk
             30 Bourneville
             200 Wafers
             30 Lint
             The chocolates may be available in different nodes at various positions

**/
void melt_and_prepare(CF * process)
{

}


int main()
{
    CF *process = NULL;

    printf("\nThe preparation has begin at...\n");
    time_t start;
    start = time(NULL);
    printf(ctime(&start));
    printf("\n\n");

    /// Call the functions to gather, melt and prepare
    process = gather_requirements(process);
    melt_and_prepare(process);


    printf("\nSecret Recipe Chocolate is now Ready\n");
    printf("\n\n");
    printf("\nThe preparation ended at...\n");
    time_t end;
    end = time(NULL);
    printf(ctime(&end));
    printf("\n\n");

    return 0;
}
