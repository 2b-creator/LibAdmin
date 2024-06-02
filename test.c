#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void test()
{
    nodes *head = NULL; // null
    // books
    book book1, book2, book3;
    strcpy(book1.title, "C Programming");
    strcpy(book1.author, "Dennis Ritchie");
    book1.book_id = 1;

    strcpy(book2.title, "Data Structures");
    strcpy(book2.author, "John Doe");
    book2.book_id = 2;

    strcpy(book3.title, "Algorithms");
    strcpy(book3.author, "Jane Smith");
    book3.book_id = 3;

    // 插入示例节点到链表
    head = insertNode(head, book1);
    head = insertNode(head, book2);
    head = insertNode(head, book3);

    displayList(head);
    char strs[] = "Data Structures";
    // 删除指定节点（例如，删除 ID 为 2 的节点）
    head = deleteNodeName(head, strs);

    // 可以继续插入更多节点、删除其他节点或进行其他操作
    printf("Updated list after deletion:\n");
    displayList(head);
}