#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct prolific_potion
{
    char ingredient[30];
    int quantity;
    struct prolific_potion * prev;
    struct prolific_potion * next;
};

typedef struct prolific_potion PP;

PP * gather_ingredients(PP *);
void brew(PP *);

/**
Function Name: gather_ingredients
Input Params:  The starting address of the node where collected ingredients will be added
               one by one as collected
Return Type:   Updated starting address
Description:   Collect the input one by one and add the node to the end of the list.
               You need to add a routine that will check if we have required quantity
               of desired ingredients. Till then keep collecting the input.
**/
PP * gather_ingredients(PP * process )
{

    return process;
}



/**
Function Name: brew
Input Params:  The starting address of the node where collected ingredients are available
Return Type:   NILL
Description:   brew the materials in order as specified:
               30 cups of fluxweed
               20 bundles of knotgrass
               42 leeches
               50 Lacewing flies
               9 Bicorn horn
               The ingredients may be available in different nodes at various positions

**/
void brew(PP * process)
{

}


int main()
{
    PP *process = NULL;

    printf("\nThe preparation has begin at...\n");
    time_t start;
    start = time(NULL);
    printf(ctime(&start));
    printf("\n\n");

    /// Call the functions to gather, melt and prepare
    process = gather_ingredients(process);
    brew(process);

    printf("\nThe POTION is ready, The dark army can now be defeated again!\n");
    printf("\n\n");

    printf("\nThe preparation ended at...\n");
    time_t end;
    end = time(NULL);
    printf(ctime(&end));
    printf("\n\n");

    return 0;
}
