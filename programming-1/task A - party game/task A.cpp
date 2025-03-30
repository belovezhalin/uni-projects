// Anhelina Belavezha
#include <iostream>
using namespace std;

int x, S1, S2;
char g1, g2, W1, W2;
const char a = 'a', b = 'b', c = 'c', d = 'd', J = 'J', S = 'S', K = 'K', P = 'P', N = 'N';
char w, p, r;
float wyga, wygb, wygc, wygd, prza, przb, przc, przd, rema, remb, remc, remd;

int main()
{

	cin >> x;
	while (x > 0)
	{
		cin >> g1 >> W1 >> S1 >> g2 >> W2 >> S2;

		if (W1 == J && W2 == J)
		{
			if (S1 > S2)
			{
				if (g1 == a)
				{
					wyga++;
				}
				else if (g1 == b)
				{
					wygb++;
				}
				else if (g1 == c)
				{
					wygc++;
				}
				else if (g1 == d)
				{
					wygd++;
				}

				if (g2 == a)
				{
					prza++;
				}
				else if (g2 == b)
				{
					przb++;
				}
				else if (g2 == c)
				{
					przc++;
				}
				else if (g2 == d)
				{
					przd++;
				}
			}

			else if (S1 < S2)
			{
				if (g2 == a)
				{
					wyga++;
				}
				else if (g2 == b)
				{
					wygb++;
				}
				else if (g2 == c)
				{
					wygc++;
				}
				else if (g2 == d)
				{
					wygd++;
				}

				if (g1 == a)
				{
					prza++;
				}
				else if (g1 == b)
				{
					przb++;
				}
				else if (g1 == c)
				{
					przc++;
				}
				else if (g1 == d)
				{
					przd++;
				}
			}

			else if (S1 == S2)
			{
				if (g2 == a)
				{
					rema++;
				}
				else if (g2 == b)
				{
					remb++;
				}
				else if (g2 == c)
				{
					remc++;
				}
				else if (g2 == d)
				{
					remd++;
				}

				if (g1 == a)
				{
					rema++;
				}
				else if (g1 == b)
				{
					remb++;
				}
				else if (g1 == c)
				{
					remc++;
				}
				else if (g1 == d)
				{
					remd++;
				}
			}
		}

		else if (W1 == J && W2 == P)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == P && W2 == J)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == J && W2 == S)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == S && W2 == J)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == K && W2 == K)
		{
			if (S1 > S2)
			{
				if (g1 == a)
				{
					wyga++;
				}
				else if (g1 == b)
				{
					wygb++;
				}
				else if (g1 == c)
				{
					wygc++;
				}
				else if (g1 == d)
				{
					wygd++;
				}

				if (g2 == a)
				{
					prza++;
				}
				else if (g2 == b)
				{
					przb++;
				}
				else if (g2 == c)
				{
					przc++;
				}
				else if (g2 == d)
				{
					przd++;
				}
			}

			else if (S1 < S2)
			{
				if (g2 == a)
				{
					wyga++;
				}
				else if (g2 == b)
				{
					wygb++;
				}
				else if (g2 == c)
				{
					wygc++;
				}
				else if (g2 == d)
				{
					wygd++;
				}

				if (g1 == a)
				{
					prza++;
				}
				else if (g1 == b)
				{
					przb++;
				}
				else if (g1 == c)
				{
					przc++;
				}
				else if (g1 == d)
				{
					przd++;
				}
			}

			else if (S1 == S2)
			{
				if (g2 == a)
				{
					rema++;
				}
				else if (g2 == b)
				{
					remb++;
				}
				else if (g2 == c)
				{
					remc++;
				}
				else if (g2 == d)
				{
					remd++;
				}

				if (g1 == a)
				{
					rema++;
				}
				else if (g1 == b)
				{
					remb++;
				}
				else if (g1 == c)
				{
					remc++;
				}
				else if (g1 == d)
				{
					remd++;
				}
			}
		}

		else if (W1 == K && W2 == J)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == J && W2 == K)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == K && W2 == N)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == N && W2 == K)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == N && W2 == N)
		{
			if (S1 > S2)
			{
				if (g1 == a)
				{
					wyga++;
				}
				else if (g1 == b)
				{
					wygb++;
				}
				else if (g1 == c)
				{
					wygc++;
				}
				else if (g1 == d)
				{
					wygd++;
				}

				if (g2 == a)
				{
					prza++;
				}
				else if (g2 == b)
				{
					przb++;
				}
				else if (g2 == c)
				{
					przc++;
				}
				else if (g2 == d)
				{
					przd++;
				}
			}

			else if (S1 < S2)
			{
				if (g2 == a)
				{
					wyga++;
				}
				else if (g2 == b)
				{
					wygb++;
				}
				else if (g2 == c)
				{
					wygc++;
				}
				else if (g2 == d)
				{
					wygd++;
				}

				if (g1 == a)
				{
					prza++;
				}
				else if (g1 == b)
				{
					przb++;
				}
				else if (g1 == c)
				{
					przc++;
				}
				else if (g1 == d)
				{
					przd++;
				}
			}

			else if (S1 == S2)
			{
				if (g2 == a)
				{
					rema++;
				}
				else if (g2 == b)
				{
					remb++;
				}
				else if (g2 == c)
				{
					remc++;
				}
				else if (g2 == d)
				{
					remd++;
				}

				if (g1 == a)
				{
					rema++;
				}
				else if (g1 == b)
				{
					remb++;
				}
				else if (g1 == c)
				{
					remc++;
				}
				else if (g1 == d)
				{
					remd++;
				}
			}
		}

		else if (W1 == N && W2 == J)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == J && W2 == N)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == N && W2 == P)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == P && W2 == N)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == P && W2 == P)
		{
			if (S1 > S2)
			{
				if (g1 == a)
				{
					wyga++;
				}
				else if (g1 == b)
				{
					wygb++;
				}
				else if (g1 == c)
				{
					wygc++;
				}
				else if (g1 == d)
				{
					wygd++;
				}

				if (g2 == a)
				{
					prza++;
				}
				else if (g2 == b)
				{
					przb++;
				}
				else if (g2 == c)
				{
					przc++;
				}
				else if (g2 == d)
				{
					przd++;
				}
			}

			else if (S1 < S2)
			{
				if (g2 == a)
				{
					wyga++;
				}
				else if (g2 == b)
				{
					wygb++;
				}
				else if (g2 == c)
				{
					wygc++;
				}
				else if (g2 == d)
				{
					wygd++;
				}

				if (g1 == a)
				{
					prza++;
				}
				else if (g1 == b)
				{
					przb++;
				}
				else if (g1 == c)
				{
					przc++;
				}
				else if (g1 == d)
				{
					przd++;
				}
			}

			else if (S1 == S2)
			{
				if (g2 == a)
				{
					rema++;
				}
				else if (g2 == b)
				{
					remb++;
				}
				else if (g2 == c)
				{
					remc++;
				}
				else if (g2 == d)
				{
					remd++;
				}

				if (g1 == a)
				{
					rema++;
				}
				else if (g1 == b)
				{
					remb++;
				}
				else if (g1 == c)
				{
					remc++;
				}
				else if (g1 == d)
				{
					remd++;
				}
			}
		}

		else if (W1 == P && W2 == K)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == K && W2 == P)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == P && W2 == S)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == S && W2 == P)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == S && W2 == S)
		{
			if (S1 > S2)
			{
				if (g1 == a)
				{
					wyga++;
				}
				else if (g1 == b)
				{
					wygb++;
				}
				else if (g1 == c)
				{
					wygc++;
				}
				else if (g1 == d)
				{
					wygd++;
				}

				if (g2 == a)
				{
					prza++;
				}
				else if (g2 == b)
				{
					przb++;
				}
				else if (g2 == c)
				{
					przc++;
				}
				else if (g2 == d)
				{
					przd++;
				}
			}

			else if (S1 < S2)
			{
				if (g2 == a)
				{
					wyga++;
				}
				else if (g2 == b)
				{
					wygb++;
				}
				else if (g2 == c)
				{
					wygc++;
				}
				else if (g2 == d)
				{
					wygd++;
				}

				if (g1 == a)
				{
					prza++;
				}
				else if (g1 == b)
				{
					przb++;
				}
				else if (g1 == c)
				{
					przc++;
				}
				else if (g1 == d)
				{
					przd++;
				}
			}

			else if (S1 == S2)
			{
				if (g2 == a)
				{
					rema++;
				}
				else if (g2 == b)
				{
					remb++;
				}
				else if (g2 == c)
				{
					remc++;
				}
				else if (g2 == d)
				{
					remd++;
				}

				if (g1 == a)
				{
					rema++;
				}
				else if (g1 == b)
				{
					remb++;
				}
				else if (g1 == c)
				{
					remc++;
				}
				else if (g1 == d)
				{
					remd++;
				}
			}
		}

		else if (W1 == S && W2 == K)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == K && W2 == S)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}

		else if (W1 == S && W2 == N)
		{
			if (g1 == a)
			{
				wyga++;
			}
			else if (g1 == b)
			{
				wygb++;
			}
			else if (g1 == c)
			{
				wygc++;
			}
			else if (g1 == d)
			{
				wygd++;
			}

			if (g2 == a)
			{
				prza++;
			}
			else if (g2 == b)
			{
				przb++;
			}
			else if (g2 == c)
			{
				przc++;
			}
			else if (g2 == d)
			{
				przd++;
			}
		}

		else if (W1 == N && W2 == S)
		{
			if (g2 == a)
			{
				wyga++;
			}
			else if (g2 == b)
			{
				wygb++;
			}
			else if (g2 == c)
			{
				wygc++;
			}
			else if (g2 == d)
			{
				wygd++;
			}

			if (g1 == a)
			{
				prza++;
			}
			else if (g1 == b)
			{
				przb++;
			}
			else if (g1 == c)
			{
				przc++;
			}
			else if (g1 == d)
			{
				przd++;
			}
		}
		x--;
	}

	if (wyga != 0 || prza != 0 || rema != 0)
	{
		cout << "gracz" << " " << "a" << endl;
		if (wyga > 0)
		{
			cout << " " << " " << " " << " " << "wygrane" << ":" << " " << wyga / (wyga + prza + rema) * 100.0 << "%" << endl;
		}
		if (rema > 0)
		{
			cout << " " << " " << " " << " " << "remisy" << ":" << " " << rema / (wyga + prza + rema) * 100.0 << "%" << endl;
		}
		if (prza > 0)
		{
			cout << " " << " " << " " << " " << "przegrane" << ":" << " " << prza / (wyga + prza + rema) * 100.0 << "%" << endl;
		}
		cout << endl;
	}

	if (wygb != 0 || przb != 0 || remb != 0)
	{
		cout << "gracz" << " " << "b" << endl;
		if (wygb > 0)
		{
			cout << " " << " " << " " << " " << "wygrane" << ":" << " " << wygb / (wygb + przb + remb) * 100.0 << "%" << endl;
		}
		if (remb > 0)
		{
			cout << " " << " " << " " << " " << "remisy" << ":" << " " << remb / (wygb + przb + remb) * 100.0 << "%" << endl;
		}
		if (przb > 0)
		{
			cout << " " << " " << " " << " " << "przegrane" << ":" << " " << przb / (wygb + przb + remb) * 100.0 << "%" << endl;
		}
		cout << endl;
	}

	if (wygc != 0 || przc != 0 || remc != 0)
	{
		cout << "gracz" << " " << "c" << endl;
		if (wygc > 0)
		{
			cout << " " << " " << " " << " " << "wygrane" << ":" << " " << wygc / (wygc + przc + remc) * 100.0 << "%" << endl;
		}
		if (remc > 0)
		{
			cout << " " << " " << " " << " " << "remisy" << ":" << " " << remc / (wygc + przc + remc) * 100.0 << "%" << endl;
		}
		if (przc > 0)
		{
			cout << " " << " " << " " << " " << "przegrane" << ":" << " " << przc / (wygc + przc + remc) * 100.0 << "%" << endl;
		}
		cout << endl;
	}

	if (wygd != 0 || przd != 0 || remd != 0)
	{
		cout << "gracz" << " " << "d" << endl;
		if (wygd > 0)
		{
			cout << " " << " " << " " << " " << "wygrane" << ":" << " " << wygd / (wygd + przd + remd) * 100.0 << "%" << endl;
		}
		if (remd > 0)
		{
			cout << " " << " " << " " << " " << "remisy" << ":" << " " << remd / (wygd + przd + remd) * 100.0 << "%" << endl;
		}
		if (przd > 0)
		{
			cout << " " << " " << " " << " " << "przegrane" << ":" << " " << przd / (wygd + przd + remd) * 100.0 << "%" << endl;
		}
	}

	return 0;
}
