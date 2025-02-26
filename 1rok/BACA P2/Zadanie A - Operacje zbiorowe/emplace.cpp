//Anhelina Belavezha 
void EmplaceConversion(char* sequence, int* set) {
    int value = (((*(sequence + 0) -'0') << 4) + ((*(sequence + 1) -'0') << 3) + ((*(sequence + 2) -'0') << 2) + ((*(sequence + 3) -'0') << 1) + ((*(sequence + 4) -'0') << 0));
    *set = *set | (1 << value);}

void MyInsert(char* sequence, int* set) {
    if (*sequence == '\0') return;
    else if (*sequence == ' ') MyInsert(sequence + 1, set);
    else {
        EmplaceConversion(sequence, set);
        MyInsert(sequence + 5, set);}}

void Emplace(char* sequence, int* set) {
    *set = 0;
    MyInsert(sequence, set);}
