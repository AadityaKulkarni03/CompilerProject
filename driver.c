// Name:ANISH TAORI                    ID: 2021A7PS0939P
// Name:GARVIT SINGHAL                 ID:  2021A7PS2226P
// Name:ROSHAN BAGLA                   ID: 2021A7PS2538P
// Name:ADITYA DESHPANDE               ID: 2021A7PS2681P
// Name:AADITYA KULKARNI               ID: 2021A7PS0426P
// Name:YASH KANDOI                    ID: 2021A7PS2417P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include <time.h>
#include "lexer.h"

int main(int argc, char *argv[])
{
    int command;
    while (1)
    {
        printf("Enter 0 to exit, 1 to remove comments, 2 to print tokens, 3 to get parse, 4 to get time\n");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
        {
            // Exit
            freeDataStructures();
            exit(1);
        }
        break;
        case 1:
        {
            // Removing Comments
            removeComments(argv[1]);
            printf("Comments removed successfully\n");
            // print file cleanFile.txt to console
            FILE *fp = fopen("cleanFile.txt", "r");
            if (fp == NULL)
            {
                printf("\nError in opening the cleanFile.txt\n");
                exit(1);
            }
            char c;
            while ((c = fgetc(fp)) != EOF)
            {
                printf("%c", c);
            }
            fclose(fp);
        }
        break;
        case 2:
        {
            // Running Lexer Only
            lexerOnly(argv[1]);
        }
        break;
        case 3:
        {
            // Running Lexer and Parser
            parser(argv[1], argv[2]);
        }
        break;
        case 4:
        {
            // Running Lexer and Parser and printing time
            clock_t start_time, end_time;
            double total_CPU_time, total_CPU_time_in_seconds;
            start_time = clock();
            parser(argv[1], argv[2]);
            end_time = clock();

            total_CPU_time = (double)(end_time - start_time);

            total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;

            // Print both total_CPU_time and total_CPU_time_in_seconds
            printf("\nTotal CPU time for Lexer and Parser is: %f\n", total_CPU_time);
            printf("Total CPU time in seconds for Lexer and Parser: %f\n\n", total_CPU_time_in_seconds);
        }
        break;
        default:
            printf("Invalid input. Please enter again\n");
        }
    }
}