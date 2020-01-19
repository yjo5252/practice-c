/* 
  [알고리즘]
  n-Queens Alogrithm
  backtracking
 */
 //pseudo code 20.01.20  
 
// 다음으로 탐색할 노드 결정 함수
int estimate_nqueens(int n)
{

	int i, j, *col;
	int m, mprod, t, numnodes;	//mprod = m0* m1* m2 * ... * mi-1
								//m =  유망한 자식노드의 개수  (수준 i)

	int *prom_children ;
	i = 0;
	numnodes = m = mprod = 1;
	while (m != 0 && i != n) {
		mprod = mprod * m;		
		numnodes = numnodes + mprod * n;	
		i++;
		m = 0;	
		prom_children = { 0 }; //initialize array  
		for (j = 1; j <= n; j++) {
			col[i] = j;
			if (promising(i)) {
				m++;
				prom_children = add_element(prom_children, j);
			}
		}
		if (m != 0)
			j = random(prom_children);	//select a random node from array 
			col[i] = j;
	 }
	return numnodes; //visit node #
}

int add_element(int* arr, int number); // 자료 추가하려면 prom_children은 linked list 사용?!
int promising(int number);

