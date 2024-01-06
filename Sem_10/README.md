# Динамична памет
"In the programs seen in previous chapters, all memory needs were determined before program execution by defining the variables needed. But there may be cases where the memory needs of a program can only be determined during runtime. For example, when the memory needed depends on user input. On these cases, programs need to dynamically allocate memory (in heap), for which the C++ language integrates the operators `new` and `delete`."

### Оператори new и new[]
В C++ динамична памет се заделя чрез оператора **new**. След ключовата дума new се записва типа на данните, които ще съхраняваме в заделената памет. Ако искаме да заделим памет за повече от един елемент, използваме **new[]**, като в скобите посочваме броя на елементите.  
**Операторът new връща указател към началото на заделения блок динамична памет**. Синтаксисът е следният:    
```c++
type* ptr = new type
type* ptr = new type[elementsCount]
```

*Пример:*  
```c++
size_t n = 5;
int* foo = new int[n];
```
![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_10/images/Foo.png)  

### Оператори delete и delete[]
**Паметта, заделена в стека, се освобождава автоматично**. *Например*, при деклариране на локална променлива във функция се заделя памет за нея, при приключване на функцията – паметта се освобождава. **При динамичната памет ние трябва да се грижим за нейното освобождаване** – когато вече не ни е нужна, трябва да я "декларираме" като свободна, за да може да бъде използвана от други. Това се постига чрез оператора **delete**.
```c++
delete ptr;
delete[] ptr;
```

**delete ptr** освобождава паметта (която сме заделили с new) на един елемент. **delete[] ptr** освобождава паметта, която сме заделили (с оператора new[]) за множество последователни елементи, т.е. масив.

:bangbang::bangbang::bangbang: **За всяко new задължително delete** :bangbang::bangbang::bangbang:

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_10/images/StackVsHeap.png)  

![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_10/images/First.png)  
![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_10/images/Second.png)  
![alt_text](https://github.com/MariaGrozdeva/Introduction_to_programming_FMI/blob/main/Sem_10/images/Third.png)  

---

## Задачи
**Задача 1:** Да се напише функция *insertAt(index, element)*, която  
добавя елемент на дадена позиция в динамичен масив. ***Масивът да се преоразмери с точна големина!***  
```c++ 
8 12 92 32 4,
insertAt(4, 123);
8 12 92 32 123 4
```

**Задача 2:** Да се напише функция *removeAt(index)*, която  
премахва елемент от дадена позиция в динамичен масив. ***Масивът да се преоразмери с точна големина!***  
```c++ 
8 12 92 32 4,
removeAt(1);
8 92 32 4
```

**Задача 3:** Да се напише функция, която приема низ и връща нов низ, в който са премахнати всички цифри от първия. ***Новият низ да бъде с точна дължина!***  
*Вход: "i1v2an345cho", Изход: "ivancho"*  

**Задача 4:** Да се напише функция, която приема низ и връща два нови низа uppercaseStr и lowercaseStr такива че:  
uppercaseStr съдържа *само главните букви* от подадения низ,  
lowercaseStr съдържа *само малките букви* от подадения низ.  
Останалите символи се игнорират. ***uppercaseStr и lowercaseStr да бъдат с точна дължина!***  
*Вход: "I am the best Player"  
Изход: "IP" &nbsp;&nbsp;&nbsp; "amthebestlayer"*  

**Задача 5:** Да се напише функция, която филтрира всички прости числа от зададен динамичен масив. ***Масивът да се преоразмери с точна големина!***  
*Вход: [3 5 8 7 11 24 42], Изход: [3 5 7 11]*  

**Задача 6:** Да се напише функция, която обединява два сортирани динамични масива, като резултатният масив остава сортиран. ***Последният да е с точна големина!***  
*Вход: [1 3 5 10 21] &nbsp;&nbsp; [2 7 12 32], Изход: [1 2 3 5 7 10 12 21 32]*  

**Задача 7:** Да се напише функция, която приема низ и "патърн" и връща нов низ, в който всяко число е цензурирано с подадения "патърн". ***Резултатният низ да е с точна дължина!***  
*Вход: "test124again4pocket55p" &nbsp;&nbsp;&nbsp; "_NUM_",  
Изход: "test_NUM_again_NUM_pocket_NUM_p"*  

**Задача 8:** Да се напише функция, която приема текст с произволна дължина. Всяко срещане на цифра да се замени с нейното наименувание. ***Масивът да се преоразмери с точна големина!***  
*Вход: "Hello 9 today is 54 very0 good day."  
Изход: "Hello nine today is fivefour veryzero good day."*  

**Задача 9:** Да се напише функция, която приема низ и връща нов низ, в който всяко число е увеличено с единица. ***Резултатният низ да е с точна дължина!***  
*Вход: "It's 2022 and I am 19 years old."  
Изход: "It's 2023 and I am 20 years old."*  

*Вход: "After 99 comes 100."  
Изход: "After 100 comes 101."*
