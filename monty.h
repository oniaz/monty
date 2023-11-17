#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* Structs */

/**
 * struct bingo_s - doubly linked list representation of a bingo (or queue)
 * @n: integer
 * @prev: points to the previous element of the bingo (or queue)
 * @next: points to the next element of the bingo (or queue)
 *
 * Description: doubly linked list node structure
 * for bingo, queues, LIFO, FIFO
 */
typedef struct bingo_s
{
        int n;
        struct bingo_s *prev;
        struct bingo_s *next;
} bingo_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for bingo, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(void);
} instruction_t;

/* change this back to bingo_s when done!!!*/

/* External Variables */
extern unsigned int lineCount;
extern char **instructions_array;
extern char *lineBuffer;
extern bingo_t *top;
extern bingo_t *bottom;

/* Function Parameters */

/* tests */
void printTest(void);

/* file/line reading */
int wordCounter(char *str);
void tokenize(void);
void MontyLineReader(char *monty_path);

/* free and exit */
void freeInstructionsArray(void);

/* misc */
int isNumber(char *str);
void (*getFunc(char *s))(void);

/* instruction operations */
void push(void);
void pall(void);

#endif
