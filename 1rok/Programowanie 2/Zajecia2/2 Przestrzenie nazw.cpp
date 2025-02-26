#include <iostream>


namespace mojaPrzestrzenNazw {
	int a = 1;
	double cout = 9.; 
	
	/*
	namespace zagnie�d�onaPrzestrzenNazw {
		int aa = 7;
	}
	*/
}

//using namespace std;
using namespace mojaPrzestrzenNazw;


int main()
{
	//cout << a;

	std::cout << mojaPrzestrzenNazw::a << std::endl;

	std::cout << mojaPrzestrzenNazw::cout << std::endl;

	//std::cout << mojaPrzestrzenNazw::zagnie�d�onaPrzestrzenNazw::aa;
	

	//std::cout << a;

	std::cin.ignore();
	return 0;
}
