#include <stdio.h>
#include <stdlib.h>

typedef char linktype;
typedef struct linklist{
    linktype data;
    struct linklist *next;
}linklist;
void linklistinit(linklist **head)
{
    if(head == NULL)
    {
        return;
    }
    *head = NULL;
}
void linklistprint(linklist *head)
{
    if(head == NULL)
    {
        return;
    }
    linklist *cur = head;
    while(cur != NULL)
    {
        printf("%c",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

linklist * creat(linktype value)
{
    linklist *newnode = (linklist*)malloc(sizeof(linklist));
    if(newnode == NULL)
    {
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
void linklist_pushback(linklist **head,linktype value)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        *head = creat(value);
        return;
    }
    linklist *new = creat(value);
    linklist *cur = *head;
    while(cur ->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new;
}
void linklist_popback(linklist **head)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        return;
    }
    linklist *cur = *head;
    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}
void linklist_pushfront(linklist **head,linktype value)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        *head = creat(value);
        return;
    }
    linklist *new = creat(value);
    new->next = *head;
    *head = new;
}
void linklist_popfront(linklist **head)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        return;
    }
    linklist *cur = *head;
    *head = (*head)->next;
    free(cur);
    cur = NULL;
}
linklist *linklist_find(linklist *head,linktype value)
{
    if(head == NULL)
    {
        return NULL;
    }
    linklist *cur = head;
    while(cur != NULL)
    {
        if(cur->data == value)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
void linklist_insertpos(linklist **head,linklist *pos,linktype value)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        *head = creat(value);
        return;
    }
    linklist *new = creat(value);
    new->next = pos->next;
    pos->next = new;
}

void linklist_revers(linklist *head)
{
    if(head == NULL)
    {
        return;
    }
    linklist_revers(head->next);
    printf("%c",head->data);
}
int main()
{
    linklist *head;
    linklistinit(&head);
    linklist_pushback(&head,'a');
    linklist_pushback(&head,'b');
    linklist_pushback(&head,'c');
    linklist_pushback(&head,'d');
    linklistprint(head);
    linklist_popback(&head);
    linklistprint(head);
    linklist_pushfront(&head,'x');
    linklistprint(head);
    linklist_popfront(&head);
    linklistprint(head);
    linklist *cur = linklist_find(head,'b');
    printf("%c %p\n",cur->data,cur);
    linklist_insertpos(&head,linklist_find(head,'b'),'x');
    linklistprint(head);
    linklist_revers(head);
    return 0;
}
