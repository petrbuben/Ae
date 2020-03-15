#include <stdio.h>

void printA ( char s[][33], FILE* fres){
    for(int i=0;;i++)
        if (s[i][0])
            fprintf(fres,"%s",s[i]);
    else
        break;


}
