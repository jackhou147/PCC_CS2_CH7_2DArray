#include "stdafx.h"
#include "two_d_array.h"
using namespace std;

//DEFINITIONS

//NOT TESTED
void display_menu(bool _2d)
{
	/* Purpose: print 2d array app menu.
	* Pre-condition: none.
	* Post-condition: none.
	* TESTED: 
	*/

	/*-------------DEBUG STATEMENT----------------*/
	const bool DEBUG = false;
	if (DEBUG)
		cout << endl
		<< "-------------display_menu---------------" << endl;

	/*-------------process--------------*/
	cout << endl
		<< "------------------------------------------------------------------------" << endl
		<< "		[A]ppend [I]nsert  [D]elete [S]earch s[H]uffle" << endl
		<< "		           [<]Descending [>]Ascending " << endl
		<< ".   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   ." << endl
		<< "             [?]menu   [L]eft   [R]ight  [U]p dow[N]  e[X]it" << endl
		<< "------------------------------------------------------------------------" << endl;
}


ERRORS _2d_sort(ITEM_TYPE arr[][MAX_COLS], int nu[], int current_row, bool descending)
{
	/*
	Purpose: sort the current row of a 2d array
	Pre-condition: 
	Post-condition:
	Dependency: sort()
	Note: 
	Tested:
	*/

	//variables...
	ERRORS error = NO_ERROR;

	//process...
	error = sort(arr[current_row], nu[current_row], descending);

	//output...
	return error;
}

ERRORS _2d_shuffle(ITEM_TYPE arr[][MAX_COLS], int nu[], int current_row) {
	/*
	Purpose: shuffle elements in current row in 2d array
	Pre-condition:
	Post-condition: elements in current row are shuffled
	Note:
	Dependency:
	Tested:
	*/

	//variables...
	ERRORS error = NO_ERROR;

	//process...
	error = shuffle(arr[current_row], nu[current_row]);

	//output...
	return error;
}



ERRORS _2d_remove(ITEM_TYPE arr[][MAX_COLS], int nu[], int row, int col)
{
	/*
	Purpose: remove an element at specified row and column from a 2d array
	Pre-condition: valid row and column(cursor)
	Post-condition:
	1. element at arr[row][col] has been deleted
	2. nu[row] has been decreased by 1
	3. row and col are NOT changed.
	Dependency: arrayapp.cpp, remove()
	Note:
	TESTED:
	*/

	/*----------variables-----------*/
	ERRORS error = NO_ERROR;

	/*----------process-----------*/
	//1. if invalid row or column
	if (row < MAX_ROWS || col < MAX_COLS) {
		error = remove(arr[row], nu[row], col);
	}

	/*----------output-----------*/
	return error;
}

void _2d_print(int arr[][MAX_COLS], int cursor_row, int cursor_col, ERRORS& error) {
	/* Purpose: print a fully utilized 2d array.
	* Pre-condition:
	* Post-condition:
	* Dependency:
	*/

	for (int i = 0; i<MAX_ROWS; i++) {
		display_array_nav(arr[i], MAX_COLS, cursor_row == i ? cursor_col : -1, error);
	}

}

/*
 0,1,2
 0,1,2,3
 0,1,2,3
 0,1,2,3


*/

void _2d_navigate(ITEM_TYPE arr[][MAX_COLS], int nu[], char command, int & current_row, int & current_col)
{
	/*
	Purpose: to move the cursor up/down/left/right
	Pre-condition:
	Post-condition:
	Note: debug: check for invalid cursor positions
	Dependency: nav_horizontal(), _2d_nav_vertical()
	TESTED:
	*/

	//process...
	command = toupper(command);
	switch (command) {
	case 'U': //move up
		_2d_nav_vertical(arr, nu, current_row, current_col, -1);
		break;
	case 'N': //move down
		_2d_nav_vertical(arr, nu, current_row, current_col, 1);
		break;
	case 'L': //move left
		nav_horizontal(arr[current_row], nu[current_row], current_col, -1);
		break;
	case 'R': //move right
		nav_horizontal(arr[current_row], nu[current_row], current_col, 1);
		break;
	default:
		break;
	}
}

void _2d_nav_vertical(ITEM_TYPE arr[][MAX_COLS], int nu[], int & row, int & col, int direction)
{
	/*
	Purpose: to move cursor up or down.
	Pre-condition: 0<=row<MAX_ROWS, 0<=col<MAX_COL
	Post-condition: row and col has been modified.
	Note:
	Dependency:
	TESTED:
	*/

	//variables...

	//process...
	//increment row
	if ((direction == 1 && row + 1 < MAX_ROWS) || (direction == -1 && row - 1 >= 0))
		row += direction;

	//if out of bound, decrement column
	if (col >= nu[row])
		col = nu[row] - 1;
	if (col < 0 && nu[row] > 0) {
		col = 0;
	}

}

ERRORS _2d_append(ITEM_TYPE arr[][MAX_COLS], int nu[], ITEM_TYPE item, int row)
{
	/*
	Purpose: append an item to the end of a given row
	in a given 2d array.
	Pre-condition:
	Post-condition:
	1. item becomes the last interesting
	element of the given row.
	2. num_used of that row is incremented by 1.
	Note:
	Dependency: arrayapp.cpp, append()
	TESTED:
	*/

	//variables...
	ERRORS error = NO_ERROR;

	//process...
	if(nu[row] + 1 <= MAX_COLS)
		error = append(arr[row], nu[row], item);

	//output...
	return error;
}

//KIND OF TESTED
void _2d_print(int arr[][MAX_COLS], int nu[], int cursor_row, int cursor_col, ERRORS error[]) {
	/* Purpose: print a partially filled 2d array.
	* Pre-condition: valid argument values
	* Post-condition: 2d array and relevant
	* information has been printed on the screen.
	* Dependency: display_array_nav
	*/

	//print row, column, num_used of that row
	cout << "Cursor Row: " << cursor_row << ", Cursor Col: " << cursor_col << " NumUsed: " << nu[cursor_row];

	for (int i = 0; i<MAX_ROWS; i++) {
		cout << endl;
		cout << setw(2)<<( (cursor_row == i && nu[i] < 1) ? "[" : " " )<<":";
		if (cursor_row == i && nu[i] < 1) cout << "]";
		cout << setw(3);
		display_array_nav(arr[i], nu[i], cursor_row == i ? cursor_col : -1, error[i]);
	}

	cout << endl << "----------------------------" << endl;
}




ERRORS _2d_insert(ITEM_TYPE arr[][MAX_COLS], int nu[], ITEM_TYPE item, int row, int col)
{
	/*
	Purpose: insert an element AT the given row and column
	Pre-condition:
	Post-condition: 1. item has been inserted at the given position.
	2. num_used for that row has been incremented by 1
	Note: !!row and column are zero based.
	Debug note: look at MAX_COL and CAPACITY in constants.h. they may not
	be the same.
	Dependency: arrayapp.cpp,  insert_before()
	TESTED:
	*/

	//variables...
	ERRORS error = NO_ERROR;

	//process...
	if(nu[row] + 1 <= MAX_COLS)
		error = insert_before(arr[row], nu[row], item, col);

	//output...
	return error;
}



void _2d_search(ITEM_TYPE arr[][MAX_COLS], int nu[], int item,
	int &row, int &col)
{
	/*
	Purpose: search for an element in a 2d array
	Pre-condition: valid argument values are given.
	Post-condition: row and col have been set to the row
	and column of the first	occurance of item; or
	both set to -1 if item not found.
	Note:  1. Searches left to right, top to bottm.
	2. !!Row and column are both 0 based.
	Dependency: arrayapp.cpp, search()
	TESTED:
	*/

	//variables...
	row = -1;												 //default value
	col = -1;												 //default value

															 //process...
															 //1. outer loop iterates through each row
	for (int i = 0; i < MAX_ROWS; i++) {
		//2. inner loop iterates through each column
		col = search(arr[i], MAX_COLS, item);
		//3. if item is found, set row and break
		if (col != -1) {
			row = i;
			break;
		}
	}
}

void nav_horizontal(ITEM_TYPE arr[], int num_used, int & col, int direction)
{
	/*
	Purpose: to move cursor left or right.
	Pre-condition:
	Post-condition: col has been incremented or decremented by 1
	Note: This is not an array processing function.
	Dependency:
	TESTED:
	*/

	//process...
	if ((direction == 1 && col + 1 < num_used) || (direction == -1 && col - 1 >= 0))
		col += direction;
}




//TESTED

