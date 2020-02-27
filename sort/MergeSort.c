void MergeSort(int A[], int Start, int End)
{
  if (Start <End) {
    int Middle = (Start+End)/2;     // 전체 배열을 절반으로 나눈다.

    //재귀 함수를 통하여 분할 정복의 방법을 사용한다.
    MergeSort(A, Start, Middle);
    MergeSort(A, Middle, End);

    // 각가 정렬된 데이터 셋을 Merge 해주는 함수
    Merge(A, Start, Middle, End);
  }
}

