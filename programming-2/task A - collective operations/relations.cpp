// Anhelina Belavezha
int MyCardinalityRelations(int set, int bit, int number)
{
    if (bit == 0)
        return number;
    else
    {
        if ((set & 1) == 1)
        {
            number++;
            bit--;
            MyCardinalityRelations(set >> 1, bit, number);
        }
        else
        {
            bit--;
            MyCardinalityRelations(set >> 1, bit, number);
        }
    }
}

int MyCardinality(int set)
{
    if (set == 0)
        return 0;
    else
    {
        int number = 0;
        int bit = 32;
        return MyCardinalityRelations(set, bit, number);
    }
}

bool LessThen(int set1, int set2)
{
    if (MyCardinality(set1) == MyCardinality(set2))
        return (set1 < set2);
    else
        return (MyCardinality(set1) < MyCardinality(set2));
}

bool LessEqual(int set1, int set2)
{
    if (MyCardinality(set1) == MyCardinality(set2))
        return (set1 <= set2);
    else
        return (MyCardinality(set1) <= MyCardinality(set2));
}

bool GreatEqual(int set1, int set2)
{
    if (MyCardinality(set1) == MyCardinality(set2))
        return (set1 >= set2);
    else
        return (MyCardinality(set1) >= MyCardinality(set2));
}

bool GreatThen(int set1, int set2)
{
    if (MyCardinality(set1) == MyCardinality(set2))
        return (set1 > set2);
    else
        return (MyCardinality(set1) > MyCardinality(set2));
}