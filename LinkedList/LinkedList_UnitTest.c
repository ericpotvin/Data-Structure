#include "../UnitTest.h"
#include "LinkedList.h"

/**
 */
int test_isEmpty() {
	int valid = 0;
	int empty = 0;
	struct linkedListNode *root = NULL;

	// Check empty first
	empty = isEmpty(root);
	valid += assertTrue("test_isEmpty: The list is empty", empty == 1);

	// Add a node
	addNode(&root, createNode(123));
	empty = isEmpty(root);
	valid += assertTrue("test_isEmpty: The list is not empty", empty == 0);
	
	// Free memory 
	deleteList(&root);
	empty = isEmpty(root);
	valid += assertTrue("test_isEmpty: The list is empty", empty == 1);

	return valid;
}

/**
 */
int test_exists() {
	int valid = 0;
	int exist = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(123));
	addNode(&root, createNode(924));
	addNode(&root, createNode(371));

	exist = exists(root, 17);
	valid += assertTrue("test_exists: The list does not have 17", exist == 0);

	exist = exists(root, 123);
	valid += assertTrue("test_exists: The list has 123", exist == 1);
	
	deleteList(&root);

	return valid;
}

/**
 */
int test_countNode() {
	int valid = 0;
	int count = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(10));
	addNode(&root, createNode(100));
	addNode(&root, createNode(1000));

	count = countNode(root);
	valid += assertTrue("test_countNode: The list has 4 nodes", count == 4);

	deleteList(&root);

	count = countNode(root);
	valid += assertTrue("test_countNode: The list has 0 nodes", count == 0);

	return valid;
}

/*
 */
int test_maxValue() {
	int valid = 0;
	int max = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(76));
	addNode(&root, createNode(526));
	addNode(&root, createNode(27));
	
	max = maxValue(root);
	valid += assertTrue("test_maxValue: The max value is 526", max == 526);

	deleteList(&root);

	max = maxValue(root);
	valid += assertTrue("test_maxValue: The list is empty", max == 0);

	return valid;
}

/**
 */
int test_getNext() {
	int valid = 0;
	int after = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(2));
	addNode(&root, createNode(3));
	addNode(&root, createNode(4));

	after = getNext(root, 1);
	valid += assertTrue("test_getNext: Should be 2", after == 2);

	after = getNext(root, 4);
	valid += assertTrue("test_getNext: Last element of the list", after == 0);

	return valid;
}

/**
 */
int test_getPrevious() {
	int valid = 0;
	int previous = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(2));
	addNode(&root, createNode(3));
	addNode(&root, createNode(4));

	previous = getPrevious(root, 1);
	valid += assertTrue("test_getPrevious: First element of the list", previous == 0);

	previous = getPrevious(root, 3);
	valid += assertTrue("test_getPrevious: Should be 2", previous == 2);

	return valid;
}

/**
 */
int test_removeNode() {
	int valid = 0;
	int count = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(9));
	addNode(&root, createNode(6));
	addNode(&root, createNode(4));
	addNode(&root, createNode(2));

	removeNode(&root, 0);
	count = countNode(root);
	valid += assertTrue("test_removeNode: The list has 4 nodes", count == 4);

	removeNode(&root, 4);

	count = countNode(root);
	valid += assertTrue("test_removeNode: The list has 3 nodes", count == 3);

	removeNode(&root, 9);

	count = countNode(root);
	valid += assertTrue("test_removeNode: The list has 2 nodes", count == 2);

	deleteList(&root);

	return valid;
}

/**
 */
int test_insertAfter() {
	int valid = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(2));
	addNode(&root, createNode(3));
	addNode(&root, createNode(4));

	insertAfter(&root, createNode(9), 3);

	int exist = exists(root, 9);
	valid += assertTrue("test_insertAfter: The list has 9", exist == 1);

	int count = countNode(root);
	valid += assertTrue("test_insertAfter: The list has 5 nodes", count == 5);

	deleteList(&root);

	return valid;
}

/**
 */
int test_insertBefore() {
	int valid = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(2));
	addNode(&root, createNode(3));
	addNode(&root, createNode(4));

	insertBefore(&root, createNode(9), 1);

	int exist = exists(root, 9);
	valid += assertTrue("test_insertAfter: The list has 9", exist == 1);

	int count = countNode(root);
	valid += assertTrue("test_insertAfter: The list has 5 nodes", count == 5);

	deleteList(&root);

	return valid;
}

int test_removeAfter() {
	int valid = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(2));
	addNode(&root, createNode(3));
	addNode(&root, createNode(4));

	removeAfter(&root, 3);

	int exist = exists(root, 4);
	valid += assertTrue("test_removeAfter: The list element 4 removed", exist == 0);

	removeAfter(&root, 3);

	int count = countNode(root);
	valid += assertTrue("test_removeAfter: The list has 3 nodes", count == 3);

	deleteList(&root);

	return valid;
}

/**
 */
int test_removeBefore() {

	int valid = 0;
	struct linkedListNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(2));
	addNode(&root, createNode(3));
	addNode(&root, createNode(4));

	removeBefore(&root, 3);

	int exist = exists(root, 2);
	valid += assertTrue("test_removeAfter: The list element 2 removed", exist == 0);

	removeBefore(&root, 1);

	int count = countNode(root);
	valid += assertTrue("test_removeBefore: The list has 3 nodes", count == 3);

	deleteList(&root);

	return valid;
}

/* Define UnitTests Lookup functions */

int getNumberTest() {
	return 11;
}

void getUnitTest(UnitTestFunction tests[], char *list[])
{
	int id = 0;

	tests[id]	= test_isEmpty;
	list[id++] = "test_isEmpty";

	tests[id]	= test_exists;
	list[id++] = "test_exists";

	tests[id]	= test_countNode;
	list[id++] = "test_countNode";

	tests[id]	= test_maxValue;
	list[id++] = "test_maxValue";

	tests[id]	= test_getNext;
	list[id++] = "test_getNext";

	tests[id]	= test_getPrevious;
	list[id++] = "test_getPrevious";

	tests[id]	= test_removeNode;
	list[id++] = "test_removeNode";

	tests[id]	= test_insertAfter;
	list[id++] = "test_insertAfter";

	tests[id]	= test_insertBefore;
	list[id++] = "test_insertBefore";

	tests[id]	= test_removeAfter;
	list[id++] = "test_removeAfter";

	tests[id]	= test_removeBefore;
	list[id++] = "test_removeBefore";
}
