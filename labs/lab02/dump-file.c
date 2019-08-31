#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 5

struct time
{
    int hh;
    int mm;
    int ss;
};

struct stack
{
    struct time t[STACKSIZE];
    int top;
};
typedef struct stack STACK;

int empty(STACK *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int full(STACK *s)
{
    if (s->top == STACKSIZE - 1)
        return 1;
    else
        return 0;
}

void push(STACK *s, struct time dt)
{
    s->top++;
    s->t[s->top] = dt;
    printf("\nTime is successfully pushed\n");

    /* Alternate
    s->t[s->top].hh = dt.hh;
    s->t[s->top].mm = dt.ss;
    s->t[s->top].ss = dt.ss;
    */
}

void pop(STACK *s, struct time *dt)
{
    *dt = s->t[s->top];
    s->top--;
}

void print(STACK *s)
{
    int i;
    printf("\nStack contents are:\n");
    for (i = s->top; i>= 0; i--)
    {
        printf("%d:%d:%d\n",s->t[i].hh, s->t[i].mm, s->t[i].ss);
    }
}

int main()
{
    STACK s;
    s.top = -1;
    int choice;
    struct time td;
    while(1)
    {
        printf("\n**MENU**\n\n");
        printf("1-Push Time\n2-Pop Time\n3-Print\n4-Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: if(full(&s))
                        printf("\nSTACK FULL. Cannot Insert\n");
                    else
                    {
                        printf("Enter the time details as HH MM SS\n");
                        scanf("%d %d %d",&td.hh, &td.mm, &td.ss);
                        push(&s, td);
                    }
                    break;

            case 2: if(empty(&s))
                        printf("\nSTACK EMPTY. Cannot Remove\n");
                    else
                    {
                        pop(&s, &td);
                        printf("\nPopped time is\n");
                        printf("%d:%d:%d",td.hh, td.mm, td.ss);
                    }
                    break;

            case 3:if(empty(&s))
                        printf("\nSTACK EMPTY. Cannot Print\n");
                    else
                        print(&s);
                    break;

            case 4: printf("\nProgram Terminating\n");
                    exit(1);
        }
    }
    return 0;
}
