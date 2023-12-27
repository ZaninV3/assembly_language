﻿// Занин Вячеслав ВМК-21
#include <iostream>  // Для ввода/вывода в консоль

// Здесь начало работы программы
int main() {
	/*
		Дано натуральные n и a1, a2, ... an.
		Определить количество последовательности ak
		имеющих нечётные порядковые номера и являющимися
		чётными числами.

		Например: [4, 3, 56, 32, 35] -> 2

		Вопрос с 0 возникать не должен,
		так как он по задаче нами может не предусматриваться.
	*/

	// Введем n
	unsigned short n;
	std::cout << "enter n: ";
	std::cin >> n;

	// Сделаем указатель на ячейку памяти для обращения к элементам
	unsigned short* input_massive = new unsigned short[n];

	// Поскольку нам нужно ввести значения массива
	// То здесь нам как кровь из носа нужен высокоуровневый for
	for (unsigned short i = 0; i < n; i++) {
		std::cout << "enter a" << i + 1 << ": ";
		std::cin >> input_massive[i];
	}
	// Сделаем переменную-счётчик
	unsigned short count;

	// ???
	// https://www.cyberforum.ru/cpp-beginners/thread2159053.html
	__asm {
		mov esi, arr
		add esi, 4
		mov ecx, n
		mov ebx, 2
		next_1:
			mov eax, [esi]
			imul ebx
			mov[esi], eax
			add esi, 8
		loop next_1
	}

	/*
	// Решим на C++

	// Проинициализируем 0;
	count = 0;

	// По условию нам дан n,
	// поэтому имеем право его использовать
	for (unsigned short i = 0; i < n; i++) {
		// В задании указано, что первый элемент имеет индекс 1
		if ((i + 1) % 2 != 0 and input_massive[i] % 2 == 0) count++;
	}
	*/
	// Ну а вот и вывод
	std::cout << "the count of values is " << count;
}
