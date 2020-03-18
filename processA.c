#include <string.h>
void processA(char s[][33], long size){
    int i,j,k,l,m,dot=0;
    char bkpf, cs[] = ".!?";
    char* pf = 0;

    for(i=0;i<size-1;i+=2){
        for(j=i+2;j<size;j+=2){
            if((pf=strpbrk(s[j],cs))){//interpunkce
              bkpf=*pf;
              s[j][pf-s[j]] = '\0';
              dot=1;
          }

          int sc = !strcmp(s[i],s[j]);

          if (dot){//zpet
                s[j][pf-s[j]] = bkpf;
                dot = 0;
          }

          if(sc){
              if(i+2==j){ //rovnaji - a za sebou ?
                  //presmyk
                  for(k=i; k<size-2; k+=2){
                      strcpy(s[k],s[k+2]);
                  }
                  strcpy(s[k],"");
                  size-=2;
                  j-=2;
                  continue;
              }
              else{//rovnaji, ale ne vedle sebe
                   //jsou fráze vedle sebe?
                   //m=2;
                   ////for(l=i+m; l<size-i; l+=2, m+=2){
                   m=j;
                   for(l=i+2; l<j; l+=2,m+=2){
                       if((pf=strpbrk(s[l+2],cs))){
                           bkpf=*pf;
                           s[l+2][pf-s[l+2]] = '\0';
                           dot = 1;
                       }//if interpunkce

                       ////sc = strcmp(s[l],s[j+m]);
                       sc = strcmp(s[l],s[m+2]);

                       if (dot){//zpet
                           sc=0; // punkce - nerovnaji
                           s[l+2][pf-s[l+2]] = bkpf;
                           dot = 0;
                       }//if

                        if (sc){
                            break; //nerovnaji
                        } // if
                    }//for

                    if (sc){
                        break; //nerovnaji - next i
                    }
                    else{
                        //velky presmyk
                        for(l=j; l+j<=size; l+=2){
                            if (s[l+j-i-1][0]=='\n'){
                                 s[l][0]='\0';
                                 break;
                            }
                            strcpy(s[l],s[l+j-i]);
                        }//for//velky presmyk

                        strcpy(s[l-1],"\0");
                        size-=j;
                        j-=2;
                     //break;
                    }//else presmyk

                }//else ne vedle sebe
            }//if equal
        }//for j
    }//for i
}//f
