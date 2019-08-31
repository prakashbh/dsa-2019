#include "message_service.c"

int main()
{
    STACK s1, s2;
    int choice = 0;

    initialize_stacks(&s1, &s2);

    while(1)
    {
        printf("\nMessage Service Simulation\n");
        printf("\n******** MENU ********\n");
        printf("1-View the Advertised message\n");
        printf("2-Update hour\n");
        printf("3-Print the status\n");
        printf("4-Exit\n");
        printf("***********************\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1: view_current_message(&s1, &s2);
                    break;

            case 2: update_hour(&s1, &s2);
                    printf("The message advertisement is changed\n");
                    break;

            case 3: print(&s1, &s2);
                    break;

            case 4: printf("Program will will be terminated\n\n");
                    exit(0);
        }
    }

    return 0;
}
