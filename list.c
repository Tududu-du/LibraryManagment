#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char title[50];
	char author[50];
	char cover[10];
	char genre[20];
	int year;
	int pages;
}book;

bool write_data(char *filename, book *data, int total);
book *read_data(char *filename, int *total);

int list() {
	book *library;
	library = malloc(sizeof(book) * 25);
	
	strcpy(library[0].title, "Diuna");
	strcpy(library[0].author, "Frank Herbert");
	strcpy(library[0].genre, "fantasy");
	library[0].year = 2020;
	library[0].pages = 604;
	strcpy(library[0].cover, "miekka");

	strcpy(library[1].title, "Rzeznia numer piec");
	strcpy(library[1].author, "Kurt Vonnegut Jr.");
	strcpy(library[1].genre, "scifi");
	library[1].year = 1989;
	library[1].pages = 275;
	strcpy(library[1].cover, "twarda");
	
	strcpy(library[2].title, "Historia Pszczol");
	strcpy(library[2].author, "Maja Lunde");
	strcpy(library[2].genre, "scifi");
	library[2].year = 2015;
	library[2].pages = 520;
	strcpy(library[2].cover, "twarda");

	strcpy(library[3].title, "Blade Runner");
	strcpy(library[3].author, "Philip K. Dick");
	strcpy(library[3].genre, "scifi");
	library[3].year = 1990;
	library[3].pages = 271;
	strcpy(library[3].cover, "twarda");

	strcpy(library[4].title, "Lod");
	strcpy(library[4].author, "Jacek Dukaj");
	strcpy(library[4].genre, "fantasy");
	library[4].year = 2008;
	library[4].pages = 1051;
	strcpy(library[4].cover, "twarda");

	strcpy(library[5].title, "Idiota");
	strcpy(library[5].author, "Fyodor Dostoevsky");
	strcpy(library[5].genre , "novel");
	library[5].year = 2003;
	library[5].pages = 667;
	strcpy(library[5].cover, "miekka");

	strcpy(library[6].title, "Paragraf 22");
	strcpy(library[6].author, "Joseph Heller");
	strcpy(library[6].genre, "novel");
	library[6].year = 2019;
	library[6].pages = 480;
	strcpy(library[6].cover, "miekka");

	strcpy(library[7].title, "Miecz dla Krola");
	strcpy(library[7].author, "T.H. White");
	strcpy(library[7].genre, "fantasy");
	library[7].year = 2008;
	library[7].pages = 366;
	strcpy(library[7].cover, "miekka");

	strcpy(library[8].title, "Astrofizyka dla zabieganych");
	strcpy(library[8].author, "Neil deGrasse Tyson");
	strcpy(library[8].genre, "popularnonaukowa");
	library[8].year = 2017;
	library[8].pages = 222;
	strcpy(library[8].cover, "twarda");

	strcpy(library[9].title, "Fight Club. Podziemny krag");
	strcpy(library[9].author, "Chuck Palahniuk");
	strcpy(library[9].genre, "novel");
	library[9].year = 2006;
	library[9].pages = 235;
	strcpy(library[9].cover, "miekka");

	strcpy(library[10].title, "Zlodziejka ksiazek");
	strcpy(library[10].author, "Markus Zusak");
	strcpy(library[10].genre, "novel");
	library[10].year = 2019;
	library[10].pages = 496;
	strcpy(library[10].cover, "miekka");

	strcpy(library[11].title, "Les Misrables");
	strcpy(library[11].author, "Victor Hugo");
	strcpy(library[11].genre, "novel");
	library[11].year = 2012;
	library[11].pages = 1272;
	strcpy(library[11].cover, "miekka");

	strcpy(library[12].title, "Lsnienie");
	strcpy(library[12].author, "Stephen King");
	strcpy(library[12].genre, "horror");
	library[12].year = 1997;
	library[12].pages = 520;
	strcpy(library[12].cover, "miekka");

	strcpy(library[13].title, "Bastion");
	strcpy(library[13].author, "Stephen King");
	strcpy(library[13].genre, "horror");
	library[13].year = 2018;
	library[13].pages = 1088;
	strcpy(library[13].cover, "twarda");

	strcpy(library[14].title, "Zabic Drozda");
	strcpy(library[14].author, "Harper Lee");
	strcpy(library[14].genre, "novel");
	library[14].year = 2008;
	library[14].pages = 421;
	strcpy(library[14].cover, "miekka");

	strcpy(library[15].title, "Nie zdaze");
	strcpy(library[15].author, "Olga Gitkiewicz");
	strcpy(library[15].genre, "reportaz");
	library[15].year = 2019;
	library[15].pages = 240;
	lstrcpy(library[15].cover, "miekka");

	strcpy(library[16].title, "Zapasc. Reportaze z mniejszych miast");
	strcpy(library[16].author, "Marek Szymaniak");
	strcpy(library[16].genre, "reportaz");
	library[16].year = 2021;
	library[16].pages = 256;
	strcpy(library[16].cover, "twarda");

	strcpy(library[17].title, "Good Economics");
	strcpy(library[17].author, "Abhijit V. Banerjee");
	strcpy(library[17].genre, "ekonomia");
	library[17].year = 2022;
	library[17].pages = 528;
	strcpy(library[17].cover, "miekka");

	strcpy(library[18].title, "Sklepik z marzeniami");
	strcpy(library[18].author, "Stephen King");
	strcpy(library[18].genre, "horror");
	library[18].year = 2010;
	library[18].pages = 672;
	strcpy(library[18].cover, "twarda");

	strcpy(library[19].title, "Ojciec Chrzestny");
	strcpy(library[19].author, "Mario Puzo");
	strcpy(library[19].genre, "novel");
	library[19].year = 2006;
	library[19].pages = 478;
	strcpy(library[19].cover, "twarda");

	if (write_data("library.bin", library, 20))
		printf("Wypisz dane \n");
	else {
		printf("B³¹d w zapisie do pliku");
		return 1;
	}
free(library);
int total = 0;
book *file_data;

file_data = read_data("library.bin", &total);
if (file_data == NULL) {
	printf("Nie mo¿na wczytaæ pliku. \n");
	return 1;
}
printf("\nDane wczytane\n\n");
for (int i = 0; i < total; i++) {
	printf("Id %d\n", i + 1);
	printf("Tytu³: %s\n", file_data[i].title);
	printf("Autor: %s\n", file_data[i].author);
	printf("Gatunek: %s\n", file_data[i].genre);
	printf("Rok wydania: %d\n", file_data[i].year);
	printf("Liczba stron: %d\n", file_data[i].pages);
	printf("Rodzaj okladki: %s\n", file_data[i].cover);
	printf("\n");
}
free(file_data);
	return 0;
}

bool write_data(char *filename, book *data, int total) {
	FILE* file;
	file = fopen( filename, "wb");
	if (file == NULL) return false;
	if (fwrite(&total, sizeof(int), 1, file) != 1)
		return false;
	if (fwrite(data, sizeof(book), total, file) != total)
		return false;
	if (fclose(file) == EOF)
		return false;

	return true;
}
book* read_data(char* filename, int* total) {
	FILE *file;
	file = fopen(filename, "rb");
	if (file == NULL)
		return NULL;

	if (fread(total, sizeof(int), 1, file) != 1)
		return NULL;

	book* data = malloc(sizeof(book) * *total);
	if (fread(data, sizeof(book), *total, file) != *total) {
		free(data);
		return NULL;
	}
	if (fclose(file) == EOF) {
		free(data);
		return NULL;
	}
	return data;
}
