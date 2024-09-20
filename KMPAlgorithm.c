#include<stdio.h>
#include<string.h>

void calculate_lps(char* pattern, int m, int* lps){
    int length=0;
    int i=1;
    lps[0]=0;
    
    while(i<m){
        if(pattern[i]==pattern[length]){
            length++;
            lps[i]=length;
            i++;
        }else{
            if(length!=0){
                length=lps[length-1];
            }else{
                lps[i]=length;
                i++;
            }
        }
    }
}

void find_pattern(char* pattern, char* text){
    
    int m=strlen(pattern);
    int n=strlen(text);
    int i=0;
    int j=0;
    int lps[m];
    calculate_lps(pattern,m,lps);
    int x=0;
    
    printf("The length of the pattern is : %d\n",strlen(pattern));
    
    printf("The lps array is : ");
    for(x=0;x<m;x++){
        printf("%d ",lps[x]);
    }
    printf("\n");
    
    
    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==m){
            printf("Pattern found at %dth position\n",i-j+1);
        }else if(i<n&&pattern[j]!=text[i]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
    
}


int main(void){
    char pattern[]="AABCDAAB";
    char text[]="ABCDEABAABCDAAB";
    find_pattern(pattern,text);
    return 0;
    
}
