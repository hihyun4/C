//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12 //전체 코인 
#define MAX_COIN        4 //한칸당 최대 코인 
// ----- EX. 3 : board ------------
// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
// ----- EX. 5 : shark ------------
// ----- EX. 3 : board ------------
static int board_coin[N_BOARD]; //static은이 파일 안에서만 사용 가능 //N_BOARD = 20
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------


static int shark_position;

// ----- EX. 3 : board ------------
void board_printBoardStatus(void) //특정 칸의 파손 여부 출력 
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

int board_initBoard(void) //보드 초기화 
{
    int i;
    int randPos; //내가 만든 거, 랜덤으로 지정한 동전 놓을 칸 변수 
    
    //variable initialization, 변수 초기화 
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }
    
// ----- EX. 5 : shark ------------ 
    shark_position = SHARK_INITPOS; //상어의 처음 위치, SHARK_INITPOS = -4
// ----- EX. 5 : shark ------------

    //coin allocation //여기에 코인 할당해서 랜덤 배치해야함 p.17
	for(i=0; i<N_COINPOS; i++) //i번째 코인이 할당되지 않았으면 반복 
	{
		while(board_coin[i] != 0) //0~11.. 12번 반복
		{
			//동전을 놓을 칸을 랜덤으로 지정;
			randPos = rand() % N_BOARD; //이러면 0~19?
			 
			if(board_coin[randPos] == 0) //randPos에 코인이 없으면 
			{
				//i번째 코인 할당? 
				board_coin[randPos] = rand() %  MAX_COIN +1;
			}
			
		}
			 
	 } 
    
    
    return N_COINPOS; //얘는 왜 하는거지? -> 수요일에 물어보기 
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
int board_stepShark(void) //상어 전진 명령 
{

}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos) //전체 보드의 상태출력
{
    return board_status[pos];
}

int board_getBoardCoin(int pos) //코인 습득 
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------
