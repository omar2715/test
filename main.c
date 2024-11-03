#include <stdio.h>
#include <stdlib.h>

struct person
{
    int data ;
    struct person* next;
    struct person* previous;
} * Head , *Tail ;

int getByIndex( int );

struct person* create( int ) ;

void add( int );

int del( int );

void main()
{
    add(1);
    add(2);
    add(3);
    add(45);
    printf("Data = %d\n",Tail->previous->previous->data);


}

struct person* create( int data )
{
    struct person* ptr = malloc(sizeof( struct person ) );

    if(ptr)
    {
        ptr->data =  data ;
        ptr->next = NULL ;
        ptr->previous = NULL ;
    }
    return ptr ;
}


void add( int data )
{
    struct person* ptr = create( data );
    if(ptr)
    {
        if( Head == NULL )
        {
            Head = ptr;
            Tail = ptr;
        }
        else
        {
            Tail->next = ptr;
            ptr->previous = Tail;
            Tail = ptr ;
        }

    }
    else
    {
        printf("FAILED\n");
        return;
    }
}

int getByIndex( int index )
{
    if(index < 1)
    {
        printf("INVALID INDEX\n");
        return -1 ;
    }
    struct person* ptr = Head;
    for( int i = 0 ; i < index - 1 ; i++ )
    {
        if(ptr->next)
            ptr = ptr->next;
        else
        {
            printf("INVALID INDEX\n");
            return -1 ;
        }
    }
    return ptr->data ;
}

/*int del( int index )
{
    struct person* ptr;
    if(index < 1)
    {
        printf("INVALID INDEX\n");
        return ;
    }
    if( Head == NULL )
    {
        printf("LIST IS ALREADY EMPTY\n");
        return;
    }
    else
    {
        if( Head == Tail )
        {
            free(Head);
            Head = NULL;
            Tail = NULL;
            return;
        }
        ptr = Head;
        for( int i = 0 ; i < index -1 ; i++ )
        {
            if(ptr->next)
                ptr = ptr->next;
            else
            {
                printf("INVALID INDEX\n");
                return ;
            }
        }

        if(ptr->next == NULL)
        {
            ptr = Tail;
            Tail=ptr->previous;
            free(ptr);
            return;
        }
        else
        {
            if(index == 0)
            {
                ptr=Head;
                Head= Head->next;
                ptr->next=Null;
                Head->previous=NULL;
                free(ptr);
            }

        }
    }
}*/
