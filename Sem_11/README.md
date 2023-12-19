# Динамична памет - втора част

### Динамично заделени двумерни масиви
1. Създаване
```c++
int** dynamicMatrix = new int*[rowsCount];
for (size_t i = 0; i < rowsCount; i++)
{
    dynamicMatrix[i] = new int[colsCount];
}
```
При rowsCount = 4 и colsCount = 5, резултатът ще е следният:

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_11/images/DynamicMatrix.png)

2.	 Изтриване
```c++
for (size_t i = 0; i < rowsCount; i++)
{
    delete[] dynamicMatrix[i];
}
delete[] dynamicMatrix;
```

---

## Задачи

**Задача 1:** Напишете функция, която приема матрица NxN+1 и решава системата от линейни уравнения, репрезентирана в нея. Приемете, че всички коефициенти са ненулеви.  

***Пример:***  
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

**Задача 2:** Въвежда се текст с дължина до 2048 символа. Думите в текста са разделени с интервали. Напишете следните функции:  
1. Функция, която променя дума по индекс;
2. Функция, която цензурира дума (със \*) и разцензурира вече цензурирана дума по индекс.  

На всяка операция да се отпечатва текста в текущия му вид.  

***Пример:***  
```c++
> Hello my friends how are you

> censore
> 2
Hello my * how are you

> censore
> 3
Hello my * * are you

> uncensore
> 2
Hello my friends * are you

> uncensore
> 3
Hello my friends how are you

> change
> 2
> enemies
Hello my enemies how are you
```
