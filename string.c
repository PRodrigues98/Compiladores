#include <stdio.h>
#include <stdlib.h>

int strcmp(const char *s1, const char *s2);
char *strcpy(char *dest, const char *src);
char *strchr(const char *str, int c);
double factorialRecurs(int n);
double factorialIter(int n);


int main(){

	printf("%lf\n", factorialRecurs(0));
	return 0;
}


double factorialRecurs(int n){
	if(n <= 1){
		return 1.0;
	}

	return n * factorialRecurs(n - 1);
}


double factorialIter(int n){
	int i; 
	double res = 1.0;

	for(i = 1; i < n + 1; i++){
		res = res * i;
	}

	return res;
}


int strcmp(const char *s1, const char *s2){
	int i = -1;

	do{
		i++;
	} while(s1[i] == s2[i] && s1[i] != 0);

	return s2[i] - s1[i];
}


char *strcpy(char *dest, const char *src){
	int i = -1;

	do{
		i++;
	} while((dest[i] = src[i]) != 0);

	return dest;
}


char *strchr(const char *str, int c){
	int i = -1;

	do{
		i++;
	} while((str[i] != c) != 0);

	return &str[i];
}
