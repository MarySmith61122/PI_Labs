#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	char f[100];
	printf("File name: ");
	cin.getline(f, 100);

	FILE* op;
	if ((op = fopen(f, "a")) != NULL)
	{
		fprintf(op, "\n\nfind.c:\nFile has been found\n");
		fclose(op);
	}
	else printf("\nFile not found!\n");

	return 0;
}
