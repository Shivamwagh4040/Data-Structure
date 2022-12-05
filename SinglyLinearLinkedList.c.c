#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));  // 1 Allocate memory

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)  // If linked list is empty
    {
        *First = newn;
    }
    else                // If linked list contain atleast one node
    {
        newn->next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));  // 1 Allocate memory
    PNODE temp = *First;

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)  // If linked list is empty
    {
        *First = newn;
    }
    else                // If linked list contain atleast one node
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements from the Linked list are : \n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
        First = First -> next;
    }
    printf("NULL \n");
}

int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First -> next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)  // A
    {
        return;
    }
    else if((*First) -> next == NULL) // B
    {
        free(*First);
        *First = NULL;
    }
    else  // C
    {
        (*First) = (*First) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)  // Empty LL
    {
        return;
    }
    else if((*First) -> next == NULL) // 1 node in LL
    {
        free(*First);
        *First = NULL;
    }
    else  // More than 1 node in LL
    {
        while((temp->next->next) != NULL)
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

void InsertAtPos(PPNODE First, int no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        printf("Invalid Position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,no);
    }

    else if(ipos == NodeCnt + 1)
    {
        InsertLast(First,no);
    }

    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *First;

        for(iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > NodeCnt))
    {
        printf("Invalid Position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First);
    }

    else if(ipos == NodeCnt)
    {
        DeleteLast(First);
    }

    else
    {
        temp1 = *First;

        for(iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp1 = temp1 -> next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next; //temp1->next = temp->next->next
        free(temp2);
    }
}

int main()
{
    // struct node * Head = NULL;
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);
    Display(Head);
    iRet = Count(Head);
    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&Head,101);
    InsertLast(&Head,111);
    InsertLast(&Head,121);
    Display(Head);
    iRet = Count(Head);
    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&Head,105,5);
    Display(Head);
    iRet = Count(Head);
    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&Head,5);
    Display(Head);
    iRet = Count(Head);
    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of nodes arte : %d\n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of nodes are : %d\n",iRet);

    return 0;
}