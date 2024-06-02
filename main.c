#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "ui.h"

#define BOOK_MAX 50
#define TITLE_MAX 50
#define AUTHOR_MAX 50

int main(void)
{
    nodes *head = NULL; // null
    int choser = 0;
    char title[TITLE_MAX];
    char author[AUTHOR_MAX];
    int id = 0;
    book books;
starts:
    choser = 0;
    utils();
    while (!(choser == 1 || choser == 2 || choser == 3 || choser == 4))
    {
        scanf("%d", &choser);
    }
    switch (choser)
    {
    case 1:
        sub_1();
        scanf("%s %s %d", books.title, books.author, &books.book_id);
        head = insertNode(head, books);
        goto starts;
        break;
    case 2:
        choser = 0;
        sub_2();
        while (!(choser == 1 || choser == 2 || choser == 3 || choser == 4))
        {
            scanf("%d", &choser);
        }
        switch (choser)
        {
        case 1:
            printf("Please enter your id: ");
            scanf("%d", &id);
            head = deleteNode(head, id);
            printf("Compelete!\n");
            goto starts;
            break;
        case 2:
            printf("Please enter the book title: ");
            scanf("%s", title);
            head = deleteNodeName(head, title);
            printf("Compelete!\n");
            goto starts;
            break;
        case 3:
            printf("Please enter the book author: ");
            scanf("%s", author);
            head = deleteNodeAuthor(head, author);
            printf("Compelete!\n");
            goto starts;
            break;
        default:
            break;
        }
        break;
    case 3:
        choser = 0;
        sub_3();
        while (!(choser == 1 || choser == 2 || choser == 3 || choser == 4))
        {
            scanf("%d", &choser);
        }
        switch (choser)
        {
        case 1:
            displayList(head);
            goto starts;
            break;
        case 2:
            printf("Please enter your book id: ");
            scanf("%d", &id);
            displayID(head, id);
            goto starts;
            break;
        case 3:
            printf("Please enter author");
            scanf("%s", author);
            displayAuthor(head, author);
            goto starts;
            break;
        case 4:
            printf("Please enter title");
            scanf("%s", title);
            displayTitle(head, title);
            goto starts;
            break;
        default:
            break;
        }
        break;
    }
    return 0;
}