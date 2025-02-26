//Anhelina Belavezha 
#include <string>
#include <cstdarg>
using namespace std;

string ReverseInMult(int& i, string& result, string& numbers) {
    if(i >= 0) {
        result += numbers[i];
        i--;
        ReverseInMult(i, result, numbers);}
    return result;}

void ReverseInMult(string& numbers) {
    string result = "";
    int i = numbers.length() - 1;
    numbers = ReverseInMult(i, result, numbers);}

string AddInMult(int& i, int& sum, int& carry, string& result, string& number1, string& number2) {
    if (i < number1.length()) {
        sum = (number1[i] - '0') + (number2[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
        i++;
        AddInMult(i, sum, carry, result, number1, number2);}
    else if (i >= number1.length() && i < number2.length()) {
        sum = (number2[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
        i++;
        AddInMult(i, sum, carry, result, number1, number2);}
    return result;}

string AddInMult(string number1, string number2) {
    string result = "";
    int i = 0;
    int sum = 0;
    int carry = 0;

    if(number1.length() > number2.length()) {
        string temp = number1;
        number1 = number2;
        number2 = temp;}

    ReverseInMult(number1);
    ReverseInMult(number2);

    result = AddInMult(i, sum, carry, result, number1, number2);

    if(carry) result += carry + '0';
    
    ReverseInMult(result);
    return result;}

void AddZeroInMult(int& i, string& numbers, int& amount) {
    if(i < amount) {
        numbers += "0";
        i++;
        AddZeroInMult(i, numbers, amount);}}

void AddZeroInMult(string& numbers, int& amount) {
    int i = 0;
    AddZeroInMult(i, numbers, amount);}

string IntToStringInMult(int numbers) {
    string result = "";

    if(numbers/10 != 0) {
        result += (numbers / 10 + '0');
        result += (numbers % 10 + '0');}
    else result += (numbers + '0');

    return result;}

string Multiply2(int& i, int& j, int& amount, int& counter, string& numadd, string& result, string& number1, string& number2) {
    if(i >= 0) {
        numadd = IntToStringInMult((number1[i] - '0') * (number2[j] - '0'));
        AddZeroInMult(numadd, amount);
        result = AddInMult(result, numadd);
        i--;
        amount++;
        Multiply2(i, j, amount, counter, numadd, result, number1, number2);}
    amount = counter;
    return result;}

string Multiply1(int& i, int& j, int& amount, int& counter, string& numadd, string& result, string& number1, string& number2) {
    if(j >= 0) {
        Multiply2(i, j, amount, counter, numadd, result, number1, number2);
        i = number1.length() - 1;
        counter++;
        j--;
        Multiply1(i, j, amount, counter, numadd, result, number1, number2);}
    return result;}

string Multiply(string number1, string number2) {
    string result = "";
    int i = number1.length() - 1;
    int j = number2.length() - 1;
    int amount = 0;
    int counter = 1;
    string numadd = "";

    result = Multiply1(i, j, amount, counter, numadd, result, number1, number2);

    return result;}

void DeleteZeroInMult(int& i, string& numbers) {
    if(i < numbers.length() && numbers[i] == '0') {
        if(numbers[i] == '0' && numbers[i+1] == '0') {
            numbers.erase(i, 2);
            i = -1;}

        if(numbers[i] == '0' && numbers[i + 1] != '0') {
            numbers.erase(i, 1);
            i = -1;}
        i++;
        DeleteZeroInMult(i, numbers);}}

void DeleteZeroInMult(string& numbers) {
    int i = 0;
    DeleteZeroInMult(i, numbers);}

string MyMult(string number1, string number2) {
    string result = "";
    bool minus1 = false;
    bool minus2 = false;

    if(number1[0] == '-') {
        minus1 = true;
        number1.erase(0, 1);}

    if(number1[0] == '+') number1.erase(0, 1);

    if(number2[0] == '-') {
        minus2 = true;
        number2.erase(0, 1);} 

    if(number2[0] == '+') number2.erase(0, 1);

    if(number1 != "0") DeleteZeroInMult(number1);
    if(number2 != "0") DeleteZeroInMult(number2);

    if(number1 == "0" || number2 == "0" || number1 == "" || number2 == "") return "0";

    if(number1.length() < number2.length()) {
        string temp = number1;
        number1 = number2;
        number2 = temp;}

    if((minus1 && minus2) || (!minus1 && !minus2)) result = Multiply(number1, number2);
    else {
        result = Multiply(number1, number2);
        result = '-' + result;}

    return result;}

void Mult1(int& i, int& counter, string& result, const string* numbers ) {
    if(i < counter) {
        result = MyMult(result, numbers[i]);
        i++;
        Mult1(i, counter, result, numbers);}}

string Mult(int counter, const string* numbers) {
    string result = "1";
    int i = 0;

    Mult1(i, counter, result, numbers);

    return result;}

void Mult2(int& i, int& counter, string& result, va_list numbers) {
    if(i < counter) {
        result = MyMult(result, va_arg(numbers, char*)); 
        i++;
        Mult2(i, counter, result, numbers);}}

string Mult(int counter, ...) {
    string result = "1";
    int i = 0;

    va_list numbers;
    va_start(numbers, counter);
    Mult2(i, counter, result, numbers);
    va_end(numbers);

    return result;}


void Mult(string* result, int counter, const string* numbers) {
    *result = Mult(counter, numbers);}

void Mult(string* result, int counter, ...) {
    int i = 0;
    *result = "1";

    va_list numbers;
    va_start(numbers, counter);
    Mult2(i, counter, *result, numbers);
    va_end(numbers);}

void Mult(string& result, int counter, const string* numbers) {
    Mult(&result, counter, numbers);}

void Mult(string& result, int counter, ...) {
    int i = 0;
    result = "1";

    va_list numbers;
    va_start(numbers, counter);
    Mult2(i, counter, result, numbers);
    va_end(numbers);}
