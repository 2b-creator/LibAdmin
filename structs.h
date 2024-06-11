#include <time.h>
#define CHAR_MAX_OCC 50

typedef struct Lenders
{
    char name[CHAR_MAX_OCC];
    struct tm lend_time;
} lender;

typedef struct Books
{
    char title[CHAR_MAX_OCC];
    char author[CHAR_MAX_OCC];
    int book_id;
    int this_lend;
    struct Lenders lender;
} book;

typedef struct BookNodes
{
    struct Books book_data;
    struct BookNodes *next;
} nodes;