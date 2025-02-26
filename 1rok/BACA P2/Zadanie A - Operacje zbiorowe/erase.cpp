//Anhelina Belavezha 
void MyErase(char* sequence, int* set) {
    int value = (((*(sequence + 0) -'0') << 4) + ((*(sequence + 1) -'0') << 3) + ((*(sequence + 2) -'0') << 2) + ((*(sequence + 3) -'0') << 1) + ((*(sequence + 4) -'0') << 0));
    *set = (*set & ~(1 << value));}

void Erase(char* sequence, int* set) {
    if (*sequence == '\0') return;
    else if (*sequence == ' ') Erase(sequence + 1, set);
    else {
        MyErase(sequence, set);
        Erase(sequence + 5, set);}} 
