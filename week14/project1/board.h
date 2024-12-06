//
//  board.h
//  sharkGame
//


#ifndef board_h
#define board_h

#include <stdio.h>
#include <stdlib.h>

// ----- EX. 3 : board ------------
#define N_BOARD                 20

//0 - OK, 1 - destroyed
#define BOARDSTATUS_NOK          1
#define BOARDSTATUS_OK           0

int board_initBoard(void); //보드 초기화 
int board_getBoardStatus(int pos); //전체 보드의 상태출력 
int board_getSharkPosition(void); //상어의 위치 출력
int board_stepShark(void); //상어 전진 명령 
int board_getBoardCoin(int pos); //코인 습득 명령 
void board_printBoardStatus(void); //특정 칸의 파손 여부 출력 
// ----- EX. 3 : board ------------
#endif /* board_h */
