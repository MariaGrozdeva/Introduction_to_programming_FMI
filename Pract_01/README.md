# Примитивни типове данни (built-in types)
|Тип  |Памет  |Стойности|
|--|--|--|
| char | 1 byte |-127 to 127 or 0 to 255|
| int | 4 bytes |-2147483648 to 2147483647|
| signed int | 4 bytes |same as int|
| unsigned int | 4 bytes |0 to 4294967295|
| short int | 2 bytes |-32768 to 32767|
| signed short int | 2 bytes |same as short int|
| unsigned short int | 2 bytes |0 to 65,535|
| float | 4 bytes ||
| double | 4 bytes ||
| bool | 1 byte ||

# Оператори
![alt text](https://i.ibb.co/zGQYpDK/Operator.png)

 1. ### Аритметични оператори - извършват математически операции
|Оператор|Описание|
|--|--|
|+|Събира две стойности|
|-|Изважда една стойност от друга|
|*|Умножава две стойности|
|/|Дели една стойност на друга|
|%|Връща остатъка при деление една стойност на друга|
|++|Инкрементира дадена стойност с единица|
|-\-|Декрементира дадена стойност с единица|

 2. ### Оператори за сравнение - извършват операции за сравнение на два или повече операнда
|Оператор|
|--|
| > (по - голямо) |
| < (по - малко) |
| >= (по - голямо или равно) |
| <= (по - малко или равно) |
| == (равенство) |
| != (различие) |

 3. ### Логически оператори - извършват булеви операции върху данните и връщат булев резултат  
|Оператор|  
|--|  
| && (логическо "И") |  
| \|\| (логическо "ИЛИ") |  
| ! (логическо отрицание) |  

|x  |y  | !x| x && y| x \|\| y|  
|--|--|--|--|--|  
| true | true  |false|true|true|  
| true | false |false|false|true|  
| false| true  |true|false|true|  
| false| false |true|false|false|  
 
 4. ### Оператори за присвояване – присвояват стойност на дадена променлива  
 |Оператор|Описание|  
|--|--|  
|=|Присвояване|  
|+=|Прибавяне и присвояване|  
|-=|Изваждане и присвояване|  
|*=|Умножение и присвояване|  
|/=|Деление и присвояване|  
|%=|Деление по модул и присвояване| 

## Оператор ++
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
	cout << e << endl; // e = 35;

	int f = 5;
	f += ++f; // Same as f = f + ++f <=> f = 6 + 6 <=> f = 12
	cout << f << endl; // f = 12
}
```
  
**ЗАДАЧА:**  
Въвежда се цяло число. Ако числото е *четно*, да се изведе **1** на стандартния изход. *В противен случай*, да се изведе **0**.    
*Вход: 265, Изход: 0  
Вход: 290, Изход: 1*  
