//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12 //��ü ���� 
#define MAX_COIN        4 //��ĭ�� �ִ� ���� 
// ----- EX. 3 : board ------------
// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
// ----- EX. 5 : shark ------------
// ----- EX. 3 : board ------------
static int board_coin[N_BOARD]; //static���� ���� �ȿ����� ��� ���� //N_BOARD = 20
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------


static int shark_position;

// ----- EX. 3 : board ------------
void board_printBoardStatus(void) //Ư�� ĭ�� �ļ� ���� ��� 
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

int board_initBoard(void) //���� �ʱ�ȭ **�ϼ� 
{
    int i;
    int randPos; //���� ���� ��, �������� ������ ���� ���� ĭ ���� 
    
    //variable initialization, ���� �ʱ�ȭ 
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }
    
// ----- EX. 5 : shark ------------ 
    shark_position = SHARK_INITPOS; //����� ó�� ��ġ, SHARK_INITPOS = -4
// ----- EX. 5 : shark ------------

    //coin allocation //���⿡ ���� �Ҵ��ؼ� ���� ��ġ�ؾ��� p.17
	for(i=0; i<N_COINPOS; i++) //i��° ������ �Ҵ���� �ʾ����� �ݺ� 
	{
		while(board_coin[i] != 0) //0~11.. 12�� �ݺ�
		{
			//������ ���� ĭ�� �������� ����;
			randPos = rand() % N_BOARD; //�̷��� 0~19?
			 
			if(board_coin[randPos] == 0) //randPos�� ������ ������ 
			{
				//i��° ���� �Ҵ�? 
				board_coin[randPos] = rand() %  MAX_COIN +1;
			}
			
		}
			 
	 } 
    
    
    return N_COINPOS; //��� �� �ϴ°���? 
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
int board_stepShark(void) //��� ���� ��� **�ϼ�? 
{
	//MAX_SHARKSTEP 6, SHARK_INITPOS -4 
	//1~MAX_SHARKSTEPĭ�� �������� �̵�, �̵���ο��� board_status �迭 ��� ���� 
	//shark_position �� ����
	//shark_position�ʱ�ȭ,  board_initBoard�Լ����� SHARK_INITPOS������ �ʱ�ȭ��. 
	//����� 20��(N_BOARD) 
	
	int i;
	int randstepShark; //���� ���� ��, 1~6���� ���� ����
	//1. 1~MAX_SHARKSTEPĭ�� �������� �̵�
	randstepShark = rand() % MAX_SHARKSTEP + 1; 
	

	for (i=0; i<randstepShark; i++) //���� ���ڸ�ŭ �� �̵� 
	{
		shark_position++; //���� ���ڸ�ŭ ��� ��ĭ�� �̵� 
		
		if(shark_position >= N_BOARD) //20�� �ʰ��ع����� ���߱� 
		{
			shark_position = 19; //20�� ������ �׳� 20? 19?
			break;
		}
		
		//2. �̵���ο��� board_status �迭 ��� ����
		board_status[shark_position] = BOARDSTATUS_NOK;
	}
	
	 
	//return shark_position; 
}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos) //��ü ������ �������, 
{
    return board_status[pos]; //�迭 ��� ��ȯ, ���� static���� ���� ���� main.c�� ���� 
}

int board_getBoardCoin(int pos) //���� ����(pos��° ����ĭ�� �ִ� ���� �ݱ�), board_coin�迭�� ���� ��ȯ�ϸ鼭 �迭 ���� 0���� ����. 
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------
