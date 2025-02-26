//Anhelina Belavezha 
#include <iostream>
using namespace std;

bool Empty(int array[]) {
	int n = 0;
	
	while (n <= 4095) {
		if (array[n] == -1) {
			return array[0] == -1;
			break;}
	n++;}
}

bool Nonempty(int array[]) {
	int n = 0;
	
	while (n <= 4095) {
		if (array[n] != -1) {
			return array[0] != -1;
			break;}
	n++;}
}

void Cardinality(int array[], int *moc) {
	*moc = 0;
	
	for (int n = 0; n <= 4095; n++) {
		if (array[n] != -1) {*moc += 1;}
		else break;
	}
}

bool Element(int liczba, int array[]) {
	int n = 0;
	
	Cardinality(array, &n);
	
	for (int i = 0; i < n; i++) {
		if (array[i] == liczba) {return true;}
	}
return false;
}

bool Equal(int array1[], int array2[]) {
	int n, m;
	
	Cardinality(array1, &n);
	Cardinality(array2, &m);
	
    if (n != m) {return false;}
	
	for (int i = 0; array1[i] != -1 ; i++) {
		for (int j = 0; array2[j] != -1; j++) {
	        if (array1[i] == array2[j]) {break;}
	        else {if (array2[ j + 1] == -1) {return false;}}
	    }
    }
return true;
}

void Add (int liczba, int array[]) {
	int n = 0;
	int q = 0;
	
	if ((liczba > 0) && (liczba <= 4095)) {
	while (array[n] != -1) {
		if (array[n] == liczba) { q = 1;}
		n++;}
	
	if (!q) {
		array[n] = liczba;
		array[n + 1] = -1;
		while (n && array[n] < array[n - 1]) {
			swap(array[n], array[n - 1]);
			n--;}
	}}
}

double Arithmetic(int array[]) {
	double suma = 0, asr = 0;
	int n = 0;
	 
	if (array[0] == -1) {return asr = 0.0;}
	
	int i = 0;
	while( i == n) {
		        if (array[n] != -1) {
				suma += array[n];
				n++;}
	i++;}
return asr = suma / n;
}	

double Harmonic(int array[]) {
	double suma = 0, har = 0;
	int n = 0;
	 
	if (array[0] == -1) {return har = 1.0;}
	if (array[n] == 0) {return false;}
	
	int i = 0;
	while( i == n) {
		        if (array[n] != -1 && array[n] != 0) {
				suma += 1.0/array[n];
				n++;}
	i++;}
	
return har = n / suma;
}

void Create(int liczba, int array1[], int array2[]) {
	int n = 0;
	
	for (int i = 0; i < liczba; i++) {
		if ((array1[i] >= 1) && (array1[i] <= 4095)) {
			int q = 1;
			for (int j = 0; j < n; j++) {if (array1[i] == array2[j]) {q = 0;}}
		    if (q) {array2[n] = array1[i]; n++;}
		}
    }
    
	array2[n] = -1;
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (array2[j] > array2[j + 1]) {
				swap(array2[j], array2[j + 1]);}
		}
	}
}

void MinMax(int array[], int *min, int &max) {
	int n;
	
	Cardinality (array, &n);
	
	if (n > 0) { *min = array[0]; max = array[0];
	   for (int i = 0; i < n; i++) {
	   	  if (array[i] < *min) *min = array[i];
	   	  if (array[i] > max) max = array[i];
	   }
	}
}
	
void Union (int array1[], int array2[], int array[]) {
	int i = 0, j = 0, t = 0;
	
	while ((array1[i] != -1) && (array2[j] != -1)) {
		if (array1[i] > array2[j]) {array[t] = array2[j]; t++; j++;}
		else if (array1[i] < array2[j]) {array[t] = array1[i]; t++; i++;}
		else {array[t] = array1[i]; t++; i++;; j++;}}
	while (array1[i] != -1) {array[t] = array1[i]; i++; t++;}
	while (array2[j] != -1) {array[t] = array2[j]; j++; t++; }
	array[t] = -1;
}

void Intersection (int array1[], int array2[], int array[]) {
	int i = 0, j = 0, t = 0;
	
	while ((array1[i] != -1) && (array2[j] != -1)) {
		if (array1[i] > array2[j]) {j++;}
		else if (array1[i] < array2[j]) {i++;}
		else {array[t] = array1[i]; t++; i++; j++;}}
	array[t] = -1;
}

void Difference (int array1[], int array2[], int array[]) {
	int i = 0, j = 0, t = 0;
	
	while ((array1[i] != -1) && (array2[j] != -1)) {
		if (array1[i] > array2[j]) {j++;}
		else if (array1[i] < array2[j]) {array[t] = array1[i]; t++; i++;}
		else {i++; j++;}}
	while (array1[i] != -1) {array[t] = array1[i]; t++; i++;}
	array[t] = -1;
}

void Symmetric (int array1[], int array2[], int array[]) {
	int i = 0, j = 0, t = 0;
	
	while ((array1[i] != -1) && (array2[j] != -1)) {
		if (array1[i] > array2[j]) {array[t] = array2[j]; t++; j++;}
		else if (array1[i] < array2[j]) {array[t] = array1[i]; t++; i++;}
		else {i++;; j++;}}
	while (array1[i] != -1) {array[t] = array1[i]; i++; t++;}
	while (array2[j] != -1) {array[t] = array2[j]; j++; t++; }
	array[t] = -1;
}

void Complement (int array1[], int array2[]) {
	int n = 0;
	
	for (int i = 1; i <= 4095; i++) {
		int q = 1;
        for (int j = 0; array1[j] != -1; j++) {
        	if (array1[j] == i) q = 0;}
		if (q) {array2[n] = i; n++;}
	}
array2[n] = -1;
}

void Properties (int array[], char ciag[], double &arithmetic, double *harmonic, int &min, int *max, int &moc) {
	for (int i = 0; ciag[i] != 0; i++) {
		if (ciag[i] == 'a') arithmetic = Arithmetic(array);
		if (ciag[i] == 'h') *harmonic = Harmonic(array); 
		if (ciag[i] == 'm') MinMax(array, &min, *max);
		if (ciag[i] == 'c') Cardinality(array, &moc);
	}
}

bool Subset(int array1[], int array2[]) {
	int n, m;
	
	Cardinality(array1, &n);
	Cardinality(array2, &m);
	
	if (n > m) return false;
	
	for (int i = 0; array1[i] != -1; i++) {
		for (int j = 0; array2[j] != -1; j++) {
			if (array1[i] == array2[j]) break;
			else {if (array2[j + 1] == -1) return false;} 
		}
	}
return true;
}

   




		
	
	
		

		
	
	
	







