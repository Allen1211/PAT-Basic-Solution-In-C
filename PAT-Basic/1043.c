#include <stdio.h>

int main(){
    int P,A,T,e,s,t;
    P=0,A=0,T=0,e=0,s=0,t=0;
    char ch;
    while((ch=getchar())!='\n'){
        switch(ch){
            case 'P':P++;break;
            case 'A':A++;break;
            case 'T':T++;break;
            case 'e':e++;break;
            case 's':s++;break;
            case 't':t++;break;
            default:break;
        }
    }
    while(P||A||T||e||s||t){
        if(P>0){
            putchar('P');
            P--;
        } 
        if(A>0){
            putchar('A');
            A--; 
        } 
        if(T>0){
            putchar('T'); 
            T--;
        }
        if(e>0){
            putchar('e'); 
            e--;
        } 
        if(s>0){
            putchar('s');  
            s--;
        } 
        if(t>0){
            putchar('t');
            t--;
        }
    }
    return 0;
}