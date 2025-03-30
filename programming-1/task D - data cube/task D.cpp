// Anhelina Belavezha
#include <iostream>
using namespace std;
int szescian[32][32][32];
int n, sr;

int czworoscian(int l, int v, int p, int e)
{
	int poziom;

	if (l < sr)
		poziom = l + e;
	else
		poziom = l - e;

	if (l > poziom)
	{
		int bufor;
		bufor = poziom;
		poziom = l;
		l = bufor;
	}

	int pion;

	if (v < sr)
		pion = v + e;
	else
		pion = v - e;

	if (v > pion)
	{
		int bufor;
		bufor = pion;
		pion = v;
		v = bufor;
	}

	int panel;

	if (p < sr)
		panel = p + e;
	else
		panel = p - e;

	if (p > panel)
	{
		int bufor;
		bufor = panel;
		panel = p;
		p = bufor;
	}

	int x, y, z, suma = 0;
	for (int i = l; i <= poziom; i++)
	{
		for (int j = v; j <= pion; j++)
		{
			for (int g = p; g <= panel; g++)
			{
				if (i >= 0 && i < n && j >= 0 && j < n && g >= 0 && g < n)
				{
					x = i - l;
					y = j - v;
					z = g - p;
					if (x + y + z <= e)
						suma += szescian[i][j][g];
				}
			}
		}
	}
	return suma;
}

int oktal(int l, int v, int p, int r)
{
	int poziom;

	if (l < sr)
		poziom = l + r;
	else
		poziom = l - r;

	if (l > poziom)
	{
		int bufor;
		bufor = poziom;
		poziom = l;
		l = bufor;
	}

	int pion;

	if (v < sr)
		pion = v + r;
	else
		pion = v - r;

	if (v > pion)
	{
		int bufor;
		bufor = pion;
		pion = v;
		v = bufor;
	}

	int panel;

	if (p < sr)
		panel = p + r;
	else
		panel = p - r;

	if (p > panel)
	{
		int bufor;
		bufor = panel;
		panel = p;
		p = bufor;
	}

	int x, y, z, suma = 0;
	for (int i = l; i <= poziom; i++)
	{
		for (int j = v; j <= pion; j++)
		{
			for (int g = p; g <= panel; g++)
			{
				if (i >= 0 && i < n && j >= 0 && j < n && g >= 0 && g < n)
				{
					x = i - l;
					y = j - v;
					z = g - p;
					if (x * x + y * y + z * z <= r * r)
						suma += szescian[i][j][g];
				}
			}
		}
	}
	return suma;
}

int prostopadloscian(int l, int v, int p, int h, int w, int d)
{
	int poziom;

	if (l < sr)
		poziom = l + h;
	else
		poziom = l - h;

	if (l > poziom)
	{
		int bufor;
		bufor = poziom;
		poziom = l;
		l = bufor;
	}

	int pion;

	if (v < sr)
		pion = v + w;
	else
		pion = v - w;

	if (v > pion)
	{
		int bufor;
		bufor = pion;
		pion = v;
		v = bufor;
	}

	int panel;

	if (p < sr)
		panel = p + d;
	else
		panel = p - d;

	if (p > panel)
	{
		int bufor;
		bufor = panel;
		panel = p;
		p = bufor;
	}

	int suma = 0;
	for (int i = l; i <= poziom; i++)
	{
		for (int j = v; j <= pion; j++)
		{
			for (int g = p; g <= panel; g++)
			{
				if (i >= 0 && i < n && j >= 0 && j < n && g >= 0 && g < n)
				{
					suma += szescian[i][j][g];
				}
			}
		}
	}
	return suma;
}

long long nwd(long long int x, long long int y)
{
	while (x != 0)
	{
		long long int bufor;
		y %= x;
		bufor = y;
		y = x;
		x = bufor;
	}
	return y;
}

long long int wyznacznik(long long int array[][32], int rozmiar)
{
	long long int dziel = 1;

	for (int i = 0; i < rozmiar - 1; i++)
	{
		for (int j = i + 1; j < rozmiar; j++)
		{
			if (array[j][i] == 0)
				continue;
			if (array[i][i] == 0)
				for (int k = 0; k < rozmiar; k++)
				{
					array[i][k] += array[j][k];
				}

			long long int nww = array[j][i] * array[i][i] / nwd(array[j][i], array[i][i]);
			long long int il = nww / array[j][i];
			for (int k = 0; k < rozmiar; k++)
			{
				array[j][k] *= il;
			}

			dziel *= il;
			long long int przelicznik = array[j][i] / array[i][i];
			for (int k = 0; k < rozmiar; k++)
			{
				array[j][k] -= przelicznik * array[i][k];
			}
		}
	}
	long long int det = 1;
	for (int i = 0; i < rozmiar; i++)
	{
		det *= array[i][i];
	}

	return det / dziel;
}

int main()
{
	int l, v, p, h, w, d, e, r, i;
	long long int resultat;
	char o, k;

	cin >> n;
	sr = n / 2;

	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			for (int c = 0; c < n; c++)
			{
				cin >> szescian[b][c][a];
			}
		}
	}

	cin >> o;

	while (o != 'E')
	{
		switch (o)
		{
		case 'C':
			cin >> l >> v >> p >> h >> w >> d;
			resultat = prostopadloscian(l, v, p, h, w, d);
			cout << resultat << endl;
			break;

		case 'T':
			cin >> l >> v >> p >> e;
			resultat = czworoscian(l, v, p, e);
			cout << resultat << endl;
			break;

		case 'O':
			cin >> l >> v >> p >> r;
			resultat = oktal(l, v, p, r);
			cout << resultat << endl;
			break;

		case 'D':
			cin >> k >> i;
			long long int array[32][32];

			switch (k)
			{
			case 'l':
				for (int x = 0; x < n; x++)
				{
					for (int y = 0; y < n; y++)
					{
						array[x][y] = szescian[i][x][y];
					}
				}
				break;

			case 'v':
				for (int x = 0; x < n; x++)
				{
					for (int y = 0; y < n; y++)
					{
						array[x][y] = szescian[x][i][y];
					}
				}
				break;

			case 'p':
				for (int x = 0; x < n; x++)
				{
					for (int y = 0; y < n; y++)
					{
						array[x][y] = szescian[x][y][i];
					}
				}
				break;
			}

			resultat = wyznacznik(array, n);
			cout << resultat << endl;
			break;
		}

		cin >> o;
	}
}
