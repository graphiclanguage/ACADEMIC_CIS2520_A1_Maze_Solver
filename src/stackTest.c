/* Shawn Hustins
 * ID: 0884015
 */

#include "linkedList.h"
#include "stack.h"

int main(int argc, char * argv[]) {
	
	int returnVal = 0;
	int errorVal = 0;
	Stack * test;
	
	/* create stack **********************************************************/
	test = createStack();
	check(test != NULL, "Create internal failure.");
	
	/* push/peek test 1 ******************************************************/
	check(push((Node*)test, -10) == 0, "Push internal failure.");
	check(test->next->data == -10, "Push failure, Expected: -10, Output: %d", 
		  test->next->data);
	
	returnVal = peek((Node*)test, &errorVal);
	check(errorVal == 0, "Peek internal failure.");
	check(returnVal == -10, "Peek failure, Expected: -10, Output: %d",
		  returnVal);
	
	/* push/peek test 2 ******************************************************/
	check(push((Node*)test, 0) == 0, "Push internal failure.");
	check(test->next->data == 0, "Push failure, Expected: 0, Output: %d", 
		  test->next->data);
	
	returnVal = peek((Node*)test, &errorVal);
	check(errorVal == 0, "Peek internal failure.");
	check(returnVal == 0, "Peek failure, Expected: 0, Output: %d",
		  returnVal);
	
	/* push/peek test 3 ******************************************************/
	check(push((Node*)test, 500000) == 0, "Push internal failure.");
	check(test->next->data == 500000, 
		  "Push failure, Expected: 500000, Output: %d", test->next->data);
	
	returnVal = peek((Node*)test, &errorVal);
	check(errorVal == 0, "Peek internal failure.");
	check(returnVal == 500000, "Peek failure, Expected: 500000, Output: %d",
		  returnVal);
	
	/* pop test 1 ************************************************************/
	returnVal = pop((Node*)test, &errorVal);
	check(errorVal == 0, "Pop internal failure.");
	check(returnVal == 500000, "Pop failure, Expected: 500000, Output: %d",
		  returnVal);
	
	/* pop test 2 ************************************************************/
	returnVal = pop((Node*)test, &errorVal);
	check(errorVal == 0, "Pop internal failure.");
	check(returnVal == 0, "Pop failure, Expected: 0, Output: %d",
		  returnVal);
	
	/* destroy test **********************************************************/
	destroyStack((Node*)test);
	
	//Pop and destroy must also be tested in valgrind for their correctness
	
	
	/* Expected/Documented Fail Cases ****************************************/
	printf("The following are intentional failure tests.\n");
	
	//Should have no effect
	destroyStack(NULL);
	
	//Pushing to nothing
	check(push(NULL, 5) == -1, "Should fail here.");

	//Popping from nothing
	check(pop(NULL, &errorVal) == 0, "Should fail here.");
	check(errorVal == -1, "Should fail here.");
	
	//Popping from empty stack
	test = createStack();
	check(pop((Node*)test, &errorVal) == 0, "Should fail here.");
	check(errorVal == -1, "Should fail here.");
	
	//Peeking at nothing
	check(peek(NULL, &errorVal) == 0, "Should fail here.");
	check(errorVal == -1, "Should fail here.");
	
	//Peeking at empty stack
	check(peek((Node*)test, &errorVal) == 0, "Should fail here.");
	check(errorVal == -1, "Should fail here.");
	destroyStack((Node*)test);
	
	printf("All tests complete.\n");
	
	return 0;
	
error:
	printf("Tests failed before completion.\n");
	
	return 1;
}