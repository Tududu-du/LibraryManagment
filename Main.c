#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>                 
#include<ctype.h>                  
#include<dos.h>    
#include<time.h>




void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void searchbooks(void);
void viewbooks(void);
int  getdata();
int  t(void);
int  checkid(int);

char genre[][20] = { "novel","scifi","fantasy","reportaz","ekonomia","horror", "popularnonaukowa"};
COORD coord = { 0, 0 };
char findbook;

int s;

struct books
{
	int id;
	char title[50];
	char Author[50];
	int year;
	int pages;
	char *gen;
	char* cover;

};
struct books a;

FILE* fp, * ft, * fs;

void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void mainmenu(void) {
	system("cls");
	gotoxy(20, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIBLIOTECZKA DOMOWA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20, 5);
	printf("\xDB\xDB\xDB\xDB\xB2 1.Dodaj ksiazki ");
	gotoxy(20, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Usun ksiazki ");
	gotoxy(20, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Wyszukaj ksiazke ");
	gotoxy(20, 11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Zobacz liste ksiazek ");
	gotoxy(20, 13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Sortuj wg tytulu ");
	gotoxy(20, 15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Sortuj wg autora ");
	gotoxy(20, 17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Zamknij aplikacje ");
	gotoxy(20, 21);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20, 22);
	t();
	gotoxy(20, 23);
	printf("Wpisz swoj wybor:");
	switch (getch())
	{
	case '1':
		addbooks();
		break;
	case '2':
		deletebooks();
		break;
	case '3':
		searchbooks();
		break;
	case '4':
		viewbooks();
		break;
	case '7':
	{
		system("cls");
		gotoxy(16, 4);
		printf("\t Projekt zaliczeniowy w C");
		gotoxy(16, 5);
		printf("\tStworzony przez");
		gotoxy(16, 7);
		printf("\tAgata Handzlik, Katarzyna Bassara, Tomasz Bajor");
		gotoxy(16, 8);
		printf("******************************************");
		gotoxy(16, 10);
		printf("*******************************************");
		gotoxy(16, 11);
		printf("*******************************************");
		gotoxy(16, 13);
		printf("********************************************");
		gotoxy(10, 17);
		printf("Wyjœcie za 3 sekundy...........>");
		//flushall();
		Sleep(3000);
		exit(0);
	}
	default:
	{
		gotoxy(10, 23);
		printf("\aWpisz poprawn¹ wartoœæ!");
		if (_getch())
			mainmenu();
	}

	}
}
void addbooks(void)    //funtion that add books
{
	system("cls");
	int i;
	FILE* fp;
	gotoxy(20, 5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2WYBIERZ GATUNEK\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Novel");
	gotoxy(20, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Fantasy");
	gotoxy(20, 11);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Reportaz");
	gotoxy(20, 13);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Popularnonaukowe");
	gotoxy(20, 15);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Ekonomia");
	gotoxy(20, 17);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Scifi");
	gotoxy(20, 19);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Horror");
	gotoxy(20, 21);
	printf("\xDB\xDB\xDB\xDB\xB2 8. Wroc do Menu");
	gotoxy(20, 23);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20, 24);
	printf("Wpisz swoj wybor:");
	scanf_s("%d", &s);
	if (s == 8)

		mainmenu();
	system("cls");
	fp = fopen( "library.bin", "ab+");
	if (getdata() == 1)
	{
		a.gen =genre[s-1];
		fseek(fp, 0, SEEK_END);
		fwrite(&a, sizeof(a), 1, fp);
		fclose(fp);
		gotoxy(21, 14);
		printf("Ksi¹zka stworzona");
		gotoxy(21, 15);
		printf("Chcesz stworzyc wiecej?(t/n):");
		if (_getch() == 'n')
			mainmenu();
		else
			system("cls");
		addbooks();
	}
}
void deletebooks()
{
	FILE* fp;
	system("cls");
	int d;
	char another = 'y';
	while (another == 'y')
	{
		system("cls");
		gotoxy(10, 5);
		printf("Podaj ID ksiazki do usuniecia");
		scanf_s("%d", &d);
		fp = fopen("library.bin", "rb+");
		rewind(fp);
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (a.id == d)
			{
				gotoxy(10, 8);
				printf("Tytu³ ksiazki to: %s", a.title);
				findbook = 't';
			}
		}
		if (findbook != 't')
		{
			gotoxy(10, 10);
			printf("Taka ksi¹¿ka nie istnieje");
			if (_getch())
				mainmenu();
		}
		if (findbook == 't')
		{
			gotoxy(10, 9);
			printf("Czy chcesz usunac te ksiazke?(t/n):");
			if (_getch() == 't')
			{
				ft = fopen( "library.bin", "wb+");
				rewind(fp);
				while (fread(&a, sizeof(a), 1, fp) == 1)
				{
					if (a.id != d)
					{
						fseek(ft, 0, SEEK_CUR);
						fwrite(&a, sizeof(a), 1, ft);
					}
				}
				fclose(ft);
				fclose(fp);
				remove("library.bin");
				rename("test.bin ", "library.bin");
				fp = fopen("library.bin", "rb+");
				if (findbook == 't')
				{
					gotoxy(10, 10);
					printf("Udalo sie usunac ksiazke");
					gotoxy(10, 11);
					printf("Usunac kolejna ksiazke?(t/n)");
				}
			}
			else
				mainmenu();
			fflush(stdin);
			another = _getch();
		}
	}
	gotoxy(10, 15);
	mainmenu();
}
void searchbooks()
{
	FILE* fp;
	system("cls");
	int d;
	printf("*****************************SZUKAJ KSIAZKI*********************************");
	gotoxy(20, 10);
	printf("\xDB\xDB\xDB\xB2 1. Szukaj po ID");
	gotoxy(20, 14);
	printf("\xDB\xDB\xDB\xB2 2. Szukaj po tytule");
	gotoxy(15, 20);
	printf("Wpisz swoj wybor:");
	fp = fopen("library.bin", "rb+"); 
	rewind(fp);   
	switch (getch())
	{
	case '1':
	{
		system("cls");
		gotoxy(25, 4);
		printf("***Szukaj po ID****");
		gotoxy(20, 5);
		printf("Wpisz ID:");
		scanf_s("%d", &d);
		gotoxy(20, 7);
		printf("Szukanie........");
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (a.id == d)
			{
				Sleep(2);
				gotoxy(20, 8);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(20, 9);
				printf("\xB2 ID:%d", a.id); gotoxy(47, 9); printf("\xB2");
				gotoxy(20, 10);
				printf("\xB2 Tytul%s", a.title); gotoxy(47, 10); printf("\xB2");
				gotoxy(20, 11);
				printf("\xB2 Autor:%s ", a.Author); gotoxy(47, 11); printf("\xB2");
				gotoxy(20, 12);
				printf("\xB2 Gatunek: %d ", a.gen); gotoxy(47, 12); printf("\xB2"); gotoxy(47, 11); printf("\xB2");
				gotoxy(20, 13);
				printf("\xB2 Liczba stron: %d", a.pages); gotoxy(47, 13); printf("\xB2");
				gotoxy(20, 14);
				printf("\xB2 Rok wydania:%d ", a.year); gotoxy(47, 14); printf("\xB2");
				gotoxy(20, 15);
				printf("\xB2 Okladka: %d ", a.cover); gotoxy(47, 15); printf("\xB2");
				gotoxy(20, 17);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				findbook = 't';
			}

		}
		if (findbook != 't')
		{
			gotoxy(20, 8);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(20, 9); printf("\xB2");  gotoxy(38, 9); printf("\xB2");
			gotoxy(20, 10);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(22, 9); printf("\aNie ma takiej ksiazki");
		}
		gotoxy(20, 17);
		printf("Chcesz sprobowac jeszcze raz?(T/N)");
		if (_getch() == 't')
			searchbooks();
		else
			mainmenu();
		break;
	}
	case '2':
	{
		char s[50];
		system("cls");
		gotoxy(25, 4);
		printf("****Szukaj ksiazki po tytule****");
		gotoxy(20, 5);
		printf("Podaj tytul:");
		scanf("%s", s);
		int d = 0;
		while (fread(&a, sizeof(a), 1, fp) == 1)
		{
			if (strcmp(a.title, (s)) == 0)
			{
				gotoxy(20, 8);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(20, 9);
				printf("\xB2 ID:%d", a.id); gotoxy(47, 9); printf("\xB2");
				gotoxy(20, 10);
				printf("\xB2 Tytul:%s", a.title); gotoxy(47, 10); printf("\xB2");
				gotoxy(20, 11);
				printf("\xB2 Autor:%s", a.Author); gotoxy(47, 11); printf("\xB2");
				gotoxy(20, 12);
				printf("\xB2 Rok wydania:%d", a.year); gotoxy(47, 12); printf("\xB2");
				gotoxy(20, 13);
				printf("\xB2 Gatunek: %s", a.gen); gotoxy(47, 13); printf("\xB2");
				gotoxy(20, 14);
				printf("\xB2 Liczba stron:%d ", a.pages); gotoxy(47, 14); printf("\xB2");
				gotoxy(20, 15);
				printf("\xB2 Rodzaj okladki: %d", a.cover); gotoxy(47, 15); printf("\xB2");
				gotoxy(20, 17);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				d++;
			}
		}
		if (d == 0)
		{
			gotoxy(20, 8);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(20, 9); printf("\xB2");  gotoxy(38, 9); printf("\xB2");
			gotoxy(20, 10);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(22, 9); printf("\aNie ma takiej ksiazki");
		}
		gotoxy(20, 17);
		printf("Chcesz sprobowac jeszcze raz?(T/N)");
		if (_getch() == 't')
			searchbooks();
		else
			mainmenu();
		break;
	}
	default:
		_getch();
		searchbooks();
	}
	fclose(fp);
}
void viewbooks(void)  //show the list of book persists in library
{
	FILE* fp;
	int i = 0, j;
	system("cls");
	gotoxy(1, 1);
	printf("*********************************Lista ksiazek*****************************");
	gotoxy(2, 2);
	printf("GATUNEK     ID   TYTUL    AUTOR     ILOSC STRON    ROK WYDANIA     RODZAJ OKLADKI ");
	j = 4;
	fp = fopen("library.bin", "rb");
	while (fread(&a, sizeof(a), 1, fp) == 1)
	{
		gotoxy(3, j);
		printf("%s", a.gen);
		gotoxy(16, j);
		printf("%d", a.id);
		gotoxy(22, j);
		printf("%s", a.title);
		gotoxy(36, j);
		printf("%s", a.Author);
		gotoxy(50, j);
		printf("%d", a.pages);
		gotoxy(57, j);
		printf("%d", a.year);
		gotoxy(69, j);
		printf("%d", a.cover);
		printf("\n\n");
	}
	fclose(fp);
	gotoxy(35, 25);
	returnfunc();
}
int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while (fread(&a, sizeof(a), 1, fp) == 1)
		if (a.id == t)
			return 0;  //returns 0 if book exits
	return 1; //return 1 if it not
}
int t(void) //for time
{
	time_t t;
	time(&t);
	printf("Data i godzina:%s\n", ctime(&t));

	return 0;
}
void returnfunc(void)
{
	{
		printf(" Nacisnij ENTER by wrocic do Menu");
	}
a:
	if (_getch() == 13) //allow only use of enter
		mainmenu();
	else
		goto a;
}
int getdata()
{
	int t;
	gotoxy(20, 3); printf("Podaj informacje ponizej");
	gotoxy(20, 4); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20, 5);
	printf("\xB2"); gotoxy(46, 5); printf("\xB2");
	gotoxy(20, 6);
	printf("\xB2"); gotoxy(46, 6); printf("\xB2");
	gotoxy(20, 7);
	printf("\xB2"); gotoxy(46, 7); printf("\xB2");
	gotoxy(20, 8);
	printf("\xB2"); gotoxy(46, 8); printf("\xB2");
	gotoxy(20, 9);
	printf("\xB2"); gotoxy(46, 9); printf("\xB2");
	gotoxy(20, 10);
	printf("\xB2"); gotoxy(46, 10); printf("\xB2");
	gotoxy(20, 11);
	printf("\xB2"); gotoxy(46, 11); printf("\xB2");
	gotoxy(20, 12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21, 5);
	printf("Gatunek:");
	gotoxy(31, 5);
	printf("%s", genre[s - 1]);
	gotoxy(21, 6);
	printf("ID:\t");
	gotoxy(30, 6);
	scanf_s("%d", &t);
	if (checkid(t) == 0)
	{
		gotoxy(21, 13);
		printf("\aTa ksiazka juz istnieje\a");
		_getch();
		mainmenu();
		return 0;
	}
	a.id = t;
	gotoxy(21, 7);
	printf("Tytul:"); gotoxy(33, 7);
	scanf("%s", a.title);
	gotoxy(21, 8);
	printf("Author:"); gotoxy(30, 8);
	scanf("%s", a.Author);
	gotoxy(21, 9);
	printf("Gatunki:"); gotoxy(31, 9);
	scanf("%s", &a.gen);
	gotoxy(21, 10);
	printf("Rok wydania:"); gotoxy(28, 10);
	scanf("%d", &a.year);
	gotoxy(21, 11);
	printf("Liczba stron:"); gotoxy(30, 11);
	scanf("%d", &a.pages);
	gotoxy(21, 12);
	printf("Rodzaj okladki:"); gotoxy(30, 11);
	scanf("%d", &a.cover);
	return 1;
}