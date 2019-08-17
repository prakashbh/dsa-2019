/*

Pack N Parcel is a delivery agency. The different kinds of delivery made are home delivery,
through email and voice mails. The program below explains the process.

*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Function prototypes
void get_transactions();
void business()

// Structure to define home delivery
struct address
{
    int house_number;
    char house_name[20];
    char street[20]
    int pincode;
}

// Structure to define mail delivery
struct web
{
    char mail_id[30]
}

// Structure to define voice delivery
struct voice_mail
{
    int code;
    int number_part1;
    int number_part2;
}

// A structure combining all 3 delivery modes.
struct delivery_mode
{
    struct addr a;
    struct web w;
    struct voice_mail v;
}

// Structure for Pack N Parcel
struct packnparcel
{
    char name[20];
    int delivery_type;
    struct delivery_mode d;
    char month;
    int year;
    float charges;
} p[5];

// main() calls the two functions
int main()
{
    printf("Enter the input\n");
    get_transactions();
    business();
    return 0;
}

void get_transactions()
{
    int i = 0;
    int temp_type;

    // Get 5 inputs from the user
    for(i = 0; i < 5; i++)
    {
        printf("Enter name of customer, month name, and year\n");
        scanf("%s%s%d", p[i].name, p[i].month, p[i].year);

        // Ask for the delivery type
        printf("Enter Delivery Type: 1 - Home delivery\n2 - Web\n3-Voice Mail\n");
        scanf("%d", p[i].delivery_type);

       // Depending on type input by user,
       // get the values for appropriate structure members
      // Make a note of how various structure members are accessed
        if(p[i].delivery_type ==  1)
        {
            printf("Enter input for House No, Name, street, Pincode\n");
            scanf("%d%s%s%d",&p[i].d.a.house_number, p[i].d.a.house_name, p[i].d.a.street, &p[i].d.a.pincode);
            p[i].charges = 250.00;
        }

        if(p[i].delivery_type == 2)
        {
            printf("Enter mail Id\n");
            scanf("%s", p[i].d.w.mail_id);
            p[i].charges = 100.00;
        }

        if(p[i].delivery_type = 3)
        {
            printf("Enter code, Part1, part2\n");
            scanf("%d%d%d", p[i].d.v.code, p[i].d.v.number_part1, p[i].d.v.number_part2);
            p[i].charges = 200.00;
        }
    }

}

// Find out the transactions happened over the day
void business()
{
    int i = 0;
    float home_delivery_charges = 0, web_charges = 0, voice_charges = 0;
    float total_charges = 0;
    for(i = 0; i < 5; i++)
    {
        if(p[i].delivery_type == 1)
            home_delivery_charges += p[i].charges;
        else if (p[i].delivery_type == 2)
            web_charges += p[i].charges;
        else
            voice_charges += p[i].charges;
    }

    // Print the business over different modes
    printf("The Businness done over each type are..\n");
    printf("Home delivery Business = %f\n", home_delivery_charges);
    printf("Web mail Business = %f\n", web_charges);
    printf("Voice Businness = %f\n", voice_charges);

    // Print the total business
    printf("Total Business = %f\n", home_delivery_charges + web_charges + voice_charges);
}
