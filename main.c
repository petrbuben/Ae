//Petr Buben

//testovat možno se všemi subory níže v fopen, jsou přiložené v adresari

#include "main.h"

int main()
{
    FILE *f=NULL, *fres=NULL;
    char (*s)[33]=NULL;
    char ch='\0';
    long wrds =0L;

    //f = fopen("oko.txt", "r");
    //f = fopen("pom.txt", "r");
    f = fopen("ska2.txt", "r");
    //f = fopen("nepr1.txt", "r");

    if(!f){
            printf("%s","Cannot open file");
            return 1;
    }

    fres = fopen("result.txt", "w");
    if(!fres){
            printf("%s","Cannot open file");
            return -1;
    }

    ///kolik mezer - slov souboru
    for (ch = fgetc(f); ch != EOF; ch = fgetc(f))
        if (ch == ' ' || ch=='\n')
            wrds++;
    wrds = wrds*2;

    printf("slov i mezer %ld\n", wrds);

    //rewind
    (void)fseek(f, 0L, SEEK_SET);

    s = calloc(wrds, sizeof(*s)+1);


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
    free (s);

    //system("pause");
    return 0;
}

