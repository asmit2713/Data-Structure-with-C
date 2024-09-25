#include <stdio.h>
#include <string.h>

#define MAX 100

void readStrings(char STR[], char PAT[], char REP[]) {
    printf("Enter the main string (STR): ");
    fgets(STR, MAX, stdin);
    STR[strcspn(STR, "\n")] = '\0';

    printf("Enter the pattern string (PAT): ");
    fgets(PAT, MAX, stdin);
    PAT[strcspn(PAT, "\n")] = '\0';

    printf("Enter the replace string (REP): ");
    fgets(REP, MAX, stdin);
    REP[strcspn(REP, "\n")] = '\0';
}

void findAndReplace(char STR[], char PAT[], char REP[]) {
    int i, j, k, found;
    int lenSTR = strlen(STR);
    int lenPAT = strlen(PAT);
    int lenREP = strlen(REP);

    char result[MAX];
    int resultIndex = 0;
    int foundFlag = 0;

    for (i = 0; i <= lenSTR - lenPAT; i++) {
        found = 1;
        for (j = 0; j < lenPAT; j++) {
            if (STR[i + j] != PAT[j]) {
                found = 0;
                break;
            }
        }
        
        if (found == 1) {
            foundFlag = 1;
            for (k = 0; k < lenREP; k++) {
                result[resultIndex++] = REP[k];
            }
            i += lenPAT - 1;
        } else {
            result[resultIndex++] = STR[i];
        }
    }
    
    while (i < lenSTR) {
        result[resultIndex++] = STR[i++];
    }
    
    result[resultIndex] = '\0';

    if (foundFlag) {
        printf("The new string after replacement: %s\n", result);
    } else {
        printf("Pattern not found in the main string.\n");
    }
}

int main() {
    printf("Asmit's (1AY23CS044) program!\n\n");

    char STR[MAX], PAT[MAX], REP[MAX];
    
    printf("This is Asmit's program\n");
    
    readStrings(STR, PAT, REP);
    
    findAndReplace(STR, PAT, REP);
    
    return 0;
}
