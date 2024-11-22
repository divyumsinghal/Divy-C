#include <assert.h>
#include <stdio.h>

#include "../include/vector.h"

// Function to run all the test cases
void run_tests ()
{
	printf ("Running vector tests...\n");

	// Test 1: Create a vector and check if it is empty
	Vector* v = vector_create (4);
	assert (v != NULL);            // Ensure the vector is created successfully
	assert (vector_is_empty (v));  // The vector should be empty initially
	printf ("Test 1 passed: Vector created and empty\n");

	// Test 2: Push elements and check size
	vector_push_back (v, 10);
	vector_push_back (v, 20);
	vector_push_back (v, 30);
	assert (vector_size (v) == 3);  // Size should be 3 after pushing 3 elements
	printf ("Test 2 passed: Elements pushed to vector\n");

	// Test 3: Access elements using vector_get
	assert (vector_get (v, 0) == 10);  // First element
	assert (vector_get (v, 1) == 20);  // Second element
	assert (vector_get (v, 2) == 30);  // Third element
	printf ("Test 3 passed: Elements retrieved correctly\n");

	// Test 4: Modify elements using vector_set
	vector_set (v, 1, 25);             // Change the second element to 25
	assert (vector_get (v, 1) == 25);  // Verify the change
	printf ("Test 4 passed: Element modified successfully\n");

	// Test 5: Check the last element using vector_last
	assert (vector_last (v) == 30);  // The last element should be 30
	printf ("Test 5 passed: Last element is correct\n");

	// Test 6: Handle resizing when capacity is exceeded
	vector_push_back (v, 40);          // Push to full capacity
	vector_push_back (v, 50);          // Trigger resizing
	assert (vector_size (v) == 5);     // Size should now be 5
	assert (vector_get (v, 4) == 50);  // The new element should be added correctly
	printf ("Test 6 passed: Resizing handled correctly\n");

	// Test 7: Verify vector_is_empty after pushing and clearing
	assert (!vector_is_empty (v));  // Vector should not be empty after adding elements
	printf ("Test 7 passed: vector_is_empty works correctly\n");

	// Test 8: Destroy the vector
	vector_destroy (v);  // Ensure no memory leaks
	printf ("Test 8 passed: Vector destroyed\n");

	printf ("All vector tests passed!\n");
}

int main ()
{
	run_tests ();
	return 0;
}
