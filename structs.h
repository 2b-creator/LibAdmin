typedef struct Books
{
    char title[50];
    char author[50];
    int book_id;
} book;

typedef struct BookNodes
{
    struct Books book_data;
    struct BookNodes *next;
} nodes;