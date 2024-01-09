// Занин Вячеслав ВМК-21
#include <iostream>  // Для ввода/вывода с консоли

void firstProgram() {
	short result;
	__asm {
		xor ah, ah  // Нужно почистить регистр, 
		mov al, 0xAB  // иначе тут не будет 171
		mov result, ax  // а если бы это был unsigned char и al, то цифры не будет
	}

	std::cout << "first program: " << result << std::endl;
}

void secondProgram() {
	short first;
	std::cout << "enter for ah: ";
	std::cin >> first;

	short second;
	std::cout << "enter for bx: ";
	std::cin >> second;

	short third;
	std::cout << "enter for edx: ";
	std::cin >> third;

	__asm {

	}
}

// Основное тело программы
int main() {
	/*
	1) Поместить регистр AL непосредственное значение 0xAB.
		Вывести значение на экран, используя высокоуровневую переменную.

	2) Поместить регистры AH, BX, EDX значения высокоуровневых переменных,
		заданные в консоли. Вывести на экран эти значения,
		используя другие высокоуровневые переменные.

	3) Загрузить в регистр ECX значение 16-разрядной высокоуровневой переменной.
		Затем вывести это значение на экран,
		используя 32-разрядную высокоуровневую переменную.
	*/
	firstProgram();
	secondProgram();
}