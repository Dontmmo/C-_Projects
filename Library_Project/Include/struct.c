#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

static uint8_t Book_last_ID = 0;
static uint8_t BooksStored = 0;
Book_Data Books[100];
// **Add Book** Input book details: ID, Title, Author, Year, Status (Available/Borrowed)
void Add_Book(void)
{
    
    fflush(stdin);
    Books[BooksStored].ID = Book_last_ID + 1;
    printf("Enter Title: ");
    scanf(" %[^\n]s",Books[BooksStored].Title ); // searched about it
    /*
    what I understood was that [^\n] is telling scanf to remove leading whitespace and take input untill you face \n
    */
    
    printf("Enter Author Name: ");
    scanf(" %[^\n]s",Books[BooksStored].Author );
    printf("Enter Year: ");
    fflush(stdin);
    scanf("%u", &Books[BooksStored].year);
    do
    {
        printf("Is it (Borrowed or Availble ) Enter ( 0 , 1):  ");
        uint8_t val = 0;
        fflush(stdin);
        scanf(" %hhu", &val);
        if (val == 0 || val == 1)
        {
            Books[BooksStored].IsAvailble = val;
            break;
        }
        else
        {
            printf("INVALID INPUT TRY AGAIN\n");
        }
    } while (1);

    BooksStored++;
    Book_last_ID++;
    printf("Book Added Successfully. ");
}

void Show_Book(uint8_t ID) // used to show The Data of a Single Book
{

    if (ID <= 0 || ID > 100 || ID > Book_last_ID)
    {
        printf("Invalid ID to show\n");
        return;
    }

    printf("-ID: %hhd\n", ID);
    printf("-Title: %s\n", Books[ID-1].Title);
    printf("-Author Name: %s\n", Books[ID -1].Author);
    printf("-Year: %u\n", Books[ID-1].year);
    if (Books[ID-1 ].IsAvailble == 0)
    {
        printf("Status: Borrowed\n");
    }
    else
    {
        printf("Status: Availble\n");
    }
}

// **Search Book** - Search by ID  (partial or full match).
signed char Search_Book(void) // searching by ID using binary search if
{
    
    uint8_t wanted_ID = 0;
    if (BooksStored == 0)
    {
        printf("NO Books To search\n");
        return -1; // -1 to return in main to ask if he want to add book instead
    }
    while (1)
    {
        printf("Enter The ID: ");
        scanf(" %hhd", &wanted_ID);
        if (wanted_ID <= 0 || wanted_ID > 100 || wanted_ID > Book_last_ID)
        {
            printf("Invalid input.\n Please Enter Valid ID\n");
        }
        else
        {
            break;
        }
    }

    uint8_t High = Book_last_ID;
    uint8_t Low = 1; // least ID We choose
    uint8_t Mid = 0;
    while (Low <= High)
    {
        Mid = (High + Low) / 2;
        if (Mid == wanted_ID)
        {
            printf("BOOK Found");
            Show_Book(wanted_ID);
            return 0;
        }
        else if (Mid < wanted_ID)
        {
            Low = Mid + 1;
        }
        else if (Mid > wanted_ID)
        {
            High = Mid - 1;
        }
    }
    printf("NOT FOUND\n");
    return 0; // not important value
}
/* **Delete Book** - Remove a book by its ID.
*/
void delete_Book(void)
{
    
    uint8_t wanted_ID = 0;
    if (BooksStored == 0)
    {
        printf("NO Books To Delete\n");
        return;
    }
    while (1)
    {
        printf("Enter The ID: ");
        fflush(stdin);
        scanf(" %hhd", &wanted_ID);
        if (wanted_ID <= 0 || wanted_ID > 100 || wanted_ID > Book_last_ID)
        {
            printf("Invalid input.\n Please Enter Valid ID\n");
        }
        else
        {
            break;
        }
    }
    uint8_t ans = 0;
    Show_Book(wanted_ID);
    while (1)
    {
        printf("\nDo you still want to delete it? (y,n)  ");
        fflush(stdin);
        scanf(" %c", &ans);
        if (ans == 'n' || ans == 'N')
        {
            return;
        }
        else if (ans == 'y' || ans == 'Y')
        {
            break;
        }
        else
        {
            printf("INVALID INPUT TRY AGAIN.");
        }
    }

    // method of deleting depend on making the last book take the Id we want to remove
    Books[wanted_ID - 1] = Books[Book_last_ID];
    Books[wanted_ID - 1].ID = wanted_ID;
    Books[Book_last_ID].ID = 0; // zero is not used and Can be used to notify it is not usable
    Book_last_ID--;
    BooksStored--;
    printf("Book Is Deleted successfully.");

}
// **Display All Books**  - Show all books in a clean and formatted way.
signed char Display_Books(void)
{
    
    if (BooksStored == 0)
    {
        printf("NO BOOKS TO SHOW.");
        return -1; // -1 is used to ask the user if he want to add a book instead
    }
        int index = 0;
    for ( index = 0; index < BooksStored; index++)
    {
    printf("-ID: %hhd\n", index+1);
    printf("-Title: %s\n", Books[index ].Title);
    printf("-Author Name: %s\n", Books[index ].Author);
    printf("-Year: %u\n", Books[index ].year);
    if (Books[index ].IsAvailble == 0)
    {
        printf("Status: Borrowed\n");
    }
    else
    {
        printf("Status: Availble\n");
    }
        
    }
    return 0;
}
// **Update Status** - take ID - Change a book's status from Available to Borrowed or vice versa.

void Update_status(uint8_t ID)
{
    if (Books[ID - 1].IsAvailble == 0)
    {
        printf("Status: Borrowed\n");
    }
    else
    {
        printf("Status: Availble\n");
    }
    Books[ID - 1].IsAvailble = Books[ID - 1].IsAvailble ^ (0b00000001); // toggling the value
    printf("Status Updated\n");
}
// **Exist**

void Exit_Prog()
{
    
    uint8_t ans = 0;
    while (1)
    {
        printf("\nDo you still want to Exit? (y,n)  ");
        fflush(stdin);
        scanf(" %c", &ans);
        if (ans == 'n' || ans == 'N')
        {
            return;
        }
        else if (ans == 'y' || ans == 'Y')
        {
            printf("Happy to serve you!\n ");
            exit(0); // searched for it
        }
        else
        {
            printf("INVALID INPUT TRY AGAIN.");
        }
    }
}
