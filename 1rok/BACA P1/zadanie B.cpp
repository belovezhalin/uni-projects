//Anhelina Belavezha
#include <iostream>
using namespace std;
long s;
long x = 0;
long i;
long n; 
long indeks;
long fragment;
long dlugosc; 
long grupy;
long sgrupy;
long a;
long m;
long k;
long w;
char litera; 


int main() {
	
    cin >> s;
    
    while (s--) {
    	
	cin >> x;
    i = 0;
    long tab[x];
    while (i < x){cin >> tab[i]; i++;} 
    i = 0;
	while (i < x){cout << tab[i] << ' '; i++;} 
	
    
    cout << endl;
    
    cin >> litera;
    
    while (litera != 'F') {
    	
        if (litera == 'R') { 
		cin >> indeks >> dlugosc;
		
		if (dlugosc != 0) {
		indeks %= x;
		indeks += x;
		grupy = x / dlugosc;
		
		while (grupy--) {
		a = indeks;
		     while (a < indeks + (dlugosc/2))
		    {swap(tab[a%x], tab[ (indeks + dlugosc - 1 - (a - indeks) + x) % x ]);
		    a++;}
		
		indeks += dlugosc; 
	}
	}
	}
	
	    if (litera == 'C') { 
		cin >> indeks >> dlugosc;
		
		if (dlugosc != 0) {
		indeks %= x;
		indeks += x;
		grupy = x / (dlugosc * 2);
		
		while (grupy--) {
		a = indeks;
		     while (a < indeks + dlugosc)
		    {swap(tab[a%x], tab[ (dlugosc + a) % x ]);
		    a++;}
		
		indeks += dlugosc * 2; 
	}
	}
	}
	
	    if (litera == 'M') {
		cin >> indeks >> dlugosc >> k;
		
		if (dlugosc != 0) {
		indeks %= x;
		if (indeks < 0) {indeks += x;}
		grupy = x / dlugosc;
		
		while (grupy--) {
		m = k + dlugosc * 1000;
		m %= dlugosc;
		    while (m--) {
			a = indeks + dlugosc - 1;
			     while (a > indeks) {
			     	swap(tab[a%x], tab[(a - 1 + x) % x ]);
			     	a--;}
		}
		
		indeks += dlugosc;
	    }
	    
	    dlugosc = x % dlugosc;
	    if (dlugosc != 0) {
	    m = k + dlugosc * 1000;
		m %= dlugosc;
		    while (m--) {
			a = indeks + dlugosc - 1;
			     while (a > indeks) {
			     	swap(tab[a%x], tab[(a - 1 + x) % x ]);
			     	a--;}
		}
		
		indeks += dlugosc;
	}
	}
    }

        if (litera == 'S') {
		cin >> indeks >> dlugosc;
		
		if (dlugosc != 0) {
			w = 0;
			if (dlugosc < 0) { dlugosc = -dlugosc; w = 1;}
			
		indeks %= x;
		indeks += x;
		grupy = x / dlugosc;
		
		while (grupy--) {
		sgrupy = dlugosc;
		    while (sgrupy--) {
			a = indeks;
			     while (a < indeks + dlugosc - 1) {
			          if (w && tab[a%x] < tab[( a + 1 ) % x]) {swap(tab[a%x], tab[(a + 1) % x]);}
			          else if (!w && tab[a%x] > tab[( a + 1 ) % x]) {swap(tab[a%x], tab[(a + 1) % x]);}
			          a++;}	      
		    }
		
		indeks += dlugosc;
	    }
	    
	    if (dlugosc != 0) {
	    dlugosc = x % dlugosc;
	    sgrupy = dlugosc;
		    while (sgrupy--) {
			a = indeks;
			     while (a < indeks + dlugosc - 1) {
			         if (w && tab[a%x] < tab[( a + 1 ) % x]) {swap(tab[a%x], tab[(a + 1) % x]);}
			          else if (!w && tab[a%x] > tab[( a + 1 ) % x]) {swap(tab[a%x], tab[(a + 1) % x]);}
			          a++;}	     
		    }
		
		indeks += dlugosc;
	}
	}
    }
    
    cin >> litera;
			
}

    i = 0;
	while (i < x) {
	cout << tab[i] << ' ';
	i++;}
	
cout << endl;
}
}

