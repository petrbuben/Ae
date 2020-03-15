//Petr Buben

//testovat možno se všemi subory níže v fopen, jsou přiložené v adresari

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readA(char[][33], FILE*, long*);
void processA(char [][33], long);
int alloc(char[][33]);
void printA(char[][33], FILE*);

int main()
{
    FILE *f=NULL, *fres=NULL;
    char ch='\0';
    long wrds =0L;

    //f = fopen("oko.txt", "r");
    //f = fopen("oko1.txt", "r");
    //f = fopen("ska.txt", "r");
    f = fopen("nepr2.txt", "r");
    //f = fopen("ska2.txt", "r");


    if(!f){
            printf("%s","Cannot open file");
            return 1;
    }

    fres = fopen("result.txt", "w");
    if(!fres){
            printf("%s","Cannot open file");
            return -1;
    }

    char (*s)[33]=NULL;

    ///kolik mezer - slov souboru
    for (ch = fgetc(f); ch != EOF; ch = fgetc(f))
        if (ch == ' ' || ch=='\n')
            wrds++;
    wrds = wrds*2;

    printf("slov i mezer %ld\n", wrds);

    //rewind
    (void)fseek(f, 0L, SEEK_SET);

    s = calloc(wrds, sizeof(*s));


    //read file
    readA (s,f, &wrds);

    printf("%s", "soubor nacten, pole pred zpracovanim\n");
    for(int i=0; i<wrds; i++)
        if (s[i][0])
            //printf("%s",s[i]);
            fputs(s[i],stdout);
        else
            break;

    //process array
    processA(s,wrds);

    //print array into file
    printA(s, fres);

    printf("%s", "\n\npole po zpracovani\n");
    for(int i=0; i<wrds; i++)
       if (s[i][0])
           printf("%s",s[i]);
       else
           break;

    printf ("%s","\n\nvysledny soubor je result.txt\n\n");

    fclose(f);
    fclose(fres);

    //system("pause");
    return 0;
}

