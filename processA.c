#include <string.h>
void processA(char s[][33], long size){
    int i,j,k,l,m,dot=0;
    char bkpf, cs[] = ".!?";
    char* pf = 0;

    for(i=0;i<size-1;i+=2){
        for(j=i+2;j<size;j+=2){

          if((pf=strpbrk(s[j],cs))){ //interpunkce
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
                    for(k=i; k<size-1; k+=2){
                         strcpy(s[k],s[k+2]);
                    }
                    strcpy(s[k],"");
                    size-=2;
                    j-=2;
                    continue;
                }
                else{//rovnaji, ale ne vedle sebe
                    //co je mezi?
                    m=2;
                    for(l=i+m; l<size-i; l+=2, m+=2){

                        if((pf=strpbrk(s[j+m],cs))){
                            bkpf=*pf;
                            s[j+m][pf-s[j+m]] = '\0';
                            dot = 1;
                        }//if interpunkce

                        sc = strcmp(s[l],s[j+m]);

                        if (dot){//zpet
                            s[j+m][pf-s[j+m]] = bkpf;
                            dot = 0;
                        }//if

                        if (sc){
                            break; //nerovnaji
                        }
                        else{
                            //velky presmyk
                            for(l=j; l<size-m-1; l+=2){
                                strcpy(s[l],s[l+m+2]);
                            }//for//velky presmyk

                            strcpy(s[l-m+1],"\0");
                            size-=(m*2);
                            j-=2;
                            break;
                        }//else rovnaji se
                    }//for
                }//else ne vedle sebe
            }//if equal
        }//for j
    }//for i
}
