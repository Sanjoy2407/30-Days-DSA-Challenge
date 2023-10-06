#include<stdio.h>
#include<stdlib.h>

struct intNode
{
    int element;
    struct intNode *next;
} intNode;

struct intNode *addIntNodeSorted(struct intNode *start, int elem)
{
    struct intNode *t = NULL;
    if (start == NULL)
    {
        start = (struct intNode *)malloc(sizeof(struct intNode));
        start->element = elem;
        start->next = NULL;
        t = start;
        return start;
    }
    else if (start->element > elem)
    {
        t = (struct intNode *)malloc(sizeof(struct intNode));
        t->element = elem;
        t->next = start;
        start = t;
        return start;
    }
    struct intNode *head = start, *tail = start;
    while (head != NULL)
    {
        if (head->element > elem)
        {
            break;
        }
        tail = head;
        head = head->next;
    }
    t = (struct intNode *)malloc(sizeof(struct intNode));
    t->element = elem;
    t->next = head;
    tail->next = t;
    return start;
}

struct intNode *mergeSNodeSorted(struct intNode *start1, struct intNode *start2)
{
    struct intNode *last = NULL, *third = NULL;
    if (start1->element < start2->element)
    {
        third = last = start1;
        start1 = start1->next;
        third->next = NULL;
    }
    else
    {
        third = last = start2;
        start2 = start2->next;
        third->next = NULL;
    }
    while (start1 && start2)
    {
        if (start1->element < start2->element)
        {
            last->next = start1;
            last = start1;
            start1 = start1->next;
            last->next = NULL;
        }
        else
        {
            last->next = start2;
            last = start2;
            start2 = start2->next;
            last->next = NULL;
        }
    }
    if (start1)
    {
        last->next = start1;
    }
    if (start2)
    {
        last->next = start2;
    }
    return third;
}

void printLL(struct intNode *start)
{
    struct intNode *head = start;
    while (head != NULL)
    {
        printf("%d -> ", head->element);
        head = head->next;
    }
    printf("\n");
}

int main () {


struct intNode *start1 = NULL, *start2 = NULL;
            printf("Enter the Number of Elements for L1\n");
            int x = 0, ele = -1;
            scanf("%d", &x);
            for (int i = 0; i < x; i++)
            {
                printf("Enter %d Element\n", (i + 1));
                scanf("%d", &ele);
                start1 = addIntNodeSorted(start1, ele);
            }
            printLL(start1);
            printf("Enter the Number of Elements for L2\n");
            scanf("%d", &x);
            for (int i = 0; i < x; i++)
            {
                printf("Enter %d Element\n", (i + 1));
                scanf("%d", &ele);
                start2 = addIntNodeSorted(start2, ele);
            }
            printLL(start2);
            struct intNode *merge = mergeSNodeSorted(start1, start2);
            printf("Merged List is ...\n");
            printLL(merge);



    return 0;
}
