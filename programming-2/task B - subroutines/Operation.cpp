// Anhelina Belavezha
#include <string>
#include <cstdarg>
using namespace std;

string Operation(string (*x)(int, const string *), int counter, const string *numbers)
{
    return x(counter, numbers);
}

void ArrayArg(int &i, int &counter, string *array, va_list &numbers)
{
    if (i < counter)
    {
        array[i] = va_arg(numbers, char *);
        i++;
        ArrayArg(i, counter, array, numbers);
    }
}

string Operation(string (*x)(int, const string *), int counter, ...)
{
    string array[counter];
    int i = 0;

    va_list numbers;
    va_start(numbers, counter);
    ArrayArg(i, counter, array, numbers);
    va_end(numbers);

    return Operation(x, counter, array);
}

void Operation(string *result, string (*x)(int, const string *), int counter, ...)
{
    string array[counter];
    int i = 0;

    va_list numbers;
    va_start(numbers, counter);
    ArrayArg(i, counter, array, numbers);
    va_end(numbers);

    *result = Operation(x, counter, array);
}

void Operation(string *result, string (*x)(int, const string *), int counter, const string *numbers)
{
    *result = x(counter, numbers);
}

void Operation(string &result, void (*x)(string *, int, const string *), int counter, const string *numbers)
{
    x(&result, counter, numbers);
}

void Operation(string &result, void (*x)(string *, int, const string *), int counter, ...)
{
    string array[counter];
    int i = 0;

    va_list numbers;
    va_start(numbers, counter);
    ArrayArg(i, counter, array, numbers);
    va_end(numbers);

    x(&result, counter, array);
}