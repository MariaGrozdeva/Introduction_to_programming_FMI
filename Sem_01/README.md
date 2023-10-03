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
![alt_text](https://i.ibb.co/LQRmXb2/Decl-And-Init-Of-Var.png)

---

# 2. Примитивни типове данни (built-in types)

1. Целочислени типове (**Integer types**)

![alt_text](https://i.ibb.co/QJGC8dN/Int.png)

3. Числа с плаваща запетая (**Floating-point types**)
```c++
float - single precision floating-point type;  
double - double precision floating-point type;  
long double - extended precision floating-point type.
```

4. Булев тип (**Boolean type**)
```c++
bool
```

5. Символни типове (**Character types**)
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

![alt_text](https://i.ibb.co/6r30mB4/Conversion.png)

---

# 3. Оператори

![alt text](https://i.ibb.co/zGQYpDK/Operator.png)

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

 ### 2. Оператори за сравнение - извършват операции за сравнение на два или повече операнда
|Оператор|
|--|
| > (по - голямо) |
| < (по - малко) |
| >= (по - голямо или равно) |
| <= (по - малко или равно) |
| == (равенство) |
| != (различие) |
