#include "functions.c"
nodes *insertNode(nodes *head, book newBook);
nodes *deleteNode(nodes *head, int bookID);
void displayList(nodes *head);
void displayTitle(nodes *head, char *title);
void displayAuthor(nodes *head, char *author);
void displayID(nodes *head, int id);
nodes *deleteNodeName(nodes *head, char title[]);
nodes *deleteNodeAuthor(nodes *head, char *author);