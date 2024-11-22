#include "../include/queue.h"

#include <assert.h>
#include <stdio.h>

// Function to run all the test cases
void run_tests ()
{
	printf ("Running tests...\n");

	// Test 1: Create a queue and check if it is empty
	Queue* q = queue_create (1);
	assert (q != NULL);           // Ensure the queue is created successfully
	assert (queue_is_empty (q));  // The queue should be empty initially
	printf ("Test 1 passed: Queue created and empty\n");

	// Test 2: Enqueue elements and check the size
	queue_enqueue (q, 10);
	queue_enqueue (q, 20);
	queue_enqueue (q, 30);
	assert (queue_size (q) == 3);  // The size should be 3 after enqueueing 3 elements
	printf ("Test 2 passed: Enqueued 3 elements\n");

	// Test 3: Check the front element using queue_top
	assert (queue_top (q) == 10);  // The front element should be 10
	printf ("Test 3 passed: Front element is correct\n");

	// Test 4: Dequeue an element and check the size and front element
	int val = queue_dequeue (q);
	assert (val == 10);            // The dequeued element should be 10
	assert (queue_size (q) == 2);  // The size should now be 2
	assert (queue_top (q) == 20);  // The new front element should be 20
	printf ("Test 4 passed: Dequeued 1 element\n");

	// Test 5: Dequeue all elements and check if the queue is empty
	queue_dequeue (q);            // Dequeue 20
	queue_dequeue (q);            // Dequeue 30
	assert (queue_is_empty (q));  // The queue should be empty now
	printf ("Test 5 passed: Dequeued all elements, queue is empty\n");

	// Test 6: Try to dequeue from an empty queue (edge case)
	val = queue_dequeue (q);
	assert (val == INT_MIN);  // Should return -1 for an empty queue
	printf ("Test 6 passed: Dequeue on empty queue\n");

	// Test 7: Enqueue elements after the queue is emptied
	queue_enqueue (q, 40);
	queue_enqueue (q, 50);
	assert (queue_size (q) == 2);  // The size should be 2 after enqueueing 2 elements
	assert (queue_top (q) == 40);  // The front element should be 40
	printf ("Test 7 passed: Enqueued after emptying the queue\n");

	// Test 8: Check the resizing functionality (double the capacity)
	queue_enqueue (q, 60);         // This will trigger a resize
	assert (queue_size (q) == 3);  // The size should now be 3
	assert (queue_top (q) == 40);  // The front element should still be 40
	printf ("Test 8 passed: Queue resized and elements still correct\n");

	// Test 9: Destroy the queue
	queue_destroy (q);  // Ensure no memory leaks
	printf ("Test 9 passed: Queue destroyed\n");

	printf ("All tests passed!\n");
}

int main ()
{
	run_tests ();
	return 0;
}
