// Занин Вячеслав ВМК-21
#define gen_type int  // Чтобы было проще менять тип у всех сразу
#include <iostream>  // Для ввода-вывода

// Функция с ассемблерной вставкой
gen_type getResult(gen_type x, gen_type y, gen_type z) {
	gen_type result = 0;
	
	__asm {
		mov eax, x
		add eax, y
		add eax, 2
		mov ebx, eax

		mov eax, x
		mul y
		mul z


		// Посчитали аргументы функции max,
		// где первый аргумент ebx, а второй eax
		cmp eax, ebx
		jg greater  // Если eax > ebx
		mov eax, ebx  // Иначе записываем в eax
		jmp end
		greater:  // После выполнения greater будет выполнен end
		end:
			mul eax
			add eax, 1
			mov result, eax
	}

	return result;
}

// Здесь начало программы
int main() {
	/*
		Даны целые числа x, y и z. Вычислить
		max^2(x + y + 2, x * y * z) + 1
	*/
	gen_type x;
	std::cout << "enter x: ";
	std::cin >> x;

	gen_type y;
	std::cout << "enter y: ";
	std::cin >> y;

	gen_type z;
	std::cout << "enter z: ";
	std::cin >> z;

	std::cout << "max^2(x + y + 2, x * y * z) + 1 = " << getResult(x, y, z) << std::endl;
}
