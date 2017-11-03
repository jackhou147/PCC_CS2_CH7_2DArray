#ifndef TWO_D_ARRAY_H
#define TWO_D_ARRAY_H
#include "../!includes/arrayapp.h"
//Note: nu stands for num_used.

//PROTOTYPES

void display_menu(bool _2d);

//navigate 2d array, moving cursor up/down/left/right
//dependency: _2d_nav_vertical(), nav_horizontal()
ERRORS _2d_sort(ITEM_TYPE arr[][MAX_COLS], int nu[], int current_row, bool descending);

ERRORS _2d_shuffle(ITEM_TYPE arr[][MAX_COLS], int nu[], int current_row);

void _2d_navigate(ITEM_TYPE arr[][MAX_COLS], int nu[], char command, 
				  int& current_row, int& current_col);

//navigate vertically (move cursor up or down)
void _2d_nav_vertical(ITEM_TYPE arr[][MAX_COLS], int nu[], int &row, int &col, int direction);

//navigate horizontally (move cursor left or right)
void nav_horizontal(ITEM_TYPE arr[], int num_used, int& col, int direction);

//search for an element in a 2d array
void _2d_search(ITEM_TYPE arr[][MAX_COLS], int nu[], int item,
	int &row, int &col);

//insert an element at a specified row and column in a 2d array
ERRORS _2d_insert(ITEM_TYPE arr[][MAX_COLS], int nu[], ITEM_TYPE item, int row, int col);

//remove an element at specified row and column from a 2d array
ERRORS _2d_remove(ITEM_TYPE arr[][MAX_COLS], int nu[], int row, int col);

//append an element into a specified row in a partially filled 2d array
ERRORS _2d_append(ITEM_TYPE arr[][MAX_COLS], int nu[], ITEM_TYPE item, int row);

//print function for partially filled 2d array
void _2d_print(int arr[][MAX_COLS], int nu[], int cursor_row, int cursor_col, ERRORS error[]);

//print function for a fully utilized array.
void _2d_print(int arr[][MAX_COLS], int cursor_row, int cursor_col, ERRORS& error);

#endif // TWO_D_ARRAY_H
