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

int board_initBoard(void) //보드 초기화 **완성 
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
    
    
    return N_COINPOS; //얘는 왜 하는거지? 
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
int board_stepShark(void) //상어 전진 명령 **완성? 
{
	//MAX_SHARKSTEP 6, SHARK_INITPOS -4 
	//1~MAX_SHARKSTEP칸을 랜덤으로 이동, 이동경로에서 board_status 배열 요소 변경 
	//shark_position 값 갱신
	//shark_position초기화,  board_initBoard함수에서 SHARK_INITPOS값으로 초기화함. 
	//보드는 20개(N_BOARD) 
	
	int i;
	int randstepShark; //내가 만든 거, 1~6까지 랜덤 숫자
	//1. 1~MAX_SHARKSTEP칸을 랜덤으로 이동
	randstepShark = rand() % MAX_SHARKSTEP + 1; 
	

	for (i=0; i<randstepShark; i++) //랜덤 숫자만큼 상어가 이동 
	{
		shark_position++; //랜덤 숫자만큼 상어 한칸씩 이동 
		
		if(shark_position >= N_BOARD) //20을 초과해버리면 멈추기 
		{
			shark_position = 19; //20을 넘으면 그냥 20? 19?
			break;
		}
		
		//2. 이동경로에서 board_status 배열 요소 변경
		board_status[shark_position] = BOARDSTATUS_NOK;
	}
	
	 
	//return shark_position; 
}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos) //전체 보드의 상태출력, 
{
    return board_status[pos]; //배열 요소 반환, 내부 static전역 변수 값을 main.c에 제공 
}

int board_getBoardCoin(int pos) //코인 습득(pos번째 보드칸에 있는 코인 줍기), board_coin배열의 값을 반환하면서 배열 값을 0으로 만듦. 
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------
