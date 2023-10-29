#include <iostream>

template <int n>
class Fibonacci
{
public:
    static constexpr int value = Fibonacci<n - 1>::value + Fibonacci<n - 2>::value;
};

template<>
class Fibonacci<1>
{
public:
    static constexpr int value = 1;
};

template<>
class Fibonacci<0>
{
public:
    static constexpr int value = 0;
};

template<int n>
constexpr int fibonacci()
{
    if constexpr (n == 1)
        return 1;
    else if constexpr (n == 0)
        return 0;
    else
        return fibonacci<n-1>() + fibonacci<n-2>();
}

int main()
{
    int Fibon1 = fibonacci<1>();
    int Fibon2 = Fibonacci<1>::value;
    std::cout << "fibonacci 4 = " << Fibon1 << std::endl;
    std::cout << "fibonacci::value 4 = " << Fibon2 << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
