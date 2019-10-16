#include <stdio.h>
#include <stdlib.h>

struct recommendation_data
{
    char movie_name[30];
    char recommendation_name[30];
    int viewers;
};

typedef struct recommendation_data RD;
RD search_list[200];
int global_count = 0;

/**
Function Name: welcome
Input Params: NILL
Return Type: void
Description: Prints a welcome message
**/
void welcome()
{
    int  i = 0;
    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n\t\t\t\tRECOMMENDATION ENGINE\n\n\n");

    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n");

}

/**
Function Name: load_from_file
Input Params: NILL
Return Type: void
Description: loads all the data available with recommendation engine into appropriate data structure
**/
void load_from_file()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("MovieIndex.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }

    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d", search_list[global_count].movie_name, search_list[global_count].recommendation_name,
                &search_list[global_count].viewers);
        printf("%s %s %d\n",search_list[global_count].movie_name, search_list[global_count].recommendation_name,
                search_list[global_count].viewers);
        global_count++;
    }

    fclose(fp);
}

int main()
{
    welcome();
    load_from_file();

    // TODO

    return 0;
}

