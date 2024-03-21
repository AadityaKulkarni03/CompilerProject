// Name:ANISH TAORI                    ID: 2021A7PS0939P
// Name:GARVIT SINGHAL                 ID:  2021A7PS2226P
// Name:ROSHAN BAGLA                   ID: 2021A7PS2538P
// Name:ADITYA DESHPANDE               ID: 2021A7PS2681P
// Name:AADITYA KULKARNI               ID: 2021A7PS0426P
// Name:YASH KANDOI                    ID: 2021A7PS2417P

#ifndef LEX_DEF_
#define LEX_DEF_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "parserDef.h"

#define HASH_SIZE 600
#define BUFF_SIZE 1024

// Symbol Table Structure
struct record
{
    int token;
    int lexeme;
    int line_no;
};

struct table
{
    struct record *table;
    int size;
};

typedef struct twinBuffer
{
    char *buffer1;
    char *buffer2;
} twinBuffer;

// Define the structure for the node in the hash table
typedef struct hashnode
{
    char lexeme[50];
    struct hashnode *next;
} HashNode;

// Define the structure for the hash table
typedef struct
{
    HashNode *buckets[HASH_SIZE];
} HashSet;

typedef struct record Record;
typedef HashSet TokenMap;
typedef HashSet LexemeArray;
typedef struct table Symbol;

#endif