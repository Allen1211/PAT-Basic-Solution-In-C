#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[1001];
    int count[26] = {0};
    gets(str);
    for(int i=0;i<strlen(str);i++){
        char ch = str[i];
        if(isalpha(ch)){
            ch = tolower(ch);
            count[(int)(ch-'a')]++;
        }
    }
    int max=0;
    char maxch;
    for(int i=0;i<26;i++){
        if(count[i]>max){
            maxch = (char)(i+'a');
            max = count[i];
        }
    }
    printf("%c %d",maxch,max);
    return 0;
}