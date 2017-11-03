// VS_CS2_CH7_2D_ARR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../../!includes/arrayapp.h"
#include "../../../!includes/two_d_array.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << endl << endl << "================" << endl;

	srand(time(0));
	int td[MAX_ROWS][MAX_COLS] = { 
		{0}, 
		{10,11},
		{20,21,22},
		{30,31,32,33},
		{40,41,42,43,44}
	};
	int nu[MAX_ROWS] = {1,2,3,4,5};
	ERRORS error[MAX_ROWS];
	int key;
	int cursor_row = 4;
	int cursor_col = 4;
	int search_result_row = -1;
	int search_result_col = -1;
	char command = 'X';
	string prompt = ">>";

	//intialize error array:
	for (int i = 0; i<MAX_ROWS; i++) {
		//default no error
		error[i] = NO_ERROR;
	}

	/*-----------output------------*/
	_2d_print(td,nu,cursor_row,cursor_col,error);
	display_menu(true);

	do {
		//*-----------input-------------*//
		cin >> command;
		command = toupper(command);

		


		/*-----------process-------------*/
		switch (command) {
		case '?':
			display_menu(true);
			break;
			//append
		case 'A':
			//1.input an element
			key = get_int(prompt);
			//2.append to current row
			error[cursor_row] = _2d_append(td,nu,key,cursor_row);
			if (error[cursor_row] == NO_ERROR)
				cursor_col = nu[cursor_row] - 1;
			break;
			//insert
		case 'I':
			//1.input an element
			key = get_int(prompt);
			//2.insert it before current cursor position
			error[cursor_row] = _2d_insert(td, nu, key, cursor_row, cursor_col);
			break;
			//delete
		case 'D':
			//1. delete element at current cursor position
			error[cursor_row] = _2d_remove(td,nu,cursor_row,cursor_col);
			//2. update cursor position
			if (cursor_col >= nu[cursor_row]) //if out of range
				cursor_col--;
			break;
			//search
		case 'S':
			//1. input an element
			key = get_int(prompt);
			//2. search for it in array
			_2d_search(td, nu, key, search_result_row, search_result_col);
			//3. update cursor position if found
			if (search_result_row != -1 && search_result_col != -1) {
				cursor_row = search_result_row;
				cursor_col = search_result_col;
			}
			break;
			//shuffle
		case 'H':
			error[cursor_row] = _2d_shuffle(td, nu, cursor_row);
			break;
			//ascending
		case '>':
			error[cursor_col] =  _2d_sort(td, nu, cursor_row, false);
			break;
			//descending
		case '<':
			error[cursor_row] = _2d_sort(td, nu, cursor_row, true);
			break;
			//cursor next
		case 'R':
		case 'L':
		case 'U':
		case 'N':
			_2d_navigate(td, nu, command, cursor_row, cursor_col);
			//exit
		case 'X':
			break;
			//default
		default:
			cout << endl << "invalid choice."<<endl;
			break;
		}

		/*-----------output------------*/
		_2d_print(td, nu, cursor_row, cursor_col, error);

	} while (command != 'X');



	cout << endl << endl << "================" << endl;
	return 0;
}