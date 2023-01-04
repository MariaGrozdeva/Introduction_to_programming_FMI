#include <iostream>
using namespace std;


bool isDigit(char ch){
    return (ch >= '0' && ch <= '9');
}

int strLen(char str[]){
    int i = 0;
    while(*str != '\0'){
        i++;
        str++;
    }
    return i;
}

int estimateSize(char src[]){
    int i = 0;
    int srcLen = strLen(src);
    for (size_t j = 0; j < srcLen; j++)
    {
        if(isDigit(src[j]))
            i++;
    }
    return srcLen + i * 5;
}

void print(char str[]){
    while (*str != '\0')
    {
        cout << *str;
        str++;
    }
    cout << endl;
}

// returns index of '/0'
int hide(char str[], int index){
    char mask[] = "_NUM_";

    int maskLen = 5;
    for (size_t i = 0; i < maskLen; i++)
    {
        str[index + i] = mask[i];
    }
    
    return index + maskLen;
}

void censor(char str[]){
    bool lastDigit = false;
    int len = strLen(str);
    int censoredTextLen = estimateSize(str);
    char *censoredText = new char[censoredTextLen];
    int index = 0;
    while (*str != '\0')
    {
        if(isDigit(*str)){
           if(!lastDigit){
                index = hide(censoredText, index);
                lastDigit = true;
           }
        } else{
            censoredText[index++] = *str;
            lastDigit = false;
        }
        
        str++;
    }
    censoredText[index] = '\0';
    print(censoredText);
    delete censoredText;
}

int main(){
    cout << "Enter string: ";
    char text[1024];
    cin.getline(text, 1024);
    //char text[] = "test124again4pocket55p";
    censor(text);
}