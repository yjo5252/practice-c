// epper18_5
// 차량 5부제

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>;

int main(void) {

	int endNum[2] = { 0 };
	int date = 0;
	int carNum = 0, countCar = 0, illegalCar = 0;
	scanf("%d", &date); //날짜 입력
	// 차량 운행금지일 번호 
	endNum[0] = date % 10;
	endNum[1] = (endNum[0] + 5) % 10;

	scanf("%d", &carNum); // 운행할 차량 대수 

	for (int i = 0; i < carNum; i++) {
		scanf("%d", &countCar);
		countCar %= 10;
		//
		if (countCar == endNum[0] || countCar == endNum[1]) {
			illegalCar++;
		}
	}
	printf("%d", illegalCar);
	return 0;
}
