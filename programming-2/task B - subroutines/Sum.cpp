// Anhelina Belavezha
#include <string>
#include <cstdarg>
using namespace std;

string SubInSum(int &i, int &sum, int &carry, string &result, string &number1, string &number2)
{
    if (i < number2.length())
    {
        sum = (number1[i] - '0') - (number2[i] - '0') - carry;
        if (sum < 0)
        {
            sum += 10;
            carry = 1;
        }
        else
            carry = 0;
        result += (sum + '0');
        i++;
        SubInSum(i, sum, carry, result, number1, number2);
    }
    else if (i >= number2.length() && i < number1.length())
    {
        sum = (number1[i] - '0') - carry;
        if (sum < 0)
        {
            sum += 10;
            carry = 1;
        }
        else
            carry = 0;
        result += (sum + '0');
        i++;
        SubInSum(i, sum, carry, result, number1, number2);
    }
    return result;
}

string ReverseInSum(int &i, string &result, string &numbers)
{
    if (i >= 0)
    {
        result += numbers[i];
        i--;
        ReverseInSum(i, result, numbers);
    }
    return result;
}

void ReverseInSum(string &numbers)
{
    string result = "";
    int i = numbers.length() - 1;
    numbers = ReverseInSum(i, result, numbers);
}

string SubInSum(string number1, string number2)
{
    string result = "";
    int i = 0;
    int sum = 0;
    int carry = 0;

    ReverseInSum(number1);
    ReverseInSum(number2);

    result = SubInSum(i, sum, carry, result, number1, number2);

    if (carry)
        result += carry + '0';

    ReverseInSum(result);
    return result;
}

bool CompareInSum(int &i, string &number1, string &number2)
{
    if (i < number1.length())
    {
        if (number1[i] > number2[i])
            return true;
        else if (number1[i] < number2[i])
            return false;
        i++;
        return CompareInSum(i, number1, number2);
    }
    return false;
}

bool CompareInSum(string &number1, string &number2)
{
    int i = 0;
    return CompareInSum(i, number1, number2);
}

string AddInSum(int &i, int &sum, int &carry, string &result, string &number1, string &number2)
{
    if (i < number1.length())
    {
        sum = (number1[i] - '0') + (number2[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
        i++;
        AddInSum(i, sum, carry, result, number1, number2);
    }
    else if (i >= number1.length() && i < number2.length())
    {
        sum = (number2[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
        i++;
        AddInSum(i, sum, carry, result, number1, number2);
    }
    return result;
}

string AddInSum(string number1, string number2)
{
    string result = "";
    int i = 0;
    int sum = 0;
    int carry = 0;

    if (number1.length() > number2.length())
    {
        string temp = number1;
        number1 = number2;
        number2 = temp;
    }

    ReverseInSum(number1);
    ReverseInSum(number2);

    result = AddInSum(i, sum, carry, result, number1, number2);

    if (carry)
        result += carry + '0';

    ReverseInSum(result);
    return result;
}

void DeleteZeroInSum(int &i, string &numbers)
{
    if (i < numbers.length() && numbers[i] == '0')
    {
        if (numbers[i] == '0' && numbers[i + 1] == '0')
        {
            numbers.erase(i, 2);
            i = -1;
        }
        if (numbers[i] == '0' && numbers[i + 1] != '0')
        {
            numbers = numbers.erase(i, 1);
            i = -1;
        }
        i++;
        DeleteZeroInSum(i, numbers);
    }
}

void DeleteZeroInSum(string &numbers)
{
    int i = 0;
    DeleteZeroInSum(i, numbers);
}

int StringToIntInSum(int &i, int &numbers, string &sequence)
{
    if (i < sequence.length())
    {
        numbers += sequence[i] - '0';
        i++;
        StringToIntInSum(i, numbers, sequence);
    }
    return numbers;
}

int StringToIntInSum(string sequence)
{
    int i = 0;
    int numbers = 0;
    return StringToIntInSum(i, numbers, sequence);
}

string AddSubInSum(string number1, string number2)
{
    string result = "";
    bool minus1 = false;
    bool minus2 = false;

    if (number1[0] == '-')
    {
        minus1 = true;
        number1.erase(0, 1);
    }

    if (number1[0] == '+')
        number1.erase(0, 1);

    if (number2[0] == '-')
    {
        minus2 = true;
        number2.erase(0, 1);
    }

    if (number2[0] == '+')
        number2.erase(0, 1);

    if (number1 == "0" && number2 == "0")
        return "0";

    if (number1 != "0" && StringToIntInSum(number1) != 0)
        DeleteZeroInSum(number1);
    if (number2 != "0" && StringToIntInSum(number2) != 0)
        DeleteZeroInSum(number2);

    if (number1 == "" && number2 == "")
        return "";
    else if (number1 == "" && number2 != "")
    {
        if (minus2)
            return "-" + number2;
        else
            return number2;
    }
    else if (number1 != "" && number2 == "")
    {
        if (minus1)
            return "-" + number1;
        else
            return number1;
    }

    if (!minus1 && !minus2)
        result = AddInSum(number1, number2);

    else if (minus1 && minus2)
    {
        result = AddInSum(number1, number2);
        if (result != "0")
            DeleteZeroInSum(result);
        result = '-' + result;
    }

    else if (minus1 && !minus2)
    {
        if (number1 == number2)
            result = "0";
        else
        {
            if (number1.length() > number2.length())
            {
                result = SubInSum(number1, number2);
                if (result != "0")
                {
                    DeleteZeroInSum(result);
                    result = '-' + result;
                }
            }
            else if (number1.length() < number2.length())
            {
                result = SubInSum(number2, number1);
                DeleteZeroInSum(result);
            }
            else
            {
                if (CompareInSum(number1, number2))
                {
                    result = SubInSum(number1, number2);
                    if (result != "0")
                    {
                        DeleteZeroInSum(result);
                        result = '-' + result;
                    }
                }
                else
                {
                    result = SubInSum(number2, number1);
                    DeleteZeroInSum(result);
                }
            }
        }
    }

    else if (!minus1 && minus2)
    {
        if (number1 == number2)
            result = "0";
        else
        {
            if (number1.length() > number2.length())
            {
                result = SubInSum(number1, number2);
                DeleteZeroInSum(result);
            }
            else if (number1.length() < number2.length())
            {
                result = SubInSum(number2, number1);
                if (result != "0")
                {
                    DeleteZeroInSum(result);
                    result = '-' + result;
                }
            }
            else
            {
                if (CompareInSum(number1, number2))
                {
                    result = SubInSum(number1, number2);
                    DeleteZeroInSum(result);
                }
                else
                {
                    result = SubInSum(number2, number1);
                    if (result != "0")
                    {
                        DeleteZeroInSum(result);
                        result = '-' + result;
                    }
                }
            }
        }
    }
    return result;
}

void Sum1(int &i, int &counter, string &result, const string *numbers)
{
    if (i < counter)
    {
        result = AddSubInSum(result, numbers[i]);
        i++;
        Sum1(i, counter, result, numbers);
    }
}

string Sum(int counter, const string *numbers)
{
    string result = "";
    int i = 0;

    Sum1(i, counter, result, numbers);

    return result;
}

void Sum2(int &i, int &counter, string &result, va_list numbers)
{
    if (i < counter)
    {
        result = AddSubInSum(result, va_arg(numbers, char *));
        i++;
        Sum2(i, counter, result, numbers);
    }
}

string Sum(int counter, ...)
{
    string result = "";
    int i = 0;

    va_list numbers;
    va_start(numbers, counter);
    Sum2(i, counter, result, numbers);
    va_end(numbers);

    return result;
}

void Sum(string *result, int counter, const string *numbers)
{
    *result = Sum(counter, numbers);
}

void Sum(string *result, int counter, ...)
{
    int i = 0;

    va_list numbers;
    va_start(numbers, counter);
    Sum2(i, counter, *result, numbers);
    va_end(numbers);
}

void Sum(string &result, int counter, const string *numbers)
{
    Sum(&result, counter, numbers);
}

void Sum(string &result, int counter, ...)
{
    result = "";
    int i = 0;

    va_list numbers;
    va_start(numbers, counter);
    Sum2(i, counter, result, numbers);
    va_end(numbers);
}