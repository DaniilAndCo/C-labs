#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Returns new str which is sum of two ones*/
char* Concat(char *s1, char *s2) {
        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);                      
        char *result = malloc(len1 + len2 + 1);
        if (!result) {
            fprintf(stderr, "malloc() failed: insufficient memory!\n");
            return NULL;
        }
        memcpy(result, s1, len1);
        memcpy(result + len1, s2, len2 + 1);    
		result[len1 + len2] = '\0';
        return result;
    }

/* Add to str 000 or 111 depending on parameters and return new str*/
char* CreateBinaryNumber(int counter, char* currentNumber) {
	if (counter % 2 == 0) {
		return Concat(currentNumber, "111");
	}
	else {
		return Concat(currentNumber, "000");
	}
}

/* Clear buffer trash*/
void MyFlush(void){
	int c;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');
	return;
}

int main()
{
	int m = 0, var = 0;
	/* Check correctness of input*/
	do {
		printf("m = ");
		var = scanf("%i", &m);
		MyFlush();
	} while (var == 0);
	char* currentNumber = "";

	/* The main cycle*/
	int i = 7, counter = 0;
	for (; i <= m; i = (counter % 2 == 0) ? i * 8 : i * 8 + 7, ++counter){
		currentNumber = CreateBinaryNumber(counter, currentNumber);
		printf("%d - ", i);
		puts(currentNumber);
	}
	getchar();
	return 0;
}