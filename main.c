//Author  Leinad Cybre
//A C lexical analyzer
//Program to scan lexemes from C code


#include <stdio.h> //standard I/O
#include <string.h> //to allow input to be line of code
#include <stdbool.h> //boolean function
#include <stdlib.h>
#include <ctype.h>

int isDelimeter = 0, isOperator = 0, validID = 0, isKeyWord = 0;





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

int checkIdentifier(char buffer)
{
    int flag = 0;
    if(!isdigit(buffer) )
    {

       flag = 1;
    }

    return flag;
}

int checkKeyword(char buffer[])
{
    int flag = 0, i;
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};

for(i = 0; i < 32; ++i) {
    if(strcmp(keywords[i], buffer) == 0) {
        flag  = 1;
        break;
    }
}
return flag;


}

//Returns true if the character is delimeter
void setBoolValues(char ch,char ch2[])
{
    if(isKeyWord){
        checkKeyword(ch2);
    }else
     {

    char delimeter [] ={';',':'};
    char operand [] = {'+', '-', '/', '*','='};
    char badIds [] = {'1', '2', '3', '4', '5', '6', '7', '8', '9','0'};




    if(checkChar(delimeter, ch)) {
         isDelimeter = 1;
    }
    if(checkChar(operand, ch) && !isDelimeter ) {
         isOperator = 1;
    }


    if(checkIdentifier(ch) && !isDelimeter && !isOperator)
       {
           validID = 1;
       }




     }

}
void resetBoolValues()
{
     isDelimeter=0; isOperator = 0; validID = 0; isKeyWord = 0;
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

    int keyword = checkKeyword(str);

    if(!keyword){
        for(int i = 0; i<codeLn; i++)
    {

        setBoolValues(str[i], str);

        printf("%d. %c Codes Results : \n IsDelimeter => %d \n IsOperator => %d \n Valid Identifier => %d \n \n",i,str[i],isDelimeter,isOperator,validID);

        resetBoolValues();


    }

    }else {
    printf("%s is a keyword",str);
    }









   return 0;
}
