#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int fibonacci(int number);
int input_bilangan;

int validInt(int *var)
{
	char buff[1024];
	char check;
	if (fgets(buff, sizeof(buff), stdin) != NULL)
	{
		if (sscanf(buff, "%d %c", var, &check) == 1)
		{
			return 1;
		}
	}
	return 0;
}

void reset()
{
	int main();
	char pil[1];
	printf("\nIngin Kembali ke Program? [Y/N] : ");
	scanf("%s", &pil);

	if (!strcmp(pil, "y") || !strcmp(pil, "Y"))
	{
		system("cls");
		main();
	}
	else if (!strcmp(pil, "n") || !strcmp(pil, "N"))
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("\nError, Input Tidak Valid!\n");
		reset();
	}
}

void rekursif()
{
	int i;
	printf("==================================================\n");
	printf("=              Metode Rekursif                   =\n");
	printf("==================================================\n\n");
	printf("Masukan Jumlah Deret : ");
	if (!validInt(&input_bilangan))
	{
		printf("\nError, Input Tidak Valid!\n");
		rekursif();
	}
	if (input_bilangan < 0)
	{
		printf("\nError, Input Ulang Berupa Bilangan Positif!\n");
		rekursif();
	}
	else
	{
		printf("Deret bilangan FIbonacci Adalah:\n");
		for (i = 0; i < input_bilangan; i++)
		{
			printf(" %d", fibonacci(i));
		}
	}
}

void fibonacciIteratif()
{
	printf("Deret bilangan FIbonacci Adalah:\n");
	int a = -1, i, c, b = 1;
	for (i = 1; i <= input_bilangan; i++)
	{
		c = a + b;
		a = b;
		b = c;
		printf(" %d", c);
	}
}

void iteratif()
{
	printf("==================================================\n");
	printf("=              Metode Iteratif                   =\n");
	printf("==================================================\n\n");
	printf("Masukan Jumlah Deret : ");
	if (!validInt(&input_bilangan))
	{
		printf("\nError, Input Tidak Valid!\n");
		iteratif();
	}
	if (input_bilangan < 0)
	{
		printf("\nError, Input Ulang Berupa Bilangan Positif!\n");
		iteratif();
	}
	else
	{
		fibonacciIteratif();
	}
}

int fibonacci(int number)
{
	if (number == 0)
	{
		return 0;
	}
	else if (number == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(number - 1) + fibonacci(number - 2);
	}
}

void menu()
{
	int pilih;
	fflush(stdin);
	system("cls");
	printf("==================================================\n");
	printf("=             PROGRAM DERET FIBONACCI            =\n");
	printf("=                   KELOMPOK 24                  =\n");
	printf("==================================================\n");
	printf("=                  Daftar Menu                   =\n");
	printf("=            [1] Metode Rekursif                 =\n");
	printf("=            [2] Metode Iteratif                 =\n");
	printf("=            [3] Keluar                          =\n");
	printf("==================================================\n\n");
	printf("Pilih Menu : ");
	if (!validInt(&pilih))
	{
		printf("\nError, Input Tidak Valid!\n");
		menu();
	}

	switch (pilih)
	{
	case 1:
		system("cls");
		rekursif();
		reset();
		break;

	case 2:
		system("cls");
		iteratif();
		reset();
		break;
	case 3:
		printf("TERIMA KASIH");
	    sleep(1);
		system("cls");
		break;
	default:
		printf("\nError, Input Tidak Valid!\n");
		reset();
		break;
	}
}

int main()
{
	menu();
	return 0;
}
