# Структури

"**C++ struct**, short for C++ Structure, is an **user-defined data type** available in C++".  
Фундаментални типове данни - int, double, bool, char,..  
Структурите в C++ са **съставен тип данни**. Използват се за групиране на елементи. Елементите могат да бъдат **от различен тип** и **с различна дължина**.  
Последното е точно това, което различава структурите от масивите. В масивите съхраняваме данни от **еднакъв тип**.

```c++
struct Person
{
	char firstName[32];
	char lastName[32];
	unsigned int age;
	char ucn[11]; // unified civilian number
};
```

### Деклариране и дефиниране на инстанции в стека
```c++
Person p; // default values are assigned

Person p2 = { "Ivan", "Dimitrov", 25, "9612120305" }; // firstName == Ivan, lastName == Dimitrov, age == 25, ucn == 9612120305

Person p3;
strcpy(p3.firstName, "Ivan");
strcpy(p3.lastName, "Dimitrov");
p3.age = 25;
strcpy(p3.ucn, "9612120305");
```

### Подаване на инстанции във функции
:heavy_exclamation_mark: Ако няма да променяме инстанцията, я подаваме по **константна референция.**
```c++
void printByTwoNames(const Person& p)
{
	std::cout << p.firstName << ' ' << p.lastName;
}
```
Можем и да я променяме.
```c++
void readPerson(Person& p)
{
	std::cin >> p.firstName >> p.lastName >> p.age >> p.ucn;
}
```
Можем да я подаваме по копие.
```c++
Person changeLastName(Person p, const char* newName)
{
	strcpy(p.lastName, newName);
	return p;
}
```

### Деклариране и дефиниране на инстанции в динамичната памет
```c++
Person* p1 = new Person({ "Ivan", "Dimitrov", 25, "9612120305" });

Person* p2 = new Person();
strcpy((*p2).firstName, "Ivan");
strcpy((*p2).lastName, "Dimitrov");
(*p2).age = 25;
strcpy((*p2).ucn, "9612120305");
```
Използваме "obj->data" вместо (*obj).data.
```c++
Person* p2 = new Person();
strcpy(p2->firstName, "Ivan");
strcpy(p2->lastName, "Dimitrov");
p2->age = 25;
strcpy(p2->ucn, "9612120305");
```
:heavy_exclamation_mark: Изтриваме динамичната памет.
```c++
delete p1;
delete p2;
```

### Влагане на инстанции
```c++
struct Person
{
	char firstName[32];
	char lastName[32];
	unsigned int age;
	char ucn[11]; // unified civilian number
};
struct Family
{
	Person mother;
	Person father;
	unsigned int numberOfChildren;
};

int main()
{
	Family f = { {"Tanya", "Georgieva", 33, "8901015437"}, {"Anton", "Georgiev", 34, "8802024573"}, 2 };
}
```

### Масиви от инстанции
```c++
Person arr1[22];

Person* arr2 = new Person[23];
delete[] arr2;
```

### Структури в паметта
Елементите на всяка структура "вървят в комплект". Те се записват последователно в паметта точно в реда, в който сме ги изредили в структурата.  

---

## Задача:
Въвежда се цяло число **N**, последвано от **N** тригъгълника в равнината, всеки от които се определя от 3 точки (6 координати). Отпечатайте лицата им в сортиран вид.  

