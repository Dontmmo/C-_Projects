#include <stdio.h>
#include "..\Include/struct.h"
#include "..\Include/struct.c"
#include <stdlib.h>
#include <stdint.h>

signed char proceeding();

int main()
{
    uint8_t choice = 0;
    uint8_t _ID = 0;
    signed char options = 0;
    while (1)
    {
        printf("Welcome To Your Library Management CLI App: ");
        printf("\nWhat do you want to do?");
        printf("\n1- Add a Book.");
        printf("\n2- Search a Book.");
        printf("\n3- Show a Book.");
        printf("\n4- Delete a Book.");
        printf("\n5- Update Book Status.");
        printf("\n6- Display All Books.");
        printf("\n7- Exit.");
        printf("\nEnter Your Choice: ");
        scanf(" %hhd", &choice);
        switch (choice)
        {
        case 1:
            Add_Book();
            break;
        case 2:
            fflush(stdin);
            options = Search_Book();
            if (options == -1)
            {
                printf("Do you want to add a book?\n");
                if (proceeding() == 'y')
                {
                    Add_Book();
                }
            }
            break;
        case 3:
            printf("Enter the ID of The Book.");
            scanf(" %hhd", &_ID);
            Show_Book(_ID);
            break;
        case 4:
            delete_Book();
            break;
        case 5:
            printf("Enter the ID of The Book.");
            scanf(" %hhd", &_ID);
            Update_status(_ID);
            break;
        case 6:
            options = Display_Books();
            if (options == -1)
            {
                printf("Do you want to add a book?\n");
                if (proceeding() == 'y')
                {

                    Add_Book();
                }
            }

            break;
        case 7:
            Exit_Prog();
            break;

        default:
            printf("INVALID INPUT TRY AGAIN.");
            break;
        }
    }
}
signed char proceeding()
{
    uint8_t ans = 0;
    while (1)
    {
        fflush(stdin);
        scanf(" %c", &ans);
        if (ans == 'n' || ans == 'N')
        {
            return 'n';
        }
        else if (ans == 'y' || ans == 'Y')
        {
            return 'y';
        }
        else
        {
            printf("INVALID INPUT TRY AGAIN.");
        }
    }
}