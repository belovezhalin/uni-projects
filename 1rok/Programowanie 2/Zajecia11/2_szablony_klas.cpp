#include <iostream>
using namespace std;

template <class T> // This is a template class, the user will provide the data type for T
class Array
{
private:
    int m_length;
    T *m_data;

public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }

    Array(int length)
    {
        m_data = new T[length];
        m_length = length;
    }

    ~Array()
    {
        delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    T &operator[](int index)
    {
        // assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // The length of the array is always an integer
    // It does not depend on the data type of the array
    int getLength(); // templated getLength() function defined below
};

template <typename T> // member functions defined outside the class need their own template declaration
int Array<T>::getLength()
{
    cout << "ogolna" << endl;
    return m_length;
} // note class name is Array<T>, not Array

template <>
int Array<int>::getLength()
{
    cout << "DLA INTA";
    return m_length;
} // note class name is Array<T>, not Array

int main()
{
    Array<double> doubleArray(12);
    Array<string> stringArray(12);
    Array<int> intArray(12);

    stringArray.getLength();
    doubleArray.getLength();
    intArray.getLength();
    /*
       for (int count = 0; count < intArray.getLength(); ++count)
       {
           intArray[count] = count;
           doubleArray[count] = count + 0.5;
       }

       for (int count = intArray.getLength()-1; count >= 0; --count)
           std::cout << intArray[count] << "\t" << doubleArray[count] << '\n';
    */
    return 0;
}
