//Anhelina Belavezha 
void Union(int set1, int set2, int* sum){
    *sum = (set1 | set2);}

void Intersection(int set1, int set2, int* intersection) {
    *intersection = (set1 & set2);}

void Symmetric(int set1, int set2, int* symmetric) {
    *symmetric = (set1 ^ set2);}

void Difference(int set1, int set2, int* difference) {
    *difference = (set1 & ~set2);}

void Complement(int set, int* complement) {
    *complement = (~set);}