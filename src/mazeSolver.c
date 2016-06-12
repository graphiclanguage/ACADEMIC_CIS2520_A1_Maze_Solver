/* Shawn Hustins
 * ID: 0884015
 */

#include "mazeSolver.h"

int main(int argc, char * argv[]) {
	
	DubList * maze = NULL;
	Stack * route = NULL;
	
	check(argc == 2, "USAGE: ./[executable] [mazeFile]");
	
	int lineWidth = 0;
	
	maze = parseFile(argv[1], &lineWidth);
	check(maze != NULL, "File parsing failed.");
	
	route = navMaze(maze, lineWidth);
	check(route != NULL, "Maze navigation failed.");
	
	check(!drawPath(maze, route, lineWidth), "");
	
	printMaze(maze, lineWidth);
	
	destroyStack((Node*)route);
	
	destroyList((Node*)maze);
	
	return 0;
	
error:
	if (maze) destroyList((Node*)maze);
	if (route) destroyStack((Node*)route);
	return -1;
}