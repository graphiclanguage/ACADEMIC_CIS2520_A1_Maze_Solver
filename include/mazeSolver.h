/* Shawn Hustins
 * ID: 0884015
 */

#ifndef __maze_Solver_h__
#define __maze_Solver_h__

#include "dbg.h"
#include "dubList.h"
#include "linkedList.h"
#include "stack.h"

enum Direction {
	up, right, down, left
};

enum MovementType {
	forward, backward, draw
};

/*
 * parseFile
 * PRE: Takes a maze filepath string and a pointer to an integer
 * POST: Returns a doubly linked list representing the input maze file and sets
 *       the integer lineLength to be the width of the maze 
 * ERROR: Unable to open file - returns NULL
 *        Inconsistent maze line lengths - returns NULL
 *        Invalid character in file - returns NULL
 */
void * parseFile(char * filePath, int * lineLength);

/*
 * navMaze
 * PRE: Takes a pointer to the start of the maze and the line width of the maze
 * POST: Makes movements through the maze and returns a pointer to a stack that
 *       specifies the maze solution (from F to S)
 * ERROR: No solution - returns NULL
 *        Stack memory error - returns NULL
 *        Maze is missing a start and/or end character - returns NULL
 */
void * navMaze(DubList * maze, int lineWidth);

/*
 * find
 * PRE: Takes a pointer to a list to search and a character to search for
 * POST: Finds and returns a pointer to the first location in the list where
 *       the character is found
 * ERROR: Character not found in list - returns NULL
 */
void * find(DubList * maze, char toFind);

/*
 * move
 * PRE: Takes a pointer to the current location in the list/maze, the direction
 *      to travel (int between 0-3, see enum Direction above), the type of move
 *      to be made (int between 0-2, see enum MovementType above), and the
 *      line width of the maze
 * POST: Jumps to the desired location in the list/maze and returns this
 *       location if accessible (based on the moveType)
 * ERROR: Desired location outside of list boundaries - returns NULL
 *        Moving forwards or backtracking into wall - returns NULL
 *        Moving forwards into path already traveled - returns NULL
 */
void * move(DubList * currSpot, int direction, int moveType, int lineWidth);

/*
 * revDirection
 * PRE: Takes a direction of travel (int 0-3, see enum Direction above)
 * POST: Returns the opposite direction
 * ERROR: Invalid direction specified - returns -1
 */
int revDirection(int direction);

/*
 * drawPath
 * PRE: Takes a pointer to the start of the list/maze, a pointer to the stack
 *      specifying the solution, and the line width of the maze
 * POST: Inserts characters in the list to represent the solution path and
 *       returns 0 on success
 * ERROR: Error in drawing path - returns 0
 */
int drawPath(DubList * maze, Stack * route, int lineWidth);

/*
 * printMaze 
 * PRE: Takes a pointer to the start of the list/maze and the line width of the
 *      maze
 * POST: Prints each character from the list to stdout
 * ERROR: N/A
 */
void printMaze(DubList * maze, int lineWidth);

#endif