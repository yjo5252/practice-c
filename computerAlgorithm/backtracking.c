//1771105 조예은 
//nQueens.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//unsigned char = 0~255
//signed char = -128 ~ +127
typedef unsigned int(u32);
typedef unsigned char(u8);

u8 g_max_size;			// Queen의 개수
u32 g_total_num;		//첫째 줄에 놓을 수 있는 Queen-N의 경우의 수 1 증가 

static __inline u8	IsComplete(u8 depth) // inline 함수는 자주 호출될때 유용.속도가 더 빠르다. 함수의 코드가 복제되는 것.
{
	if (depth == (g_max_size - 1))	return 1;  	//leaf node까지 검사했으면 1값 반환

	return 0;
}

static void FindNextTargets(u8 * arr, u8 depth, u8 * next_targets, u8 * num_of_next_targets){		
	//FindNextTargets() : 같은 열, 대각선 찾아서 유망한 노드에서 제외함
	int i, j;
	u8 valid_target_num = 0;

	for (i = 0; i < g_max_size; i++)
	{
		u8 valid_flag = 1;

		for (j = 1; j <= depth; j++){
			if (arr[(depth - j) * g_max_size + i] != 0)		{
				valid_flag = 0;
				break;
			}
			if (((i - j) >= 0) && (arr[(depth - j) * g_max_size + (i - j)] != 0))	{
				valid_flag = 0;
				break;
			}
			if (((i + j) < g_max_size) && (arr[(depth - j) * g_max_size + (i + j)] != 0))	{
				valid_flag = 0;
				break;
			}
		}
		if (valid_flag == 1) next_targets[valid_target_num++] = i;  //유망한 자식 노드들의 i값을 next_targets배열에 저장
	}
	*num_of_next_targets = valid_target_num;
}

void	Backtracking(u8 * arr, u8 depth){	
	//Backtracking(): 백트랙킹
	int i;

	// Check whether this combination is the solution or not.
	if (IsComplete(depth))	{
		g_total_num++;		//첫째 줄에 놓을 수 있는 Queen-N의 경우의 수 1 증가 
	}
	else	{
		u8 num_of_next_targets = 0;
		u8* next_targets = (u8*)calloc(g_max_size, sizeof(u8));

		// Increase the count of depth.
		depth++;

		// Update the list of next targets and the number.
		FindNextTargets(arr, depth, next_targets, &num_of_next_targets);

		// Check every feasible target.
		for (i = 0; i < num_of_next_targets; i++)	{
			arr[depth * g_max_size + next_targets[i]] = 1; 
			// depth 깊이에 있는 next_targets (유망한 자식노드들)에 대해 백트랙킹 진행
			Backtracking(arr, depth);
			arr[depth * g_max_size + next_targets[i]] = 0;
		}
		free(next_targets);
	}
}

int main(void)	{
	int i;
	u8* arr_ptr;

	scanf("%d", &g_max_size);	//루트 노드의 자식의 개수

	arr_ptr = (u8*)calloc(g_max_size * g_max_size, sizeof(u8));		
	//heap 구조로 메모리 할당; calloc 사용하면 0으로 초기화 
	for (i = 0; i < g_max_size; i++)	{
		arr_ptr[i] = 1;					// i열에 대해 백트랙킹 진행시작
		Backtracking(arr_ptr, 0);		// 백트랙킹 루트노드부터 진행
		arr_ptr[i] = 0;					//  i열에 대해 백트래킹 끝
	}

	printf("%d\n", g_total_num);			//첫째 줄에 놓을 수 있는 Queen-N의 경우의 수 1 증가 

	free(arr_ptr);

	return 0;
}
