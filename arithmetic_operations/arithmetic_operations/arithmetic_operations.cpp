// Занин Вячеслав ВМК-21
#include <iostream>  // Для ввода и вывода в консоль

// Точка входа и выхода программы
int main() {
	// Объявим n и попросим пользователя ввести его
	unsigned short n;
	std::cout << "enter n: ";
	std::cin >> n;

	// А теперь объявим ненициализированную переменную,
	// в которой будет наш результат
	 unsigned int last_number_of_n;

	// Выбрал в качестве регистров общего использования 
	// 16 bit так как число 99 в двоичной занимает 15 bit,
	// а по условию задачи 10 <= n <= 99.
	// Поэтому n выбран unsigned short (беззнаковый 2 Byte)
	__asm {
		movzx eax, n
		mov last_number_of_n, eax
	}
	std::cout << "the last number of n is " << last_number_of_n;
}

/* шпаргалка 
* mov ПРИЕМНИК, ИСТОЧНИК
* Записывает в ПРИЕМНИК значение из ИСТОЧНИК
* 
* movzx работает как mov, но позволяет записывать в регистр значение
* меньшее, чем сам регистр
* Пример: mov eax, bx
* 
* mul ebx выполняет eax = eax * ebx
* 
* add СУММА, СЛАГАЕМОЕ выполняет СУММА = СУММА + СЛАГАЕМОЕ
* 
* https://btpit36.ru/pluginfile.php/629/mod_resource/content/2/%D0%9E%D1%81%D0%BD%D0%BE%D0%B2%D1%8B%20%D0%B0%D1%81%D1%81%D0%B5%D0%BC%D0%B1%D0%BB%D0%B5%D1%80%D0%B0%20FASM.pdf
*/
