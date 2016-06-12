/* Shawn Hustins
 * ID: 0884015
 */

#include "mazeSolver.h"

void * parseFile(char * filePath, int * lineLength) {
	
	DubList * mazeList = NULL;
	FILE * mazeFile = fopen(filePath, "r");
	check(mazeFile != NULL, "Unable to open specified maze.");
	
	char buffer = '0';
	int currLength = 0;
	int line = 0;
	
	while ((buffer = fgetc(mazeFile)) != EOF) {
		switch (buffer) {
			case '+': //All valid characters in file
			case '-':
			case '|':
			case ' ':
			case 'S':
			case 'F':
				mazeList = addToBack(mazeList, buffer);
				++currLength;
				break;
			case '\n': //test line length
				if (line) check(currLength == *lineLength,
					"Inconsistent maze width, first occurence: Line %d",
					line+1);
				line++;
				*lineLength = currLength;
				currLength = 0;
				break;
			default:
				sentinel("Invalid char - Line: %d Col: %d '%c'", line+1,
						currLength+1, buffer);
		}
	}
	fclose(mazeFile);
	return mazeList;
	
error:
	destroyList((Node*)mazeList);
	if (mazeFile) fclose(mazeFile);
	return NULL;
}

void * navMaze(DubList * maze, int lineWidth) {
	
	Stack * route = createStack();
	DubList * currSpot = find(maze, 'S');
	check(currSpot != NULL, "Maze does not contain a start position.");
	check(find(maze, 'F'), "Maze does not contain a end position.");
	
	while (currSpot->data != 'F') {
		DubList * newSpot = NULL;
		if ((newSpot = move(currSpot, up, forward, lineWidth))) {
			currSpot->data = 'X';
			currSpot = newSpot;
			check(!push((Node*)route, up), "Stack error.");
			continue;
		}
		if ((newSpot = move(currSpot, right, forward, lineWidth))) {
			currSpot->data = 'X';
			currSpot = newSpot;
			check(!push((Node*)route, right), "Stack error.");
			continue;
		}
		if ((newSpot = move(currSpot, down, forward, lineWidth))) {
			currSpot->data = 'X';
			currSpot = newSpot;
			check(!push((Node*)route, down), "Stack error.");
			continue;
		}
		if ((newSpot = move(currSpot, left, forward, lineWidth))) {
			currSpot->data = 'X';
			currSpot = newSpot;
			check(!push((Node*)route, left), "Stack error.");
			continue;
		}
		int errState = 0;
		int direction = pop((Node*)route, &errState);
		check(!errState, "No solution.");
		
		newSpot = move(currSpot, revDirection(direction), backward, lineWidth);
		check(newSpot, "No solution.");
		currSpot->data = 'N';
		currSpot = newSpot;
	}
	
	return route;
	
error:
	return NULL;
}

void * find(DubList * maze, char toFind) {
	
	while (maze != NULL) {
		if (maze->data == toFind) break;
		maze = maze->next;
	}
	
	return maze;
}

void * move(DubList * currSpot, int direction, int moveType, int lineWidth) {
	
	int numMoves;
	
	switch (direction) {
		case up:
			numMoves = -lineWidth;
			break;
		case down:
			numMoves = lineWidth;
			break;
		case left:
			numMoves = -1;
			break;
		case right:
			numMoves = 1;
			break;
	}
	
	for (int i = numMoves; i != 0; (i > 0) ? i-- : i++) {
		if (i > 0) {
			currSpot = currSpot->next;
		} else {
			currSpot = currSpot->prev;
		}
		if (!currSpot) return NULL;
	}
	
	if (moveType == draw) return currSpot;
	
	if (currSpot->data != 'F' && currSpot->data != ' ' &&
		currSpot->data != 'X')
		return NULL;
	
	if (moveType == forward && currSpot->data == 'X')
		return NULL;
	
	return currSpot;
}

int revDirection(int direction) {
	
	switch (direction) {
		case up:
			return down;
		case down:
			return up;
		case left:
			return right;
		case right:
			return left;
	}
	return -1;
}

int drawPath(DubList * maze, Stack * route, int lineWidth) {
	
	DubList * currSpot = find(maze, 'F');
	int errState = 0;
	
	while(route->next) {
		int direction = revDirection(pop((Node*)route, &errState));
		currSpot = move(currSpot, direction, draw, lineWidth);
		check(currSpot, "Path creating error occured.");
		check(!errState, "Path creating error occured.");
		currSpot->data = '*';
	}
	currSpot->data = 'S';
	return 0;
	
error:
	return -1;
}

void printMaze(DubList * maze, int lineWidth) {
	
	int column = 0;
	
	while (maze) {
		switch (maze->data) {
			case '+':
			case '-':
			case '|':
			case 'S':
			case 'F':
			case '*':
			case ' ':
				printf("%c", maze->data);
				break;
			case 'N':
			case 'X':
				printf(" ");
		}
		++column;
		if (column == lineWidth) {
			column = 0;
			printf("\n");
		}
		maze = maze->next;
	}
	return;
}
