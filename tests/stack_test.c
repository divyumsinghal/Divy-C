#include "../include/stack.h"

#include <stdio.h>
#include <assert.h>

// Function to run all the test cases
void run_tests ()
{
	printf ("Running tests...\n");

	// Test 1: Create a stack and check if it is empty
	Stack* s = stack_create (1);
	assert (s != NULL);           // Ensure the stack is created successfully
	assert (stack_is_empty (s));  // The stack should be empty initially
	printf ("Test 1 passed: Stack created and empty\n");

	// Test 2: Push elements and check the size
	stack_enstack (s, 10);
	stack_enstack (s, 20);
	stack_enstack (s, 30);
	assert (stack_size (s) == 3);  // The size should be 3 after pushing 3 elements
	printf ("Test 2 passed: Pushed 3 elements\n");

	// Test 3: Check the top element using stack_top
	assert (stack_top (s) == 30);  // The top element should be 30
	printf ("Test 3 passed: Top element is correct\n");

	// Test 4: Pop an element and check the size and top element
	int val = stack_destack (s);
	assert (val == 30);            // The popped element should be 30
	assert (stack_size (s) == 2);  // The size should now be 2
	assert (stack_top (s) == 20);  // The new top element should be 20
	printf ("Test 4 passed: Popped 1 element\n");

	// Test 5: Pop all elements and check if the stack is empty
	stack_destack (s);            // Pop 20
	stack_destack (s);            // Pop 10
	assert (stack_is_empty (s));  // The stack should be empty now
	printf ("Test 5 passed: Popped all elements, stack is empty\n");

	// Test 6: Try to pop from an empty stack (edge case)
	val = stack_destack (s);
	assert (val == INT_MIN);  // Should return INT_MIN for an empty stack
	printf ("Test 6 passed: Pop on empty stack\n");

	// Test 7: Push elements after the stack is emptied
	stack_enstack (s, 40);
	stack_enstack (s, 50);
	assert (stack_size (s) == 2);  // The size should be 2 after pushing 2 elements
	assert (stack_top (s) == 50);  // The top element should be 50
	printf ("Test 7 passed: Pushed after emptying the stack\n");

	// Test 8: Check the resizing functionality (double the capacity)
	stack_enstack (s, 60);         // This will trigger a resize if necessary
	assert (stack_size (s) == 3);  // The size should now be 3
	assert (stack_top (s) == 60);  // The top element should now be 60
	printf ("Test 8 passed: Stack resized and elements still correct\n");

	// Test 9: Destroy the stack
	stack_destroy (s);  // Ensure no memory leaks
	printf ("Test 9 passed: Stack destroyed\n");

	printf ("All tests passed!\n");
}

int main ()
{
	run_tests ();
	return 0;
}
