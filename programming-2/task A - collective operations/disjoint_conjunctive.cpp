// Anhelina Belavezha
bool Disjoint(int set1, int set2)
{
    if ((set1 && set2) == 0)
        return true;
    else
        return false;
}

bool Conjunctive(int set1, int set2)
{
    if ((set1 && set2) != 0)
        return true;
    else
        return false;
}
