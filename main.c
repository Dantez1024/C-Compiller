//Author  Leinad Cybre
//Program to scan lexemes from C code

#include <stdio.h> //standard I/O
#include <string.h> //to allow input to be line of code
#include <stdbool.h> //boolean function
#include <stdlib.h>

bool isDelimeter = false, isOperator = false, validID = true;





bool checkChar(char ch[],char ch2)
{
    int arrLen = strlen(ch) ;

    int isIn = 0;

    for(int i =0; i < arrLen; i++)
    {
        if(ch[i] == ch2)
        {
            isIn = 1;
            break;
        }
    }

    if(isIn)
    {
        return true;
    } else
    {
        return false;
    }
}

//Returns true if the character is delimeter
bool setBoolValues(char ch,char ch2[])
{
    char delimeter [] ={'/','+','-','*',']','['};
    char operand [] = {'+', '-', '/', '*','='};
    char badIds [] = {'1', '2', '3', '4', '5', '6', '7', '8', '9','0'};

    bool isDel, isOp, validID2;

    if(checkChar(delimeter, ch)) {
         isDelimeter = true;
    }
    if(checkChar(operand, ch)) {
         isOperator = true;
    }


    if(checkChar(badIds, ch) || checkChar(delimeter, ch)) {
         validID = false;
    }


    return true;

}
void resetBoolValues()
{
    bool isDelimeter=false, isOperator = false, validID = true;
}

int getSize(char ch[])
{
    int codeLn = strlen(ch) ;

    return codeLn;
}
//returns the size of a character array using a pointer to the first element of the character array
/*
int size(char *ptr)
{
    //variable used to access the subsequent array elements.
    int offset = 0;
    //variable that counts the number of elements in your array
    int count = 0;

    //While loop that tests whether the end of the array has been reached
    while (*(ptr + offset) != '\0')
    {
        //increment the count variable
        ++count;
        //advance to the next element of the array
        ++offset;
    }
    //return the size of the array
    return count;
}
*/


int main()
{
    //maximum length for my string is 100
    char str[100];

    //input
    printf("Type line of code : \n");
    scanf("%[^\n]",&str);

    int codeLn = getSize(str);

    printf("Code has %d \n",codeLn);

    for(int i = 0; i<codeLn; i++)
    {
        setBoolValues(str[i], str);

        printf("%d. %c Code Results : \n IsDelimeter => %i \n IsOperator => %i \n Valid Identifier => %i \n",i,str[i],isDelimeter,isOperator,validID);

        resetBoolValues();
    }








   return 0;
}
