    // Doubly Circular Linear Linked List in C++.

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class DoublyCL
{
    public:
        PNODE First;
        PNODE Last;

        DoublyCL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int ipos, int no);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

DoublyCL :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

void DoublyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn -> next = First;
        (First) -> prev = newn;
        First = newn;
    }
    (First) -> prev = Last;
    (Last) -> next = First;
}

void DoublyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = newn;
        Last = newn;
    }
    else 
    {
        (Last) -> next = newn;
        newn -> prev = Last;
        Last = newn;
    }
    (First) -> prev = Last;
    (Last) -> next = First;
}

void DoublyCL :: Display()
{
    PNODE temp = First;
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    cout<<"Elements of Linked List are : "<<"\n";

    do
    {
        cout<<" | " <<temp -> data<<" | <=>";
        temp = temp -> next;
    } while (temp != Last -> next);
    cout<<"\n";
}

int DoublyCL :: Count()
{
    int iCnt = 0;
    PNODE temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return iCnt++;
    }
    do
    {
        iCnt++;
        temp = temp -> next;
    } while (temp != Last -> next);
    return iCnt++;
}

void DoublyCL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
    }
    else
    {
        (First) = First -> next;
        delete (Last) -> next;

        (First) -> prev = Last;
        (Last) -> next = First;
    }
}

void DoublyCL :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
    }
    else
    {
        Last = (Last) -> prev;
        delete (First) -> prev;

        (First) -> prev = Last;
        (Last) -> next = First;
    }
}

void DoublyCL :: InsertAtPos(int no, int ipos)
{
    int iCnt = 0;
    int iNodeCnt = Count();
    PNODE newn = NULL;
    PNODE temp = NULL;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;
        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    }
}

void DoublyCL :: DeleteAtPos(int ipos)
{
    int iCnt = 0;
    int iNodeCnt = Count();
    PNODE temp = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
    }
}

int main()
{
    int iRet = 0;
    DoublyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<"\n";

    obj.InsertAtPos(105,5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Nodes in Linked List are : "<<iRet<<"\n";

    return 0;
}