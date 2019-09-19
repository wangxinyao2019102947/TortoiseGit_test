#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>
 
const size_t WORDSIZE = 60;
const size_t MAXSIZE = 100;
 
typedef struct Word {
    char word[WORDSIZE];
    size_t size;
}WORD;
 
int addWord(WORD a[],int n,char word[]) {
    int i;
    
    for(i = 0; i < n; ++i) {
        if(strcmp(a[i].word,word) == 0) {
            ++a[i].size;
            return n;
        }
    }
    strcpy(a[n].word,word);
    a[n].size = 1;
    return n + 1;
}
 
void mysort(WORD a[], int n) {
    int i,j,k;
    WORD t;
    for(i = 0; i < n - 1; ++i) {
        k = i;
        for(j = i + 1; j < n; ++j) {
            if(a[k].size < a[j].size)
                k = j;
        }
        if(i != k) {
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
}
 
int pickupword(char *statement, char words[][WORDSIZE]) {
    int i = 0,j,n = 0;
    while(statement[i]) {
        j = 0;
        while(!isalpha(statement[i]) && statement[i]) ++i;
        while(isalpha(statement[i]) && statement[i])
            words[n][j++] = statement[i++];
        if(j) {
            words[n][j] = 0;
            ++n;
        }
    }
    return n;
}
 
void show(WORD a[], int n) {
    int i;
    for(i = 0; i < n; ++i)
        printf("%s : %d\n",a[i].word,a[i].size);
    printf("\n");
}
 
int main() {
    WORD a[MAXSIZE];
    int i,n = 0,m,len;
    char str[2 * MAXSIZE],words[MAXSIZE][WORDSIZE];
    memset((void *)a,0,sizeof(a));
    while(fgets(str,2 * MAXSIZE,stdin)) {
        len = strlen(str);
        if(str[len - 1] == '\n') str[len - 1] = 0;
        m = pickupword(str,words);
        for(i = 0; i < m; ++i)
            n = addWord(a,n,words[i]);
        if(n) {
            mysort(a,n);
            show(a,n);
        }
        printf("total:%d\n",m);
    }
    return 0;
}
