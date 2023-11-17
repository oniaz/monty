#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* Structs */

/**
 * struct bigno_s - doubly linked list representation of a bigno (or queue)
 * @n: integer
 * @prev: points to the previous element of the bigno (or queue)
 * @next: points to the next element of the bigno (or queue)
 *
 * Description: doubly linked list node structure
 * for bigno, queues, LIFO, FIFO
 */
typedef struct bigno_s
{
        int n;
        struct bigno_s *prev;
        struct bigno_s *next;
} bigno_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for bigno, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(bigno_t **bigno, unsigned int line_number);
} instruction_t;

/* change this back to bigno_s when done!!!*/

/* External Variables */
extern unsigned int lineCount;
extern char **instructions_array;
extern char *lineBuffer;
extern bigno_t *top;
extern bigno_t *bottom;

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
void (*getFunc(char *s))(bigno_t **bigno, unsigned int line_number);

/* instruction operations */
void push(bigno_t **bigno, unsigned int line_number);
void pall(bigno_t **bigno, unsigned int line_number);

#endif
