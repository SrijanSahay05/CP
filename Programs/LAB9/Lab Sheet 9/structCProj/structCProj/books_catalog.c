#include "books_catalog.h"

void addBookToCatalog(BOOK book1)
{
    if (count < MAX_SIZE)
    {
        booksCatalog[count] = book1;
        count++;
    }
    else
    {
        printf("Catalog is full. Cannot add more books.\n");
    }
}

void printBookCatalog()
{
    for (int i = 0; i < count; i++)
    {
        printf("Book %d:\n", i + 1);
        printBook(booksCatalog[i]);
        printf("\n");
    }
}

void sortBookCatalogOnID()
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (booksCatalog[j].ID > booksCatalog[j + 1].ID)
            {
                BOOK temp = booksCatalog[j];
                booksCatalog[j] = booksCatalog[j + 1];
                booksCatalog[j + 1] = temp;
            }
        }
    }
}