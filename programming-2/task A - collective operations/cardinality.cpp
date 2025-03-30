// Anhelina Belavezha
int MyCardinality(int set, int bit, int number)
{
    if (bit == 0)
        return number;
    else
    {
        if ((set & 1) == 1)
        {
            number++;
            bit--;
            MyCardinality(set >> 1, bit, number);
        }
        else
        {
            bit--;
            MyCardinality(set >> 1, bit, number);
        }
    }
}

int Cardinality(int set)
{
    if (set == 0)
        return 0;
    else
    {
        int number = 0;
        int bit = 32;
        return MyCardinality(set, bit, number);
    }
}