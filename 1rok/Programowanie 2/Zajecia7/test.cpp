#include <iostream>
using namespace std;

class Rocket
{
private:
    int payload;
    static string manufacturer;

public:
    Rocket(int _payload)
    {
        payload = _payload;
        // manufacturer = _manufacturer;
    }

    void setManufacturer(string _manufacturer)
    {
        manufacturer = _manufacturer;
    }

    static void staticSetManufacturer(string _manufacturer)
    {
        manufacturer = _manufacturer;
    }

    Rocket(Rocket &rocket)
    {
        payload = rocket.payload;
    }

    // friend int load(Rocket &rocket, int object);
};

// int load(Rocket &rocket, int object)
// {
//     rocket.payload -= object;
// }

string Rocket::manufacturer = "SpaceX";

int main()
{
    Rocket starship(100000);
    Rocket starship2(200000);
    Rocket starship3(300000);
    Rocket starship4(400000);

    // starship4.setManufacturer("BlueOrigin");

    Rocket::staticSetManufacturer("BlueOrigin");

    // load(starship, 100);

    return 0;
}