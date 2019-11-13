#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


char g_max_size;		
char g_total_num;		//ù° �ٿ� ���� �� �ִ� Queen-N�� ����� �� 1 ���� 

static __inline char	IsComplete(char depth) // inline �Լ��� ���� ȣ��ɶ� ����.�ӵ��� �� ������. �Լ��� �ڵ尡 �����Ǵ� ��.
{
	if (depth == (g_max_size - 1))	return 1; 	//leaf node���� �˻������� 1�� ��ȯ

	return 0;
}

static void FindNextTargets(char * arr, char depth, char * next_targets, char * num_of_next_targets)
{
	int i, j;
	char valid_target_num = 0;

	for (i = 0; i < g_max_size; i++)
	{
		char valid_flag = 1;

		for (j = 1; j <= depth; j++)
		{
			if (arr[(depth - j) * g_max_size + i] != 0)		 
			{
				valid_flag = 0;
				break;
			}

			if (((i - j) >= 0) && (arr[(depth - j) * g_max_size + (i - j)] != 0))
			{
				valid_flag = 0;
				break;
			}

			if (((i + j) < g_max_size) && (arr[(depth - j) * g_max_size + (i + j)] != 0))
			{
				valid_flag = 0;
				break;
			}
		}

		if (valid_flag == 1) next_targets[valid_target_num++] = i;	//������ �ڽ� ������ i���� next_targets�迭�� ����
	}

	*num_of_next_targets = valid_target_num;
}
//��Ʈ��ŷ 
void	Backtracking(char * arr, char depth)			
{
	int i;

	// Check whether this combination is the solution or not.
	if (IsComplete(depth))
	{
		g_total_num++;		//ù° �ٿ� ���� �� �ִ� Queen-N�� ����� �� 1 ���� 
	}
	else
	{
		char num_of_next_targets = 0;
		char* next_targets = (char*)calloc(g_max_size, sizeof(char));

		// Increase the count of depth.
		depth++;

		// Update the list of next targets and the number.
		FindNextTargets(arr, depth, next_targets, &num_of_next_targets);

		// Check every feasible target.
		for (i = 0; i < num_of_next_targets; i++)
		{
			arr[depth * g_max_size + next_targets[i]] = 1; // depth ���̿� �ִ� next_targets (������ �ڽĳ���)�� ���� ��Ʈ��ŷ ����
			Backtracking(arr, depth);
			arr[depth * g_max_size + next_targets[i]] = 0;
		}

		free(next_targets);
	}
}

int main(void)
{
	int i;
	char* arr_ptr;

	scanf("%d", &g_max_size);		//��Ʈ ����� �ڽ��� ����

	arr_ptr = (char*)calloc(g_max_size * g_max_size, sizeof(char));		//heap ������ �޸� �Ҵ�; calloc ����ϸ� 0���� �ʱ�ȭ 

	for (i = 0; i < g_max_size; i++)
	{
		arr_ptr[i] = 1;				// i��° depth�� ���� ��Ʈ��ŷ �������
		Backtracking(arr_ptr, 0);	// ��Ʈ��ŷ ��Ʈ������ ����
		arr_ptr[i] = 0;				//  i��° depth�� ���� ��Ʈ��ŷ ��
	}

	printf("%d\n", g_total_num);	//ù° �ٿ� ���� �� �ִ� Queen-N�� ����� �� 1 ���� 

	free(arr_ptr);

	return 0;
}
