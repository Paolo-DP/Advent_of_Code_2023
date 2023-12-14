#include <stdio.h>
#define STRING_BUFFER 64

int isCharNum(char a);

int main()
{
    FILE *fptrInput;
    FILE *fptrOutput;

    fptrInput = fopen("input1_1.txt", "r");
    fptrOutput = fopen("output1_1.txt", "w");

    char currentLine[STRING_BUFFER];
    char firstDigit;
    char secondDigit;
    int calibNum;
    int sum = 0;
    int checkIndex = 0;
    while(fgets(currentLine, STRING_BUFFER, fptrInput)){
        fprintf(fptrOutput, "Current Line:\t%s", currentLine);
        int textLen = 0; 
        while(currentLine[textLen] != '\n')
        {
            textLen++;
        }
        fprintf(fptrOutput, "Length:\t\t\t%d\n", textLen);

        checkIndex = 0;
        while(!isCharNum(currentLine[checkIndex]) && checkIndex < textLen)
        {
            checkIndex++;
        }
        //printf("isCharNum(%c) = %d\n", currentLine[checkIndex], isCharNum(currentLine[checkIndex]));
        firstDigit = currentLine[checkIndex];

        checkIndex = textLen-1;
        while(!isCharNum(currentLine[checkIndex]) && checkIndex >= 0)
        {
            checkIndex--;
        }
        secondDigit = currentLine[checkIndex];
        
        fprintf(fptrOutput, "Digits are %c, %c\n", firstDigit, secondDigit);

        calibNum = ((firstDigit - '0') * 10) + (secondDigit - '0');
        fprintf(fptrOutput, "Calibration num: %d\n", calibNum);

        sum += ((firstDigit - '0') * 10) + (secondDigit - '0');
        fprintf(fptrOutput, "Current Sum = %d\n", sum);
    }

    fprintf(fptrOutput, "\n\nSum: %d", sum);

    fclose(fptrInput);
    fclose(fptrOutput);
    return 0;
}

int isCharNum(char a)
{
    return (a >= '0' && a <= '9');
}