*******************************************************************************
Shawn Hustins                                                           0884015
CIS2520                                          Non-Recursive Maze Solver (A1)
June 10th 2016
*******************************************************************************

***********
Compilation
***********

make arguments:
	$ make program (builds bin/mazeSolver)
	$ make test (builds bin/stackTest)
	$ make all (builds both of the above)
	$ make clean (removes executables and compilation artifacts)

**********************
Running the program(s)
**********************

For test:
	$ ./bin/stackTest
	(Any debug output other than intentional failures denote an error)

For program:
	$ ./bin/mazeSolver [inputMazeFilePath]
	Program will print the maze, filled in with it's solution, to stdout

*****************
Known Limitations
*****************

All errors are handled safely, though, in order for maze to be solved:
	Maze file should only include valid characters ("+-|SF ")
	Maze file should appear in expected format (see A1 spec)
	Maze file should have at least one existing solution
	Maze file should have a consistent line width
	Maze file should not include multiple endings


**********
References
**********

Found in include/dgb.h:
	Shaw, Zed (2015) Zed's Awesome Debug Macros [Source Code] Addison-Wesley


*******************************
Academic Integrity Pledge
*******************************

I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased.  Furthermore,
I certify that this assignment was prepared by me specifically for this course.