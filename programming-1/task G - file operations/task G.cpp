// Anhelina Belavezha
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Lines
{
    string a1, a2, a3, a4, a5, a6, a7;
};

struct Str
{
    int liczba;
    string tekst;
    char letter;
    bool l1, l2, l3, l4;
    short s1, s2, s3, s4;
    float d1, d2, d3, d4;
};

Str tworzenie2(string file1, int numerlin)
{
    fstream f1;
    f1.open(file1.c_str(), fstream::in | fstream::out);
    string temp;
    for (int i = 0; i < numerlin; i++)
    {
        getline(f1, temp);
    }
    Str str;
    f1 >> str.liczba;
    getline(f1, str.tekst);
    getline(f1, str.tekst);
    str.letter = f1.get();
    f1 >> str.l1 >> str.s1 >> str.d1 >> str.l2 >> str.s2 >> str.d2 >> str.l3 >> str.s3 >> str.d3 >> str.l4 >> str.s4 >> str.d4;
    f1.close();
    return str;
}

int obliczanie(string file1)
{
    fstream f1;
    string line;
    int n = 0;
    f1.open(file1.c_str(), fstream::in);
    while (getline(f1, line))
    {
        n++;
    }
    f1.close();
    return n / 7;
}

void kopia(string file1, string file2)
{
    fstream f1;
    fstream f2;
    string line;
    f1.open(file1.c_str(), fstream::in);
    f2.open(file2.c_str(), fstream::out);
    while (getline(f1, line))
    {
        f2 << line << endl;
    }
    f1.close();
    f2.close();
}

void app1(string file2, Str str)
{
    fstream f2;
    f2.open(file2.c_str(), fstream::app | fstream::out);
    f2 << str.liczba << endl
       << str.tekst << endl
       << str.letter << endl
       << str.l1 << ' ' << str.s1 << ' ' << str.d1 << endl
       << str.l2 << ' ' << str.s2 << ' ' << str.d2 << endl
       << str.l3 << ' ' << str.s3 << ' ' << str.d3 << endl
       << str.l4 << ' ' << str.s4 << ' ' << str.d4 << endl;
    f2.close();
}

void SortInt(string file1, string file2, string file3)
{
    int n;
    n = obliczanie(file1);

    if (n != 0)
    {
        kopia(file1, file2);
        for (int i = 0; i < n - 1; i++)
        {
            if (i % 2 == 0)
            {
                fstream f4;
                f4.open(file3.c_str(), fstream::out);
                f4.close();
                Str str1, str2, temp;
                int stan = 0;
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (!stan)
                    {
                        str1 = tworzenie2(file2, j * 7);
                    }
                    else
                    {
                        stan = 0;
                    }

                    str2 = tworzenie2(file2, j * 7 + 7);
                    if (str1.liczba > str2.liczba)
                    {
                        app1(file3, str2);
                        stan = 1;
                    }
                    else
                    {
                        app1(file3, str1);
                    }
                }

                if (!stan)
                {
                    app1(file3, str2);
                }
                else
                {
                    app1(file3, str1);
                }

                for (int j = i; j > 0; j--)
                {
                    temp = tworzenie2(file2, n * 7 - j * 7);
                    app1(file3, temp);
                }
            }
            else
            {
                fstream f4;
                f4.open(file2.c_str(), fstream::out);
                f4.close();
                Str str1, str2, temp;
                int stan = 0;
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (!stan)
                    {
                        str1 = tworzenie2(file3, j * 7);
                    }
                    else
                    {
                        stan = 0;
                    }

                    str2 = tworzenie2(file3, j * 7 + 7);
                    if (str1.liczba > str2.liczba)
                    {
                        app1(file2, str2);
                        stan = 1;
                    }
                    else
                    {
                        app1(file2, str1);
                    }
                }

                if (!stan)
                {
                    app1(file2, str2);
                }
                else
                {
                    app1(file2, str1);
                }

                for (int j = i; j > 0; j--)
                {
                    temp = tworzenie2(file3, n * 7 - j * 7);
                    app1(file2, temp);
                }
            }
        }

        if (n % 2 == 0)
        {
            kopia(file3, file1);
        }
        else
        {
            kopia(file2, file1);
        }
    }
}

void SortCount(string file1, string file2, string file3) {};

Lines tworzenie1(string file1, int numerlin)
{
    fstream f1;
    f1.open(file1.c_str(), fstream::in | fstream::out);
    string temp;
    for (int i = 0; i < numerlin; i++)
    {
        getline(f1, temp);
    }
    Lines lin;
    getline(f1, lin.a1);
    getline(f1, lin.a2);
    getline(f1, lin.a3);
    getline(f1, lin.a4);
    getline(f1, lin.a5);
    getline(f1, lin.a6);
    getline(f1, lin.a7);
    f1.close();
    return lin;
}

bool rown(Lines lin1, Lines lin2)
{
    return (lin1.a1 == lin2.a1 && lin1.a2 == lin2.a2 && lin1.a3 == lin2.a3 && lin1.a4 == lin2.a4 && lin1.a5 == lin2.a5 && lin1.a6 == lin2.a6 && lin1.a7 == lin2.a7);
}

void app2(string file2, Lines lin)
{
    fstream f2;
    f2.open(file2.c_str(), fstream::app | fstream::out);
    f2 << lin.a1 << endl
       << lin.a2 << endl
       << lin.a3 << endl
       << lin.a4 << endl
       << lin.a5 << endl
       << lin.a6 << endl
       << lin.a7 << endl;
    f2.close();
}

void usun(string file2, string file3, int numerlin)
{
    kopia(file2, file3);
    fstream f2;
    fstream f3;
    f3.open(file3.c_str(), fstream::in);
    f2.open(file2.c_str(), fstream::out);
    string line;
    for (int i = 0; i < numerlin; i++)
    {
        getline(f3, line);
        f2 << line << endl;
    }

    for (int i = 0; i < 7; i++)
    {
        getline(f3, line);
    }

    while (getline(f3, line))
    {
        f2 << line << endl;
    }
    f2.close();
    f3.close();
}

void SymmetricDifference(string file1, string file2, string file3)
{
    int q = obliczanie(file1);
    int w = obliczanie(file2);

    if (q == 0)
    {
        kopia(file2, file1);
        fstream f4;
        f4.open(file2.c_str(), fstream::out);
        f4.close();
    }

    for (int i = 0; i < w; i++)
    {
        Lines str1, str2;
        str1 = tworzenie1(file2, i * 7);

        for (int j = 0; j < q; j++)
        {
            str2 = tworzenie1(file1, j * 7);

            if (rown(str1, str2))
            {
                j = q;
            }
            else if (j == q - 1 && !rown(str1, str2))
            {
                app2(file1, str1);
                usun(file2, file3, i * 7);
                w--;
                i--;
                q++;
            }
        }
    }
};

void SortString(string file1, string file2, string file3)
{
    int n;
    n = obliczanie(file1);
    if (n != 0)
    {
        kopia(file1, file2);
        for (int i = 0; i < n - 1; i++)
        {
            if (i % 2 == 0)
            {
                fstream f4;
                f4.open(file3.c_str(), fstream::out);
                f4.close();
                Str str1, str2, temp;
                int stan = 0;
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (!stan)
                    {
                        str1 = tworzenie2(file2, j * 7);
                    }
                    else
                    {
                        stan = 0;
                    }

                    str2 = tworzenie2(file2, j * 7 + 7);
                    if (str1.tekst > str2.tekst)
                    {
                        app1(file3, str2);
                        stan = 1;
                    }
                    else
                    {
                        app1(file3, str1);
                    }
                }

                if (!stan)
                {
                    app1(file3, str2);
                }
                else
                {
                    app1(file3, str1);
                }

                for (int j = i; j > 0; j--)
                {
                    temp = tworzenie2(file2, n * 7 - j * 7);
                    app1(file3, temp);
                }
            }
            else
            {
                fstream f4;
                f4.open(file2.c_str(), fstream::out);
                f4.close();
                Str str1, str2, temp;
                int stan = 0;
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (!stan)
                    {
                        str1 = tworzenie2(file3, j * 7);
                    }
                    else
                    {
                        stan = 0;
                    }

                    str2 = tworzenie2(file3, j * 7 + 7);
                    if (str1.tekst > str2.tekst)
                    {
                        app1(file2, str2);
                        stan = 1;
                    }
                    else
                    {
                        app1(file2, str1);
                    }
                }
                if (!stan)
                {
                    app1(file2, str2);
                }
                else
                {
                    app1(file2, str1);
                }

                for (int j = i; j > 0; j--)
                {
                    temp = tworzenie2(file3, n * 7 - j * 7);
                    app1(file2, temp);
                }
            }
        }

        if (n % 2 == 0)
        {
            kopia(file3, file1);
        }
        else
        {
            kopia(file2, file1);
        }
    }
};
