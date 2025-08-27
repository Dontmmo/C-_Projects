#ifndef _STRUCT_H_
#define _STRUCT_H_
#include <stdint.h>
#pragma pack(push,4)
#define StrSize 20
#define num_of_books 100

typedef enum 
{
    Borrowed = 0,
    Availble
} Status;

typedef struct
{
    unsigned int year  ;
    Status IsAvailble ; // only one and zero
    uint8_t ID  ;// enough for 100 books 7 bits holds for 128
    unsigned char Title[StrSize];
    unsigned char Author[StrSize];
} Book_Data;

void Add_Book(void);
void Show_Book(uint8_t ID);

signed char Search_Book(void);

void delete_Book(void);

signed char Display_Books(void);

void Update_status(uint8_t ID);

void Exit_Prog();

#endif