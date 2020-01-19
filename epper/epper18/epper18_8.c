#include <stdio.h>
#include <string.h>

char msg[100];
int key [98];

int main() {


//변수 선언 및 초기화, 데이터 입력
int num;
int i, n;
scanf ('%s", msg);
fflush(stdin);
scanf("%d", &num);

for (i=1; i<8; i++) {
  key[i] = num%10;
  num /=10;
}

//입력된 문자의 개수가 7의 배수가 아닌 경우 abc 순서대로 추가
n = strlen(msg);
i = 0;
while(n%7 !=0) {
  msg[n++] = (char)((int)'a' +i);
  i++;
}
msg[n] = '\0';

//key 번호와 대응되는 문자출력
for (int i = 0; i<strlen(msg) ; i++) {
  int j = key [i % 7 + 1] + i/7 *7 - 1;
  printf("%c", msg[j]);
}
}
