
#ifndef IMP_H
#define IMP_H


#define TRUE   1
#define FALSE  0

#define EASYLEVEL   1
#define MEDIUMLEVEL 2
#define HARDLEVEL   3



#define R1  1
#define R2  2
#define R3  3
#define R4  4
#define R5  5
#define R6  6
#define R7  7
#define R8  8
#define R9  9

#define C1  1
#define C2  2
#define C3  3
#define C4  4
#define C5  5
#define C6  6
#define C7  7
#define C8  8
#define C9  9

#define BLOCK1  1
#define BLOCK2  2
#define BLOCK3  3
#define BLOCK4  4
#define BLOCK5  5
#define BLOCK6  6
#define BLOCK7  7
#define BLOCK8  8
#define BLOCK9  9






void Sudoku_Rewrite_Array(void);

void String_scan (char *string);

char* Get_Inf_LEVEL_NAME(int*Plevel);

void Sudoku_Print_All_Frame(int Level,char*User_name);

void Sudoku_Array_Set_CursorPosition(int row,int col);

void Sudoku_Array_Print(char SudokuArray[][C9],char check);

char Sudoku_Get_Info( int*Prow, int*Pcol,int*Pdigit);

char Known_Block_Index (int Row, int COl);

char Check_Replace_Const(const char Sudoku[][9],int Row, int COl);

char Check_IF_Found_in_Block(char Sudoku[][C9],int Digit,char Block);

char Sudoku_CheckIF_Found_INROW_OR_Column(char Sudoku[][C9],int Row,int Col,int Digit);

void Sudoku_Digit_Set_Frame (int digit,int Row_index, int Col_index);

void Sudoku_Digit_Set_ArraySudoku(char Sudoku[][C9],int Row,int Col,int Digit);




#endif
