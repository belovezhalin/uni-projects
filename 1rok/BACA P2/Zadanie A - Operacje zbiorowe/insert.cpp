//Anhelina Belavezha 
void Conversion(char* sequence, int* set) {
    int value = (((*(sequence + 0) -'0') << 4) + ((*(sequence + 1) -'0') << 3) + ((*(sequence + 2) -'0') << 2) + ((*(sequence + 3) -'0') << 1) + ((*(sequence + 4) -'0') << 0));
    *set = *set | (1 << value);}

void Insert(char* sequence, int* set) {
    if (*sequence == '\0') return;
    else if (*sequence == ' ') Insert(sequence + 1, set);
    else {
        Conversion(sequence, set);
        Insert(sequence + 5, set);}}