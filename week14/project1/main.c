//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3 //플레이어 수 3명 
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER]; //위치 
char player_name[N_PLAYER][MAX_CHARNAME]; //이름 
int player_coin[N_PLAYER]; //누적 동전 수 
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end //현재 상태 
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"}; //상태 설명 문자열 
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;
    int all_dead = 1; //얘는 다 죽었을 때 
    
    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
        {
            flag_end = 0;
            //break;
        }
        if(player_status[i] != PLAYERSTATUS_DIE) 
        {
        	all_dead = 0;
        	
		}
    }
    
    //모든 플레이어가 죽은 경우 
    if(all_dead == 1)
	{
		return -1; //-1이면 모두 죽었다는 거. 
	} 
    
    //return flag_end;
    return flag_end;
    
}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------
void printPlayerPosition(int player) //플레이어 상태 출력 
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
//사망상태 출력 
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] != PLAYERSTATUS_END && board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}
// ----- EX. 5 : shark ------------

// ----- EX. 6 : game end ------------
//생존 플레이어 수 계산 및 반환
int getAlivePlayer(void) 
{
   int i;
   int cnt = 0;
   for(i=0; i<N_PLAYER; i++)
   {
   	if(player_status[i] == PLAYERSTATUS_END)
   		cnt++;
	} 
	
	return cnt++;
}

//생존 플레이어 중 코인이 많은 플레이어 반환
int getWinner(void)
{
    int i;
    int winner = -1;  
    int max_coin = -1;
    
    for(i=0; i<N_PLAYER; i++)
    {
            
        if (player_status[i] != PLAYERSTATUS_DIE) //먼저 살았는지 확인
		{ 
			if(player_coin[i] > max_coin ) //원래 있던 거.  
    		{
    			max_coin = player_coin[i];
    			winner = i;
			}
		
		//들어온 애랑 코인이 같을 때
			else if(player_coin[i] == max_coin)// && 
			{
				if (winner == -1 || player_position[i] < player_position[winner] && i < winner) //위치 비교 
					winner = i; 
			}	 
		}
	}
	
	return winner;
}
// ----- EX. 6 : game end ------------


int main(int argc, const char * argv[]) 
{
    
    int i;
    int turn=0;

// ----- EX. 1 : Preparation------------
    srand(time(NULL));
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();

// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;

// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn + 1)%N_PLAYER;
            continue;
        }
// ----- EX. 4 : player ------------
        
        //step 2-1. status printing
// ----- EX. 3 : board ------------
        board_printBoardStatus();
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
// ----- EX. 4 : player ------------

        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin);
        
// ----- EX. 4 : player ------------
        dieResult = rolldie();
        
        
        //step 2-3. moving
        //player_position값에 주사위 결과를 더함. 20이상 갔을 때 예외, 이동결과도 
        player_position[turn] = player_position[turn] + dieResult;
        printf("%Die result: %d, %s moved to %d\n",dieResult, player_name[turn], player_position[turn]);
        
        //여기에 pos 20넘었을 때 제한?
        if(player_position[turn] >= N_BOARD) //20을 초과해버리면 멈추기 
		{
			player_position[turn] = N_BOARD - 1; //20을 넘으면 그냥 20? 19?
			player_status[turn] = PLAYERSTATUS_END; 
		}

   
        //step 2-4. coin
        //coinResult
        //이동한 위치에서의 함수 호출, 코인 값 
		//coinResult = board_getBoardStatus(player_position[turn]); 
		coinResult = board_getBoardCoin(player_position[turn]); 
		//반환된 코인 값 더하기 
		player_coin[turn] += coinResult;
		//코인이 존재하는 경우 습득 정보 출력 
		
		if(coinResult > 0)
		{
			printf("-> Lucky! %s got %d coins\n", player_name[turn], coinResult);
			
		} 
    
        
        //step 2-5. end process
        turn = (turn + 1) % N_PLAYER;
        
        if (turn == 0)
        {
        	int shark_pos = board_stepShark();
        	int totalsharkpos = 1; //내가 만든 거, 상어의 총 움직임 
        	
        	totalsharkpos += shark_pos;
        	
        	printf("Shark moved to %i\n", totalsharkpos);
        	
        	
        	checkDie();
		}
		
		printf("\n");
		printf("\n");
    
// ----- EX. 6 : game end ------------
    } while(game_end() == 0);
    
    
    //step 3. game end process
    printf("GAME END!!\n");
    
    if(game_end() == -1)
    	printf("No winner! All players are dead.\n");
	else
		printf("%i players are alive! winner is %s\n", getAlivePlayer(), player_name[getWinner()]);
    
    
// ----- EX. 6 : game end ------------
    
// ----- EX. 2 : structuring ------------

    return 0;
}

//모두 다 죽었을 때 코드 짜야함. 

