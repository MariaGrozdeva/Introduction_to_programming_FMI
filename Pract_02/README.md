![alt text](https://i.ibb.co/H4CWhHx/Operators-precedence.png)

### if - else
```c++
if(<condition>)  
{  
	// изпълнява се, ако условието е истина.  
}  
else // незадължително  
{
	// изпълнява се, ако условието е лъжа.  
}  
```

### if - else if - else
```c++
if(<condition1>)  
{  
	// изпълнява се, ако <condition1> е истина.   
}  
else if(<condition2>)  
{  
	// изпълнява се, ако <condition1> е лъжа и <condition2> е истина.  
}  
.
.
.
else if(<conditionK>)  
{  
	// изпълнява се, ако <condition1>..<conditionK-1> са лъжа и <conditionК> е истина.  
}  
else // незадължително  
{  
	// изпълнява се, ако всички горни условия са лъжа.  
}  
```
	
### switch  
```c++  
switch(<целочислена променлива>)  
{
	case value1: code.. break;  
	case value2: code.. break;  
	case value3: code.. break;  

	default: code.. break; // незадължително  
}
```
### Ternary operator
```c++ 
<условие> ? <израз1> : <израз2>
```

### Задачи
**Задача(Grades):** Да се напише програма, която при подадено число, отговарящо на оценка, *изписва оценката с думи*.  

**Задача(PointInCircle):** Да се напише програма, която при подадена двумерна точка **(х, у)** и радиус **r** проверява *дали точката се намира вътре/извън или по контура на окръжност* с център **(0,0)**.  
*Вход: 1 3 6, Изход: "In the circle"  
Вход: 3 4 5, Изход: "On the circle"  
Вход: 4 4 5, Изход: "Out of the circle"*  
