/*
В этой программе показанно как с помощью шаблонов и некоторых проверок, можно заставить методы класса обрабатывать разные массивы данных

This program shows how using templates and some checks, you can force class methods to process different data arrays.
*/

#include<iostream>
#include<string>
using namespace std;
/*
//#define ForInt  отработает  	Arr<char, int> , Arr<string, int> will work
  #define ForInt  отработает  	Arr<int, int>  will work
*/

#define ForInt 

template<typename T3, typename T4>
class Arr
{
public:

	Arr()
	{
		T4 size = 0;
		T3 array = nullptr;
	}
	Arr(T3 *arr, T4 &size) :size(size)   // :size(size) для передачи значения , до начала инициализации массива. to pass the value, before the initialization of the array
	{
		//this->size = size;  // в этом случае значение сайз передастся после создания массива	T3 *Narray = new T3[size];	
		for (int i = 0; i < size; i++)
		{
			Narray[i] = arr[i];
		}
	}

	void view()						 // отображения массива объекта
	{
		char ch;
		if (typeid(check).name() == typeid (ch).name())// проверка на тип char	//char type check
		{
			for (int i = 0; i < size; i++)
			{
				cout << Narray[i];//
			}
			cout << endl;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << i << "# " << Narray[i] << "\t";//
			}
			cout << endl;
		}
	}

	void arraAddElement(T3 value)	//функция добавления элемента в массив объекта
	{
		T3 * Tarr = new T3[size + 1]; // размер на 1 больше для добавления элемента . one size larger for adding item
		for (int i = 0; i < (size + 1); i++)
		{
			if (i < size)
				Tarr[i] = Narray[i];
			else
				Tarr[i] = value;
		}

		delete[]Narray;					//освобождение память от старых данных
		Narray = new T3[++size];		//Для того же указателя просим выделить память с достаточным размером.
										//For the same pointer, please allocate memory with sufficient size.
		for (int i = 0; i < size; i++)
		{
			Narray[i] = Tarr[i];
		}

		delete[]Tarr;
		Tarr = nullptr;
	}
	~Arr()
	{
		delete[]Narray;
		Narray = nullptr;
	}

private:
	int size;

	T3 *Narray = new T3[size];
	T3 check;// для провеерки на тип char
};

template<>	//template<typename T3, typename T4>	переопределение шаблона. template override.
class Arr<string, int>
{
private:
	string arr;
	int size;
public:
	Arr(string arr, int size)// Конструктор с тем же названием что и в родительском шаблонном классе. Constructor with the same name as the parent template class
	{
		this->arr = arr;
		this->size = size;
	}

	void view() { cout << arr << endl; }
};


#ifdef ForInt
int  main()

{

	int size = 5;
	int *array = new int [size] { 1, 4, 5, 6, 7 };

	Arr<int, int> obj(array, size);  //передача динамического масива чисел как шаблон инт, и размера инт

	obj.view();

	obj.arraAddElement(66);

	obj.view();

	delete[]array;
	array = nullptr;
}
#else
int  main()

{

	char array[] = { "hello world!!!" };
	int size = strlen(array);
	string str = "Happy new Year!";
	int count = str.length();

	Arr<char, int> obj(array, size);
	Arr<string, int> objj(str, count);

	obj.view();

	obj.arraAddElement('?');

	obj.view();
	objj.view();
}
#endif // ForInt

