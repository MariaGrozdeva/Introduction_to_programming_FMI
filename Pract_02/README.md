![alt text](https://i.ibb.co/H4CWhHx/Operators-precedence.png)

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
### Задачи
**Задача(Grades):** Да се напише програма, която при подадено число, отговарящо на оценка, *изписва оценката с думи*.  

**Задача(PointInCircle):** Да се напише програма, която при подадена двумерна точка **(х, у)** и радиус **r** проверява *дали точката се намира вътре/извън или по контура на окръжност* с център **(0,0)**.  
*Вход: 1 3 6, Изход: "In the circle"  
Вход: 3 4 5, Изход: "On the circle"  
Вход: 4 4 5, Изход: "Out of the circle"*  
