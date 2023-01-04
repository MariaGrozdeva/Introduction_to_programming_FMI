#include <iostream>
using namespace std;

int strLen(char arr[]){
    int i = 0;
    while(*arr != '\0'){
        i++;
        arr++;
    }
    return i;
}
int strLen(char arr[][6]){
    int k = 0;
    for (size_t i = 0; i < 9; i++)
    {
        k += strLen(arr[i]);
    }
    return k;
}

//append two strings and return the index of '\0'
int append(char src[], char dest[]){
    int srcLen = strLen(src);
    int destNullTerminatorIndex = strLen(dest); 
    for (size_t i = 0; i < srcLen; i++)
    {
        dest[destNullTerminatorIndex + i] = src[i];
    }
    int lastIndex = srcLen + destNullTerminatorIndex;
    dest[lastIndex] = '\0';
    return lastIndex; 
}

void print(char src[]){
    while(*src != '\0'){
        cout << *src;
        src++;
    }
    cout << endl;
}

int main(){
    cout << "Enter string: ";
    char str[1024];
    cin.getline(str, 1024);
    //char str[] = "Hello 9 today is 54 very0 good day.";

    char digits[][6] = {"zero", "one", "two", "tree", "four", "five", "six", "seven", "eight", "nine"};
    int strLenght = strLen(str);
    int spelledDigitsLenght = strLen(digits);
    char *result = new char [strLenght + spelledDigitsLenght];

    int j = 0;
    for (size_t i = 0; i < strLenght; i++)
    {
        switch (str[i])
        {
        case '0':
            j = append(digits[0], result);
            break;
        case '1':
            j = append(digits[1], result);
            break;
        case '2':
            j = append(digits[2], result);
            break;
        case '3':
            j = append(digits[3], result);
            break;
        case '4':
            j = append(digits[4], result);
            break;
        case '5':
            j = append(digits[5], result);
            break;
        case '6':
            j = append(digits[6], result);
            break;
        case '7':
            j = append(digits[7], result);
            break;
        case '8':
            j = append(digits[8], result);
            break;
        case '9':
            j = append(digits[9], result);
            break;
        default:
            result[j++] = str[i];
            result[j] = '\0';
            break;
        }
    }
    print(result);

    delete[] result;
}
