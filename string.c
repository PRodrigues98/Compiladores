#include <stdio.h>
#include <stdlib.h>

int strcmp(const char *s1, const char *s2);
char *strcpy(char *dest, const char *src);
char *strchr(const char *str, int c);


int main(){

	char* str1 = (char*)malloc(sizeof(char) * 10);
	char* str2 = (char*)malloc(sizeof(char) * 10);

	printf("%s\n", strcpy(str1, "Ola"));
	printf("%s\n", strcpy(str2, "Teste"));
	printf("%s\n", strcpy(str2, str1));

	return 0;
}


int strcmp(const char *s1, const char *s2){
	int i = -1;

	do{
		i++;
	} while(s1[i] == s2[i] && s1[i] != '\0');

	return s2[i] - s1[i];
}


char *strcpy(char *dest, const char *src){
	int i = -1;

	do{
		i++;
	} while((dest[i] = src[i]) != '\0');

	return dest;
}


char *strchr(const char *str, int c){
	int c = 0;

	while()
}
