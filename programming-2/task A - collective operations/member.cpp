// Anhelina Belavezha
bool MyMember(char *sequence, int set, int bit)
{
    if (*(sequence + bit) != '\0')
    {
        if (*(sequence + bit) != ' ')
        {
            int i = 1;
            if (*(sequence + bit) == '1')
                i <<= 16;
            bit++;

            if (*(sequence + bit) == '1')
                i <<= 8;
            bit++;

            if (*(sequence + bit) == '1')
                i <<= 4;
            bit++;

            if (*(sequence + bit) == '1')
                i <<= 2;
            bit++;

            if (*(sequence + bit) == '1')
                i <<= 1;

            return (i & set);
        }
        bit++;
        MyMember(sequence, set, bit);
    }
}

bool Member(char *sequence, int set)
{
    int bit = 0;
    MyMember(sequence, set, bit);
}
