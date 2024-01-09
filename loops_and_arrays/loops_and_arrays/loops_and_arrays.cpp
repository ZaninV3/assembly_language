// Занин Вячеслав ВМК-21
#define general_type unsigned int
#include <iostream>
using namespace std;

// Функция, внутри которой выполняется основная работа программы
general_type countEvenSequence(general_type n, general_type* arr) {
    // Инициализируем переменнную-счетчик
    general_type count = 0;

    /*
    // Решим на C++
    for (general_type i = 0; i < n; i++) {
        // В задании указано, что первый элемент имеет индекс 1
        if ((i + 1) % 2 != 0 and arr[i] % 2 == 0) count++;
    }
    */

    __asm {
        mov ecx, n           // Загрузка количества элементов
        mov ebx, 0           // Инициализация счетчика для второго цикла
        mov esi, arr         // Загрузка адреса массива
        mov eax, 0           // Обнуление регистра eax для подсчета количества четных чисел

        loop_start:
            add ebx, 1
            mov edx, [esi]      // Загрузка значения текущего элемента
            test edx, 1         // Проверка на четность текущего элемента
            jnz next_e          // Если нечетное, переходим к следующему элементу
            test edx, 1         // Проверка на четность текущего элемента
            jz increment        // Если четное, продолжаем проверку
        increment:
            mov edx, ebx        // Загружаем индекс массива
            test edx, 1         // Проверка на четность индекса
            jnz next_i          // Если нечетное, то 
            test edx, 1         // Проверка на четность индекса
            jz next_e           // Увеличиваем счетчик
        next_i:
            inc eax             // Увеличение счетчика
        next_e:
            add esi, 4          // Увеличение указателя на размер элемента (4 байта)
            loop loop_start     // Переход к следующему элементу

        mov count, eax      // Сохранение результата в переменную count
    }
    return count;
}

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

    // Вводим n
    general_type n;
    cout << "enter n: ";
    cin >> n;

    // Вводим значения массива
    general_type *arr = new general_type[n];
    for (general_type i = 0; i < n; i++) {
        cout << "enter a" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Подсчет и вывод результата
    cout << "the count of values is " << countEvenSequence(n, arr) << endl;

    delete[] arr;
}
