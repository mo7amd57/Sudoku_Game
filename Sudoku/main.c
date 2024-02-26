#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>
#include "main.h"




int main()
{
    char Error;                            // error in user inputs Row Col Digits
    char Check_Const=0;                  // if User Try To Replace Constant Digit
    char check_Found_InBlock=0;          // if Value Enter by User Found in arr 3*3
    char Check_Found_InROW_COl=0;       // if Value Enter by User Found Row Or Col
    char Solve_Compelet=0;              // if User Enter 49 True Value Start Compare Solve

    int Level;
    char Block_Num=0;
    char*User_Name=NULL;
    int Row,Col,Digit;


    char Again_Flage=1;    // If User Want Play Again Remain 1 else If User Want To Close The Game Set it 0
    char Game_Flage=1;    // Still Take Input From User Until He win //Replace By Compare Func
    char Solve_Flag=0;    // if User Ask to See Solve Or Solved it by himself




    while(Again_Flage)
    {
        /*=====================>>    Loading Bage    <<=============================================*/

        Full_Screen();
        Play_Sound_WAIT();
        Sudoku_Print();
        Loading_print();
        TeamX_print();
        Loading_Bar();
        Sleep(100);
        Stop_Sound();
        system("cls");

        /*================================================================================================================*/

        /*======================================>>  Game Bage   <<=========================================================*/


        Fram_Game();
        Welcom_Game_Print();
        Array_Fram();
        Game_Rules_print();
        User_Name=Get_Inf_LEVEL_NAME(&Level); // Return Name And Level
        Sudoku_Print_All_Frame(Level,User_Name);


        /*==================>> Print Unsolved Array For Level Chosing   <<=============================*/

        if (Level==EASYLEVEL)
        {
            Sudoku_Array_Print(Sudoku_Easy_Unsolved,FALSE);
        }
        else if (Level==MEDIUMLEVEL)
        {

            Sudoku_Array_Print(Sudoku_Medium_Unsolved,FALSE);
        }
        else
        {
            Sudoku_Array_Print(Sudoku_Hard_Unsolved,FALSE);
        }


        /*=============================>>  Game Start   <<===============================*/

        while(Game_Flage)
        {
            Error=Sudoku_Get_Info(&Row,&Col,&Digit);  // No Error in Row And Col And Digits

            if (Error==FALSE)
            {
                Block_Num=Known_Block_Index(Row,Col);

        /*==================================>> Checks Func For All Levels  <<============================*/

                if (Level==EASYLEVEL)
                {
                    Check_Const=Check_Replace_Const(Sudoku_Easy_Const,Row,Col);

                    check_Found_InBlock=Check_IF_Found_in_Block(Sudoku_Easy_Unsolved,Digit,Block_Num);

                    Check_Found_InROW_COl=Sudoku_CheckIF_Found_INROW_OR_Column(Sudoku_Easy_Unsolved,Row,Col,Digit);


                }
                else if (Level==MEDIUMLEVEL)
                {
                    Check_Const=Check_Replace_Const(Sudoku_Medium_Const,Row,Col);

                    check_Found_InBlock=Check_IF_Found_in_Block(Sudoku_Medium_Unsolved,Digit,Block_Num);

                    Check_Found_InROW_COl=Sudoku_CheckIF_Found_INROW_OR_Column(Sudoku_Medium_Unsolved,Row,Col,Digit);

                }
                else
                {
                    Check_Const=Check_Replace_Const(Sudoku_Hard_Const,Row,Col);

                    check_Found_InBlock=Check_IF_Found_in_Block(Sudoku_Hard_Unsolved,Digit,Block_Num);

                    Check_Found_InROW_COl=Sudoku_CheckIF_Found_INROW_OR_Column(Sudoku_Hard_Unsolved,Row,Col,Digit);
                }


                if ((!Check_Const)&&(!check_Found_InBlock)&&(!Check_Found_InROW_COl))
                {
                    if (Level==EASYLEVEL)
                    {
                        Sudoku_Digit_Set_Frame(Digit,Row,Col);

                        Sudoku_Digit_Set_ArraySudoku(Sudoku_Easy_Unsolved,Row,Col,Digit);
                    }
                    else if (Level==MEDIUMLEVEL)
                    {
                        Sudoku_Digit_Set_Frame(Digit,Row,Col);

                        Sudoku_Digit_Set_ArraySudoku(Sudoku_Medium_Unsolved,Row,Col,Digit);

                    }
                    else
                    {
                        Sudoku_Digit_Set_Frame(Digit,Row,Col);

                        Sudoku_Digit_Set_ArraySudoku(Sudoku_Hard_Unsolved,Row,Col,Digit);
                    }


                }
            }

    /*===========================>> User Input True Digit till Lever Compare And check if he win  <<=========================*/

            if (Cmp_Count>=CMPLEVEL)
            {
                if (Level==EASYLEVEL)
                {
                    Solve_Compelet=Compare_Solve(Sudoku_Easy_Solved,Sudoku_Easy_Unsolved);
                }
                else if (Level==MEDIUMLEVEL)
                {
                   Solve_Compelet=Compare_Solve(Sudoku_Medium_Solved,Sudoku_Medium_Unsolved);
                }
                else
                {
                   Solve_Compelet=Compare_Solve(Sudoku_Hard_Solved,Sudoku_Hard_Unsolved);
                }

                if (Solve_Compelet==TRUE)
                {
                    Play_Sound_WOW();
                    Sleep(500);
                   Game_Flage=0;

                }

            }

   /*===========================>> User Input False Inputs till Lever ASK Solve Func  <<=========================*/

             if (ASK_Solve_Count==ASKSOLVE)
            {

              Info_Frame_Delete();
              Solve_Flag=Ask_Solve_Frame();
              ASK_Solve_Count=0;

              if (Solve_Flag==TRUE)
              {
                  Play_Sound_SUCCESS();

                  if (Level==EASYLEVEL)
                {

                   Sudoku_Array_Print(Sudoku_Easy_Solved,TRUE);
                }
                else if (Level==MEDIUMLEVEL)
                {
                   Sudoku_Array_Print(Sudoku_Medium_Solved,TRUE);
                }
                else
                {
                  Sudoku_Array_Print(Sudoku_Hard_Solved,TRUE);;
                }

                Sleep(18000); // Sleep 10S to user Seen Solve

                   Game_Flage=0;
              }
              Info_Frame_Delete();
              Cheack_Frame_print();

            }

        }


        /*====================================>>  Gamer is Win Or ASK Solve  <<========================================================*/


        if (Solve_Flag==TRUE)
        {


            Again_Flage=Try_By_YourSelf_Print();
        }
        else if (Solve_Compelet==TRUE)
        {

            Again_Flage=Congratulation_Print();
        }


        /*========>> When User Ask To Play Again  <<======================================*/

        system("cls");
        Game_Flage=1;
        Cmp_Count=0;
        Sudoku_Rewrite_Array();
    }


    return 0;
}
