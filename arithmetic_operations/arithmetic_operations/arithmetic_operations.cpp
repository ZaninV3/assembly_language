﻿// Занин Вячеслав ВМК-21
#include <iostream>  // Для ввода и вывода в консоль

// Точка входа и выхода программы
int main() {
	// Объявим n и попросим пользователя ввести его
	unsigned short n;
	std::cout << "enter n: ";
	std::cin >> n;

	// А теперь объявим ненициализированную переменную,
	// в которой будет наш результат
	unsigned short last_number_of_n;

	// Вообще этот код работает корректно не только
	// со значениями [10; 99], но и [0; 65535]
	__asm {
		mov ax, n; Запишем введеное значение в ax
		mov dx, 0; На всякий случай обнулим dx(при выполнении div здесь будет остаток от деления)
		mov bx, 10; Запишем число, на которое будем делить
		div bx; dx = ax % bx
		mov last_number_of_n, dx; Выведем значение в переменную для вывода
	}

	// Вывод результата
	std::cout << "the last number of n is " << last_number_of_n;
}
