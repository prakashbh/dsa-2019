#ifndef MESSAGE_SERVICE_H_INCLUDED
#define MESSAGE_SERVICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKSIZE 5
#define TRUE 1
#define FALSE 0

struct message
{
    char message_data[30];
    int hour[2];
};

struct stack
{
    int top;
    int active;
    struct message items[STACKSIZE];
};

typedef struct stack STACK;

// Function declarations
int empty(STACK *);
void push(STACK * , struct message);
struct message pop(STACK *);
void peek( STACK *);
void print( STACK *, STACK *);
void initialize_stacks(STACK *, STACK *);
void view_current_message(STACK *, STACK *);
void update_hour(STACK *, STACK *);

#endif // MESSAGE_SERVICE_H_INCLUDED
