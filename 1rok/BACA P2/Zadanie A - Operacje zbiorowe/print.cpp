//Anhelina Belavezha 
void MyPrint(int set, char* sequence, int bit) {
    if (((1 << 4) & bit) != 0) *(sequence + 0) = '1';
    else *(sequence + 0) = '0';

    if (((1 << 3) & bit) != 0) *(sequence + 1) = '1';
    else *(sequence + 1) = '0';

    if (((1 << 2) & bit) != 0) *(sequence + 2) = '1';
    else *(sequence + 2) = '0';

    if (((1 << 1) & bit) != 0) *(sequence + 3) = '1';
    else *(sequence + 3) = '0';

    if (((1 << 0) & bit) != 0) *(sequence + 4) = '1';
    else *(sequence + 4) = '0';

    *(sequence + 5) = ' ';
    *(sequence + 6) = '\0';}

void PrintBit(int set, char* sequence, int bit) {
   if (set == 0) {
        *(sequence + 0) = 'e';
        *(sequence + 1) = 'm';
        *(sequence + 2) = 'p';
        *(sequence + 3) = 't';
        *(sequence + 4) = 'y';
        *(sequence + 5) = '\0';}
    else {
        if (bit == 0) {
            if (((1 << bit) & set) != 0) {
                MyPrint(set, sequence, bit);
                return;}
         return;}
        else {
            if (((1 << bit) & set) != 0) {
                MyPrint(set, sequence, bit);
                return PrintBit(set, sequence + 6, --bit);}
            else return PrintBit(set, sequence, --bit);}}}

void Print(int set, char* sequence) {
    int bit = 31;
    PrintBit(set, sequence, bit);}
