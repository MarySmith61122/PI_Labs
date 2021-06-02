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


void print(char* str, const int i, const int j)
{
	cout << str << " " << i << " " << j << endl;
}

void print(float m[], const int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << m[i] << " ";
		if ((i + 1) % 4 == 0) cout << endl;
	}
	cout << endl;
}

struct data
{
	int day, month, year;
};

struct person
{
	char name[32];
	short age;
	struct data d;
}list[10];

cin >> list[0].d.year;
cin >> list[0].d.month;
cin >> list[0].d.day;

strcpy(list[0].name, "Илья");
list[0].age = 20;

