# Указатели и референции

**Указател** - променлива, която съдържа адреса на друга променлива.  

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_07/images/Pointer.png)

1. Оператор **&**:
- приема променлива от тип Т;
- връща указател от тип T*
 
```c++
 int number = 10;
 int* ptr = &number;
 cout << ptr; // 0019F798
``` 

2. Оператор **\*** (дерефериране):
- приема указaтел от тип Т*;
- връща променлива от тип Т

```c++
 int number = 10;
 int* ptr = &number;
 int dereferencedPtr = *ptr; 
 cout << dereferencedPtr; // 10
```

---

### Разлика между указател и референция?

- Референцията *задължително* се инициализира при създаването;
- Указателят има неутрална стойност (nullptr), референцията – няма;
- Указателят може да се "пренасочва" – да приема нови стойности;
- Може да се направи масив от указатели, но не и масив от референции.

```c++
// References vs Pointers

#include <iostream>
using namespace std;
 
int main() 
{
   int number1 = 88, number2 = 22;
 
   // Create a pointer pointing to number1
   int* pNumber1 = &number1;    // Explicit referencing
   *pNumber1 = 99;              // Explicit dereferencing
   cout << *pNumber1 << endl;   // 99
   cout << &number1 << endl;    // 0x22ff18
   cout << pNumber1 << endl;    // 0x22ff18 (content of the pointer variable - same as above)
   cout << &pNumber1 << endl;   // 0x22ff10 (address of the pointer variable)
   pNumber1 = &number2;         // Pointer can be reassigned to store another address
 
   // Create a reference (alias) to number1
   int& refNumber1 = number1;   // Implicit referencing (NOT &number1)
   refNumber1 = 11;             // Implicit dereferencing (NOT *refNumber1)
   cout << refNumber1 << endl;  // 11
   cout << &number1 << endl;    // 0x22ff18
   cout << &refNumber1 << endl; // 0x22ff18
   //refNumber1 = &number2;     // Error! Reference cannot be re-assigned
   refNumber1 = number2;        // refNumber1 is still an alias to number1. Assign value of number2 (22) to refNumber1 (and number1).
   number2++;
   cout << refNumber1 << endl;  // 22
   cout << number1 << endl;     // 22
   cout << number2 << endl;     // 23
}
```

---

### Указателна аритметика :heavy_exclamation_mark:

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_07/images/PointerArithmetic.png)

### Примери
- Достъпване на елемента на k-ти индекс в масив **без оператор []**;
- Линейно търсене в масив **единствено чрез указателна аритметика**

---

# Многомерни масиви

## Инициализация на многомерни масиви
```c++
int matrix1[3][4]; // създава се матрица с 3 реда и 4 колони
int matrix2[3][4] = { { 1, 2, 3, 4 }, { 9, 8, 7, 6 }, { 11, 12, 13, 14 } }; // изреждаме редовете
int matrix3[3][4] = { 1, 2, 3, 4, 9, 8, 7, 6, 11, 12, 13, 14 }; // изреждаме елементите
int matrix4[][4] = { 1, 2, 3, 4, 9, 8, 7, 6, 11, 12, 13, 14 }; // можем да изпуснем най-лявата спецификация на дължина
 
int cube[3][3][3]; // създава се тримерен масив
```
### Как изглежда многомерен масив в паметта?

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_07/images/Matrix.png)

### Указателна аритметика върху двумерни масиви
```c++
cout << matrix1 << endl; // адресът на елемента на нулев индекс от matrix1 (масивът [1, 2, 3, 4])
cout << *matrix1 << endl; // адресът на първия елемент на първия елемент от matrix1 (1-цата от масива [1, 2, 3, 4])
cout << matrix1 + 2 << endl; // адресът на елемента на втори индекс от matrix1 (масивът [11, 12, 13, 14])
cout << (*(*matrix1 + 3)) << endl; // елементът на трети индекс от първия масив (4)
cout << (**(matrix1 + 1) + 3); // елементът на нулев индекс от втория масив, събран с 3 (12)
```

---

## Задачи
**Задача 0:** Реализирайте играта **_"Морски шах" (Tic-tac-toe)_**.  Реализирайте програмата така, че да може смяната на големината на полето да става чрез промяна стойността на една константа.  

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_07/images/TicTacToe.jpeg)

**Задача 1:** Напишете функция, която приема матрица NxN и транспонира матрицата.  

**Задача 2:** Напишете функция, която приема матрица NxN и проверява дали релацията, която представлява матрицата, е релация на еквивалентност.  

**Задача 3:** Напишете функция, която приема матрица NxM и матрица MxK и умножава първата матрица по втората.  

**Задача 4:** Напишете функция, която приема матрица NxN и връща обратната матрица (ако дадената е обратима). Ако матрицата не е обратима, да се отпечата подходящо съобщение.  

**Задача 5:** Напишете функция, която приема матрица NxN+1 и решава системата от линейни уравнения, репрезентирана в нея.  

*Вход:*
| | | | |
|--|--|--|--|
| -3 | 2 | -5 | 0 |
| 2 | -3 | 4 | 10 |
| 2 | 1 | 1 | 4 |

*Изход: &nbsp; 14, &nbsp;-11.1429 (-78/7), &nbsp;-12.8571 (-90/7)*  

Тук се решава системата:  
-3x + 2y - 5z = 0  
&nbsp;2x - 3y + 4z = 10  
&nbsp;2x + &nbsp;y + &nbsp;z = 4  

:heavy_exclamation_mark: Програмата трябва да засича, ако системата няма решение или има безкраен брой решения и да отпечатва подходящо съобщение.
