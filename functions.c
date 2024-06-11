#include <stdlib.h>
#include "structs.h"

nodes *insertNode(nodes *head, book newBook)
{
    nodes *newNode = (nodes *)malloc(sizeof(nodes));
    if (newNode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->book_data = newBook;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        nodes *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

nodes *deleteNode(nodes *head, int bookID)
{
    // 如果链表为空，直接返回
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    nodes *temp = head;
    nodes *prev = NULL;

    // delete head
    if (temp != NULL && temp->book_data.book_id == bookID)
    {
        head = temp->next;
        free(temp); // free
        printf("Node with ID %d deleted successfully.\n", bookID);
        return head;
    }

    // 遍历链表找到要删除的节点及其前一个节点
    while (temp != NULL && temp->book_data.book_id != bookID)
    {
        prev = temp;
        temp = temp->next;
    }

    // 如果节点不存在
    if (temp == NULL)
    {
        printf("Node with ID %d not found.\n", bookID);
        return head;
    }

    // 跳过要删除的节点
    prev->next = temp->next;
    free(temp); // 释放内存
    printf("Node with ID %d deleted successfully.\n", bookID);
    return head;
}

nodes *deleteNodeName(nodes *head, char title[])
{
    // 如果链表为空，直接返回
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    nodes *temp = head;
    nodes *prev = NULL;
    if (temp != NULL && strcmp(temp->book_data.title, title) == 0)
    {
        head = temp->next;
        free(temp); // free
        printf("Node with title %s deleted successfully.\n", title);
        return head;
    }

    while (temp != NULL && strcmp(temp->book_data.title, title) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with title %s not found.\n", title);
        return head;
    }

    // 跳过要删除的节点
    prev->next = temp->next;
    free(temp); // 释放内存
    printf("Node with title %s deleted successfully.\n", title);
    return head;
}

nodes *deleteNodeAuthor(nodes *head, char *author)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    nodes *temp = head;
    nodes *prev = NULL;
    if (temp != NULL && strcmp(temp->book_data.author, author) == 0)
    {
        head = temp->next;
        free(temp); // free
        printf("Node with title %s deleted successfully.\n", author);
        return head;
    }
    while (temp != NULL && strcmp(temp->book_data.author, author) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node with title %s not found.\n", author);
        return head;
    }

    // 跳过要删除的节点
    prev->next = temp->next;
    free(temp); // 释放内存
    printf("Node with title %s deleted successfully.\n", author);
    return head;
}

void displayList(nodes *head)
{
    nodes *current = head;

    // 遍历链表并输出每个节点的信息
    while (current != NULL)
    {
        printf("Book ID: %d\n", current->book_data.book_id);
        printf("Title: %s\n", current->book_data.title);
        printf("Author: %s\n", current->book_data.author);
        printf("Is lend: %s\n", current->book_data.this_lend ? "yes" : "no");
        printf("-------------\n");
        if (current->book_data.this_lend)
        {
            printf("Lend data:\n");
            printf("Name: %s, Date: %d-%d-%d, ", current->book_data.lender.name, current->book_data.lender.lend_time.tm_year, current->book_data.lender.lend_time.tm_mon, current->book_data.lender.lend_time.tm_mday);
            printf("Time: %d:%d:%d", current->book_data.lender.lend_time.tm_hour, current->book_data.lender.lend_time.tm_min, current->book_data.lender.lend_time.tm_sec);
        }

        printf("\n");

        // 移动到下一个节点
        current = current->next;
    }
}

void displayTitle(nodes *head, char *title)
{
    nodes *current = head;
    while (current != NULL)
    {
        if (strcmp(current->book_data.title, title) == 0)
        {
            printf("Book ID: %d\n", current->book_data.book_id);
            printf("Title: %s\n", current->book_data.title);
            printf("Author: %s\n", current->book_data.author);
            printf("Is lend: %d", current->book_data.this_lend);
            printf("\n");
        }

        // 移动到下一个节点
        current = current->next;
    }
}

void displayAuthor(nodes *head, char *author)
{
    nodes *current = head;
    while (current != NULL)
    {
        if (strcmp(current->book_data.author, author) == 0)
        {
            printf("Book ID: %d\n", current->book_data.book_id);
            printf("Title: %s\n", current->book_data.title);
            printf("Author: %s\n", current->book_data.author);
            printf("Is lend: %d", current->book_data.this_lend);
            printf("\n");
        }

        // 移动到下一个节点
        current = current->next;
    }
}

void displayID(nodes *head, int id)
{
    nodes *current = head;
    while (current != NULL)
    {
        if (current->book_data.book_id == id)
        {
            printf("Book ID: %d\n", current->book_data.book_id);
            printf("Title: %s\n", current->book_data.title);
            printf("Author: %s\n", current->book_data.author);
            printf("Is lend: %d", current->book_data.this_lend);
            printf("\n");
        }

        // 移动到下一个节点
        current = current->next;
    }
}

void changeLendStatus(nodes *head, int id, char *name, char *date, char *time)
{
    nodes *current = head;
    while (current != NULL)
    {
        if (current->book_data.book_id == id)
        {
            current->book_data.this_lend = 1;
            strcpy(current->book_data.lender.name, name);
            sscanf(date, "%d-%d-%d", &current->book_data.lender.lend_time.tm_year, &current->book_data.lender.lend_time.tm_mon, &current->book_data.lender.lend_time.tm_mday);
            sscanf(time, "%d:%d:%d", &current->book_data.lender.lend_time.tm_hour, &current->book_data.lender.lend_time.tm_min, &current->book_data.lender.lend_time.tm_sec);
        }
        current = current->next;
    }
}