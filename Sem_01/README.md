# 1. Променливи

1. Декларация на променлива:
```c++
<dataType> <variableName>;
```
2. Дефиниция на променлива:
```c++
<variableName> = <value>;
```
3. Декларация + дефиниция на променлива:
```c++
<dataType> <variableName> = <value>;
```
![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_01/images/Variable.png)

---

# 2. Примитивни типове данни (built-in types)

1. Целочислени типове (**Integer types**)

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_01/images/DataTypes.png)

2. Числа с плаваща запетая (**Floating-point types**)
```c++
float - single precision floating-point type  
double - double precision floating-point type  
long double - extended precision floating-point type
```

3. Булев тип (**Boolean type**)
```c++
bool
```

4. Символни типове (**Character types**)
```c++
char
```

## Преобразуване между типове

Преобразуването може да се извърши:

 - **Без загуба** на информация.
```c++
	bool b = true;
	int a = b; // a == 1
```
```c++
	int a = 4; 
	double d = a; // d == 4.0 
```

 - **Със загуба** на информация.
```c++
	int a = 10;
	bool b = a; // b == 1 
```
```c++
	double PI = 3.14;
	int a = PI; // a == 3
```

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_01/images/Casting.png)

---

# 3. Оператори

![alt text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_01/images/Operators.png)

 ### 1. Аритметични оператори - извършват математически операции
|Оператор|Описание|
|--|--|
|+|Събира две стойности|
|-|Изважда една стойност от друга|
|*|Умножава две стойности|
|/|Дели една стойност на друга|
|%|Връща остатъка при деление една стойност на друга|
|++|Инкрементира дадена стойност с единица|
|-\-|Декрементира дадена стойност с единица|

#### :heavy_exclamation_mark: Оператор ++
```c++
int main() 
{
	// !! The prefix operator ++ increments the value of a variable and RETURNS THE VARIABLE (which is incremented). !!
	// !! The suffix operator ++ increments the value of a variable and RETURNS THE VARIABLE'S OLD VALUE. !!
	
	int a = 10;
	(++a) += 5;
	cout << a << endl; // a = 16

	int b = 10;
	// (b++) += 5; // ERROR! b++ returns 10 and the expression "10 += 5" is NOT valid (left operand must be lvalue)!
	cout << b << endl; 

	int c = 10;
	c = (c += 5) + (c += 8); 
	cout << c << endl; // c = 46

	int d = 23;
	// ++d++; // ERROR! The suffix operator ++ is with higher priority than the prefix one, so the expression is same as "++(d++)" = "++24" which is NOT valid! 
	cout << d << endl;

	int e = 33;
	(++e)++;
	cout << e << endl; // e = 35

	int f = 5;
	f += ++f; // f = 12
	cout << f << endl; // f = 12
}
```

 ### 2. Оператори за сравнение - извършват операции за сравнение на два или повече операнда
|Оператор|
|--|
| > (по - голямо) |
| < (по - малко) |
| >= (по - голямо или равно) |
| <= (по - малко или равно) |
| == (равенство) |
| != (различие) |

 ### 3. Логически оператори - извършват булеви операции върху данните и връщат булев резултат  
|Оператор|  
|--|  
| && (логическо "И") |  
| \|\| (логическо "ИЛИ") |  
| ! (логическо отрицание) |  

|x  |y  | !x| x && y| x \|\| y|  
|--|--|--|--|--|  
| false| false |true|false|false|  
| false| true  |true|false|true|  
| true | false |false|false|true|  
| true | true  |false|true|true|  
 
 ### 4. Оператори за присвояване – присвояват стойност на дадена променлива  
 |Оператор|Описание|  
|--|--|  
|=|Присвояване|  
|+=|Прибавяне и присвояване|  
|-=|Изваждане и присвояване|  
|*=|Умножение и присвояване|  
|/=|Деление и присвояване|  
|%=|Деление по модул и присвояване| 

Всеки оператор се характеризира с:
- **Приоритет**;
- **Асоциативност**;
- **Позиция на оператора спярмо аргумента** -  *префиксен*, *инфиксен*  и  *суфиксен (постфиксен)*.

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_01/images/OperatorCharacteristics.png)

---

## Задачи
:bangbang: Задачите се решават само чрез материал, учен до момента на семинар (без if/switch/while...).

**Задача 1:** Въвежа се цяло число. Да се отпечата **1**, ако числото е *валидна* оценка от училище, и **0**, ако *не е валидна*.  
*Вход: 3, Изход: 1  
Вход: 10, Изход: 0*  

**Задача 2:** Въвежда се цяло число. Ако числото е *четно*, да се изведе **1** на стандартния изход. *В противен случай*, да се изведе **0**.  
*Вход: 265, Изход: 0  
Вход: 290, Изход: 1*  

**Задача 3:** Въвеждат се две цели числа. Да се отпечата по-голямото от двете.  
*Вход: 265, 44, Изход: 265*  

**Задача 4:** Въвежда се цяло трицифрено число. Да се отпечата обърнатото число, събрано с единица.  
*Вход: 265, Изход: 563  
Вход: 289, Изход: 983*  

**Задача 5:** Въвежда се цяло число n - n лева. Да се изведе на конзолата как може сумата да се раздели по банкноти, така че да имаме минимален брой. В условието приемаме, че имаме и банкноти от 1 и 2 лева.  
*Вход: 193, Изход: 1x100, 1x50, 2x20, 0x5, 1x2, 1x1*  
