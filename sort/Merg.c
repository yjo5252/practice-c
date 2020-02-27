
void Merge (int A[], int Start, int Middle, int End) {
  int arr_size = End-Start+1;
  int first_index = Start;
  int second_index= Middle+1
  int temp[] = new int[arr_size]; //Merge 하려는 데이터와 동일한 크기의 임시 배열을 선언한다.
  for (int i=0; i < arr_size; i++) // Merge 하려는 데이터와 갯수만큼 반복문 수행
  {
    // 두 데이터 셋을 index 값을 활용해 Merge를 수행한다.
    if (A[first_index] < A[second_index])
    {
      temp[i] = A[first_index];
      first_index++;
    }
    else
    {
      temp[i] = A[second_index];
      second_index++;
    }
  }
  for (int i=0; i<arr_size; i++) // 임시 배열을 실제 데이터 배열에서 Copy 한다.
  {
    A[Star+1] = temp[i];
  }
}
