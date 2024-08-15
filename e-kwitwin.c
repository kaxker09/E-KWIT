#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 256

int wynik=5;
char path [MAX_LEN];

void przeslij_kwit();
void gotowy_wzor();

void zloz_wniosek(){

    int choice;

    printf("Wybierz opcje rzucania kwitem:\n");
    printf("1)Podpisz gotowy wzór.\n");
    printf("2)Prześlij własny kwit.\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            gotowy_wzor(path);
            break;
        case 2:
            przeslij_kwit();
            break;
    }

}

void gotowy_wzor(){
    FILE *fp;
    char podpis [MAX_LEN];
    char plik [MAX_LEN];
    char tekst [] = "RZUCAM KWITEM!";

    strcpy(path, "kwit.txt");

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    while (1){
        printf("Podpisz się!\n");
        fflush(stdout);
        fgets(podpis, MAX_LEN, stdin);
        podpis[strcspn(podpis, "\n")] = '\0';

        fp = fopen("kwit.txt", "w");
        if (fp == NULL) {
            printf("Nie można utworzyć gotowego wzoru!\n");
        }

        fprintf(fp, "RZUCAM KWITEM!");

        fprintf(fp, "\n%s", podpis);

        fclose(fp);

        fp = fopen("kwit.txt", "r");
        fgets(plik,MAX_LEN,fp);
        path[strcspn(path, "\n")] = '\0';

        wynik = strncmp(tekst,plik,14);

        if(wynik == 0 ){
            printf("Twój kwit został przyjęty!");
        }
        else{
            printf("Sprawdź czy twój kwit jest zgodny ze wzorem!");

        }

        fclose(fp);

        break;

    }

}

void przeslij_kwit(){
    system("cls");

    FILE *fp;

    char tekst [] = "RZUCAM KWITEM!";
    char plik [MAX_LEN];


    printf("Podaj ścieżkę pliku na której umieszczony jest twój plik\nlub wpisz nazwę pliku jeśli jest on w tym samym folderze co pliki programu\n");
    scanf("%s", path);

    fp = fopen(path,"r");

    if(fp == NULL){
        printf("Błąd otwarcia pliku przez system\n");
        return;
    }

    fgets(plik,MAX_LEN,fp);
    path[strcspn(path, "\n")] = '\0';

    wynik = strncmp(tekst,plik,14);

    if(wynik == 0 ){
        printf("Twój kwit został przyjęty!");
    }
    else{
        printf("Sprawdź czy twój kwit jest zgodny ze wzorem!");

    }

    fclose(fp);

}

void instrukcja(){
    system("cls");

    printf("Aby rzucić kwitem wybierz opcje \"Złóż wniosek\",\na następnie wybierz jedną z dostępnych opcji.\n");
    printf("W opcji 1) wystarczy złożyć swój podpis.\n");
    printf("W opcji 2) należy wkleić ścieżke pod którą zapisany jest twój wniosek o zwolnienie ze służby.\n");
    printf("Wniosek o zwolnienie ze służby musi być zgodny ze wzorem.\n");
    printf("Wzór możesz sprawdzić w opcji \"Sprawdź wzór\".\n");

}

void check(int wynik){
    system("cls");

    if (wynik == 0)
        printf("Twój kwit został przyjęty!\n");
    else
        printf("Twój kwit nie został przyjęty\n");
}

void read_file(char sciezka[MAX_LEN]){
    system("cls");

    FILE *fp;

    char tekst [MAX_LEN];

    fp = fopen(sciezka, "r");

    if(fp == NULL)
    {
        printf("Błąd otwarcia pliku\n", sciezka);
        return;
    }

    while (fgets(tekst, MAX_LEN, fp) != NULL){
        printf("%s", tekst);
    }

    fclose(fp);
}

void informacje(){
    printf("System jest odpowiedzią na potrzeby Sił Zbrojnych RP\n");
    printf("Umożliwia on zdalne rzucenie kwitem.\n");
    printf("Od dziś już nie trzeba podchodzić do biurka dyżurnego!\n");
    printf("\n");
    printf("Autor: pchor K.K\n");
    printf("Data wydania: 15.08.2024\n");
}

void sprawdz_wzor(){
    printf("Wzór wniosku o zwolnienie ze służby:\n");
    printf("RZUCAM KWITEM!");
    printf("\n");
    printf("---Imię NAZWISKO---\n");
}

void sleep_ms(int miliseconds){
    usleep(miliseconds*1000);
}

void witaj(){
    char witaj [] = "WITAJ W SYSTEMIE E-KWIT!";
    int i;
    int size_witaj;
    int size_char;
    int length;

    size_char = sizeof(char);
    size_witaj = sizeof witaj;
    length = size_witaj/size_char;

    witaj[strcspn(witaj, "\n")] = '\0';

    printf("\t\t");

    for (i =0; i<length-1; i++){
        putchar(witaj[i]);
        fflush(stdout);
        sleep_ms(250);
    }
}

void napis_wp(){

    char tekst [6][40] = {
            {"\t\t\t " " "" "" "" "" "" "" "" "" "" "" "" ""_""_""_ "                },
            {"\t\t\t ""|      |   |   |"},
            {"\t\t\t ""|      |   | __|"},
            {"\t\t\t ""|  /\\  |   |    "},
            {"\t\t\t ""| /  \\ |   |       "},
            {"\t\t\t ""|/    \\|   |    "}
    };
    int i;
    int j;

    for(i=0;i<5;i++){
        for(j=0;j<20;j++){
            printf("%c", tekst[i][j]);
        }
        printf("\n");
    }


    printf("\n\t\t\t Wojsko Polskie\n");

}

int main() {
    int choice;

    napis_wp();

    sleep(2);

    witaj();

    while (1){
        system("cls");

        printf("\n\t\t-----SYSTEM E-KWIT------\n");
        printf("WYBIERZ NUMER:\n");
        printf("1)Złóż wniosek\n");
        printf("2)Sprawdź czy wniosek został przyjęty\n");
        printf("3)Podejrzyj swój wniosek\n");
        printf("4)Instrukcja\n");
        printf("5)Sprawdż wzór\n");
        printf("6)O programie\n");
        printf("7)Wyjdż\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                zloz_wniosek();
                break;
            case 2:
                check(wynik);
                break;
            case 3:
                read_file(path);
                break;
            case 4:
                instrukcja();
                break;
            case 5:
                sprawdz_wzor();
                break;
            case 6:
                informacje();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Kliknąłes zły przycisk. Wciśnij przysik od 1 do 5\n");
        }
    }

    return 0;
}
