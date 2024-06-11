void utils()
{
    printf("1. Add books\n");
    printf("2. Delete books\n");
    printf("3. Search books\n");
    printf("4. Lend books\n");
    printf("5. Exit\n");
    printf("Please enter a number: ");
}

void sub_1()
{
    printf("Please enter a book with title, auther and id in order. You need input as this format:\n");
    printf("C_Programming Dennis_Ritchie 114514\n");
    printf("Make sure there is no whitespace in every input but split them as a single element.\n");
}
void sub_2()
{
    printf("1. Delete with id\n");
    printf("2. Delete with title\n");
    printf("3. Delete with author\n");
}
void sub_3()
{
    printf("1. List all books\n");
    printf("2. Search with id\n");
    printf("3. Search with author\n");
    printf("4. Search with title\n");
}
void sub_4(){
    printf("Please enter the borrowed book ID, borrower, borrowing date and time, separated by spaces. The date and time should be entered in the format of yyyy-MM-dd HH:mm:ss, for example:\nSunXiaochuan 114514 2018-3-14 19:19:20\n");
}