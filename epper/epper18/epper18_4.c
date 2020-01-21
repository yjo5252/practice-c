// epper18_4
// 정사각형 좌표 프로그램
// enum boolena  & possible
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef enum { false, true } boolean;

int x[3];
int y[3];

int main(void) {

	int i = 0;
	int j = 0;

	int xNum, yNum;
	boolean possibleX[3] = { true };
	boolean possibleY[3] = { true };

	for (i = 0; i < 3; i++) {
		scanf("%d %d", x[i], y[i]);
	}

	for (i = 0; i < 2; i++) {
		for (j = i + 1; j < 3; j++) {
			if (x[i] == x[j] && possibleX[i] == true && possibleX[j] == true) {
				possibleX[i] = false;
				possibleX[j] = false;
			}
			if (y[i] == y[j] && possibleY[i] == true && possibleY[j] == true) {
				possibleY[i] = false;
				possibleY[j] = false;
			}
		}

	}
	for (i = 0; i < 3; i++){
		if (possibleX[i] == true) {
			xNum = i;
		}
		if (possibleY[i] == true) {
			yNum = i;
		}
	}
	print("%d %d", x[xNum], y[yNum]);

	return 1;
}
