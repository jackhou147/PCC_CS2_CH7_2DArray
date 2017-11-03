#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
used by array library, sorted array library and 2d array library.


*/

enum ERRORS {
    NO_ERROR,
    FULL_ARRAY,
    EMPTY_ARRAY,
    INSERT_ON_EMPTY_ARRAY,
    BAD_SHIFT_POS,
    END_OF_LIST,
    START_OF_LIST,
	BAD_POS
};

typedef int ITEM_TYPE;
//1d array capacity
const int CAPACITY = 15;

//2d array capacity
const int MAX_ROWS = 5;
const int MAX_COLS = 6;





#endif // CONSTANTS_H
