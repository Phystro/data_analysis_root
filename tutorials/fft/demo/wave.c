#include <stdio.h>
#include <math.h>
#include <string.h>

// sin x + sin 2x

#define PI 3.14159265358979323846

double waveform(double num){

	double degv = num * PI/180;
	double ans = sin(degv) + sin(2*degv);
	return ans;
}

int main(){

	int values = 721;

	FILE *fp = fopen("data.dat", "w");

	for (int i = 0; i < values; i++){
	
		printf("Sine %d = %f\n", i, waveform(i));
		fprintf(fp, "%d\t%f\n", i, waveform(i));
	}


	fclose(fp);
}
