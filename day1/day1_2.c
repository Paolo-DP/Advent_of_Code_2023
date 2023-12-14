#include <stdio.h>
#define STRING_BUFFER   64
#define N_DIGITS        10

int isCharNum(char a);
int getLeadingCharNum(char *string, int size);
int getTrailingCharNum(char *string, int size);
int getLeadingSpelledNum(char *string, int size);

const char * spelledNumsTable[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};
const int spelledNumsLen[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};

int main()
{
    FILE *fptrInput;
    FILE *fptrOutput;

    fptrInput = fopen("input1_1.txt", "r");
    fptrOutput = fopen("output1_2.txt", "w");

    char currentLine[STRING_BUFFER];

    int firstCharNum;
    int secondCharNum;

    /*
    First element is the spelled number converted to int
    second element is the leading or trailing index for first and second num respectively
    */
    int firstSpelledNum[2];
    int secondSpelledNum[2];

    int firstDigit;
    int secondDigit;
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

        firstCharNum = getLeadingCharNum(currentLine, textLen);
        secondCharNum = getTrailingCharNum(currentLine, textLen);
        
        fprintf(fptrOutput, "Digits are %d, %d\n", firstCharNum, secondCharNum);

        calibNum = (firstCharNum * 10) + secondCharNum;
        fprintf(fptrOutput, "Calibration num: %d\n", calibNum);

        sum += calibNum;
        fprintf(fptrOutput, "Current Sum = %d\n", sum);
    }


    //Solution
    printf("Sum of calibration nums = %d\n", sum);
    fprintf(fptrOutput, "\n\nSum: %d", sum);

    fclose(fptrInput);
    fclose(fptrOutput);
    return 0;
}

int isCharNum(char a)
{
    return (a >= '0' && a <= '9');
}

int getLeadingCharNum(char *string, int size)
{
    int checkIndex = 0;
    while(!isCharNum(string[checkIndex]) && checkIndex < size)
    {
        checkIndex++;
    }
    return string[checkIndex] - '0';
}
int getTrailingCharNum(char *string, int size){
    int checkIndex = size - 1;
    while(!isCharNum(string[checkIndex]) && checkIndex >= 0)
    {
        checkIndex--;
    }
    return string[checkIndex] - '0';
}

int parseLeadingNum(char* string, int size){
    int startIdx = 0;
    int spelledNum;
    while(startIdx < size)
    {
        if(isCharNum(string[startIdx]))
        {
            return (string[startIdx] - '0');
        }
        

    }
    return spelledNum;
}