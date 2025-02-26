//Anhelina Belavezha 
#include <iostream> 
using namespace std;

int main() {
	int x,y,z,w;
	cin >> x;
	while (x>0) {
	cin >> y >> z >> w; 
	x--; 

	if ((z+w)<50 && (z+w)>0) cout << y << " " << z+w << "% " << "niedostateczny" << " (2.0)" << endl;
	if ((z+w)>=50 && (z+w)<60) cout << y << " " << z+w << "% " << "dostateczny" << " (3.0)" << endl;
	if ((z+w)>=60 && (z+w)<70) cout << y << " " << z+w << "% " << "dostateczny plus" << " (3.5)" << endl;
	if ((z+w)>=70 && (z+w)<80) cout << y << " " << z+w << "% " << "dobry" << " (4.0)" << endl;
	if ((z+w)>=80 && (z+w)<90) cout << y << " " << z+w << "% " << "dobry plus" << " (4.5)" << endl;
	if ((z+w)>=90 && (z+w)<=100) cout << y << " " << z+w << "% " << "bardzo dobry" << " (5.0)" << endl;
}

	return 0;
}
