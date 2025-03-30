// Anhelina Belavezha
#include <iostream>
using namespace std;

int main()
{
	int x;
	float y, w, z, r, q, S;

	cin >> x;
	while (x > 0)
	{
		cin >> y >> w >> z >> r >> q;
		x--;

		if (y == -0.0)
			y = 0.0;
		if (w == -0.0)
			w = 0.0;
		if (z == -0.0)
			z = 0.0;
		if (r == -0.0)
			r = 0.0;
		if (q == -0.0)
			q = 0.0;

		if ((y > w) && (z > w) && (r > w) && (q > w))
			cout << w << " ";
		else if ((w > y) && (z > y) && (r > y) && (q > y))
			cout << y << " ";
		else if ((y > z) && (w > z) && (r > z) && (q > z))
			cout << z << " ";
		else if ((y > r) && (w > r) && (z > r) && (q > r))
			cout << r << " ";
		else
			cout << q << " ";

		if ((y > w) && (y > z) && (y > r) && (y > q))
			cout << y << " ";
		else if ((w > y) && (w > z) && (w > r) && (w > q))
			cout << w << " ";
		else if ((z > y) && (z > w) && (z > r) && (z > q))
			cout << z << " ";
		else if ((r > y) && (r > w) && (r > z) && (r > q))
			cout << r << " ";
		else
			cout << q << " ";

		S = ((y + w + z + r + q)) / 5;
		cout << S << endl;
	}
	return 0;
}
