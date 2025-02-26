#include <iostream> //Anhelina Belavezha 
using namespace std; 

int main() {
	int x, y, z;
	cin >> x; 
	cin >> y; 	
	while (y>0){
		cin >> z;
		if (x%z==0) { 
		cout << "TAK"<<endl;
		}
		else { cout << "NIE"<<endl;
		}
		y=y-1;
	}
	return 0;
}

