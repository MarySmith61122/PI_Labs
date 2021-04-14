#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

void input(*char);
void trick();

int main()
{
	char f[100];
	printf("File name: ");
	cin.getline(f, 100);

	input(&f);
	trick();

	return 0;
}

void input(*char name)
{
	FILE* op;
	if ((op = fopen(name, "a")) != NULL)
	{
		fprintf(op, "\n\nfind.c:\nFile has been found\n");
		fclose(op);
	}
	else printf("\nFile not found!\n");
}

void trick()
{
	FILE* op = fopen("boo.txt", "w");
	fprintf(op, "You've been spooked!\n");
	fclose(op);
}
