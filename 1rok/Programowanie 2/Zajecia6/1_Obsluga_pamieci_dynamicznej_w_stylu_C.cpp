#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//przyk�ad z wyk�adu (w prostszej postaci)
int main() {

	int* lengths = (int*)malloc(12);

	*(lengths + 0) = 7;
	*(lengths + 1) = 9;
	*(lengths + 2) = 5;
	
	float** array2d = (float**)malloc((3 * sizeof(float*))); //rzutowanie bo zwracany void*;
	for (int i = 0; i < 3; i++) {
		*(array2d + i) = (float*)malloc(*(lengths+i) * sizeof(float));
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < *(lengths + i); j++) {
			*(*(array2d + i) + j) = (i + 1) + ((j + 1) / 10.0);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < *(lengths + i); j++) {
			cout << *(*(array2d + i) + j) << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		free(*(array2d + i));
	}
	free(array2d);
	free(lengths);

	return 0;

}
