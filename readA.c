#include <stdio.h>

void readA(char s[][33], FILE* f, long* wrds)
{
    int charAsInt, a=0, b=0;
    char c;

    while( (charAsInt = getc(f)) != EOF ) // Loop stops at EOF
    {
        c = (char) charAsInt;                    // Convert Int to Char

        if( c==' '){
            a++; b=0;
            s[a][b] = ' ';
            long p = ftell(f);
            if ((char)getc(f) != '\n'){  //odstranit mezera plus \n
                fseek( f, p, SEEK_SET );
                a++;
            }
            else{
                fseek( f, p, SEEK_SET );
                (*wrds)--;
                a--;
            }

            continue;
        }

        if (c=='\n'){            // If Char is a space or newline
            a++;
            b=0;
            s[a][b] = '\n';
            a++;
            continue;
        }
        s[a][b] = c;
        b++;
    }
}
