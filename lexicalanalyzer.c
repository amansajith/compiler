//LEXICALANALYZER
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_KEYWORDS 100
#define MAX_HEADER 100
#define MAX_SPECIAL 100
#define MAX_OPERATORS 100

// Function to check if a character is a special character
bool isSpecial(char c, char special[][100], int specialCount) {
    for (int i = 0; i < specialCount; i++) {
        if (c == special[i][0]) {
            return true;
        }
    }
    return false;
}


// Function to check if a character is an operator
bool isOperator(char c, char operators[][100], int operatorCount) {
    for (int i = 0; i < operatorCount; i++) {
        if (c == operators[i][0]) {
            return true;
        }
    }
    return false;
}

// Function to check if a string is a valid identifier
int isValidIdentifier(char *str, char special[][100], int specialCount) {
    if (isalpha(str[0])) {
        for (int i = 1; i < strlen(str); i++) {
            if (!isalnum(str[i])) {
                return 0;
            }
        }
        return 2;
    } else if (isdigit(str[0])) {
        for (int i = 1; i < strlen(str); i++) {
            if (!isdigit(str[i])) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *fp;
    char buffer[100];
    char keywords[MAX_KEYWORDS][100];
    char header[MAX_HEADER][100];
    char special[MAX_SPECIAL][100];
    char operators[MAX_OPERATORS][100];
    int keywordCount = 0, specialCount = 0, operatorCount = 0, headercount = 0;

    // Read keywords from file
    FILE *kw = fopen("keywords.txt", "r");
    while (fscanf(kw, "%s", keywords[keywordCount]) == 1) {
        keywordCount++;
    }
    fclose(kw);
    
    // Read headers from file
    FILE *hd = fopen("header.txt", "r");
    while (fscanf(hd, "%s", header[headercount]) == 1) {
        headercount++;
    }
    fclose(hd);

    // Read special characters from file
    FILE *sc = fopen("special.txt", "r");
    while (fscanf(sc, "%s", special[specialCount]) == 1) {
        specialCount++;
    }
    fclose(sc);

    // Read operators from file
    FILE *op = fopen("operators.txt", "r");
    while (fscanf(op, "%s", operators[operatorCount]) == 1) {
        operatorCount++;
    }
    fclose(op);

    fp = fopen("program.c", "r");
    if (fp == NULL) {
        printf("Error opening file");
        return 0;
    }

    while (fscanf(fp, "%s", buffer) == 1) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        
        
        
        
        int flag = 3; // 0 = keyword, 1 = special, 2 = operator, 3 = identifier

        // Check if the buffer is a keyword
        for (int i = 0; i < keywordCount; i++) {
            if (strcmp(buffer, keywords[i]) == 0) {
                printf("Keyword : %s\n", buffer);
                flag = 0;
                break;
            }
        }
        // check fo header
        for (int i = 0; i < headercount; i++) {
            if (strcmp(buffer, header[i]) == 0) {
                printf("header : %s\n", buffer);
                flag = 4;
                break;
            }
        }
        

        // Check if the buffer is a special character
        if (flag == 3) {
            for (int i = 0; i < specialCount; i++) {
                if (strcmp(buffer, special[i]) == 0) {
                    printf("Special Character : %s\n", buffer);
                    flag = 1;
                    break;
                }
            }
        }

        // Check if the buffer is an operator
        if (flag == 3) {
            for (int i = 0; i < operatorCount; i++) {
                if (strcmp(buffer, operators[i]) == 0) {
                    printf("Operator : %s\n", buffer);
                    flag = 2;
                    break;
                }
            }
        }

        // Check if the buffer is an identifier
        if (flag == 3) {
            if (isValidIdentifier(buffer, special, specialCount) == 2) {
                printf("Identifier : %s\n",buffer);
            } 
            
            else if (isValidIdentifier(buffer, special, specialCount) == 1)
            {
                printf("Integer : %s\n", buffer);
            }

            else
            {
                printf("Invalid Identifier : %s\n",buffer);
            }
        }
    }

    fclose(fp);

    return 0;
}


//input
/*
# include <stdio.h>
int main ( ) {    

    int number1 , number2 , sum ;
    
   
    scanf ( " % d % d " , & number1 , & number2 ) ;

    
    sum = number1 + number2 ;      
    
    printf ( " % d + % d = % d " , number1 , number2 , sum ) ;
    return 0 ;
}
*/


