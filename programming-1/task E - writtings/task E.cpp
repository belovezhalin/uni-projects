// Anhelina Belavezha
#include <iostream>
using namespace std;

unsigned long long suma = 0;

struct Miejsce
{
    unsigned short towar;
    char e[2];
};

struct Polka
{
    Miejsce miejsce[128];
    unsigned short milosc;
};

struct Regal
{
    Polka polka[128];
    unsigned short pilosc;
};

struct Magazyn
{
    Regal regal[128];
    unsigned short rilosc;
    Polka handyshelf;
};

struct Sklad
{
    Magazyn magazyn[128];
    Regal podregal;
    Polka podpolka;
    unsigned short silosc;
} static st;

void i_miejsce1(Miejsce &miejsce)
{
    miejsce.towar = 0;
    miejsce.e[0] = '0';
    miejsce.e[1] = '0';
}

void i_miejsce2(Miejsce &miejsce)
{
    miejsce.e[0] = '0';
    miejsce.e[1] = '0';
}

///////////////////////////set////////////////////////////

void setap(unsigned short w, unsigned short r, unsigned short s, unsigned short p, Polka &polka)
{
    for (int i = p; i < polka.milosc; i++)
    {
        suma -= polka.miejsce[i].towar;
        i_miejsce1(polka.miejsce[i]);
    }

    for (int i = polka.milosc; i < p; i++)
    {
        suma -= polka.miejsce[i].towar;
        i_miejsce1(polka.miejsce[i]);
    }

    polka.milosc = p;
}

void setas(unsigned short w, unsigned short r, unsigned short s, unsigned short p, Regal &regal)
{
    for (int i = s; i < regal.pilosc; i++)
    {
        regal.polka[i].milosc = 0;
        for (int n = 0; n < 128; n++)
            suma -= regal.polka[i].miejsce[n].towar;
    }

    for (int i = 0; i < s; i++)
    {
        setap(w, r, s, p, regal.polka[i]);
    }

    setap(w, r, s, p, regal.polka[0]);
    regal.pilosc = s;
}

void setar(unsigned short w, unsigned short r, unsigned short s, unsigned short p, Magazyn &magazyn)
{
    for (int i = r; i < magazyn.rilosc; i++)
    {
        magazyn.regal[i].pilosc = 0;
    }

    for (int i = 0; i < r; i++)
    {
        setas(w, r, s, p, magazyn.regal[i]);
    }

    setas(w, r, s, p, magazyn.regal[0]);
    magazyn.rilosc = r;
}

void setaw(unsigned short w, unsigned short r, unsigned short s, unsigned short p, Sklad &sklad)
{
    for (int i = w; i < sklad.silosc; i++)
    {
        sklad.magazyn[i].rilosc = 0;
    }

    for (int i = 0; i < w; i++)
    {
        setar(w, r, s, p, sklad.magazyn[i]);
    }

    setar(w, r, s, p, sklad.magazyn[0]);
    sklad.silosc = w;
}

///////////////////////put/////////////////////

void putw(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short A)
{
    if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc || p >= st.magazyn[w].regal[r].polka[s].milosc)
        cout << "error" << endl;
    else
    {
        if (65535 < st.magazyn[w].regal[r].polka[s].miejsce[p].towar + A)
        {
            suma += 65535 - st.magazyn[w].regal[r].polka[s].miejsce[p].towar;
            st.magazyn[w].regal[r].polka[s].miejsce[p].towar = 65535;
        }
        else
        {
            st.magazyn[w].regal[r].polka[s].miejsce[p].towar += A;
            suma += A;
        }
    }
}

void puth(unsigned short w, unsigned short p, unsigned short A)
{
    if (w >= st.silosc || p >= st.magazyn[w].handyshelf.milosc)
        cout << "error" << endl;
    else
    {
        if (65535 < st.magazyn[w].handyshelf.miejsce[p].towar + A)
        {
            suma += 65535 - st.magazyn[w].handyshelf.miejsce[p].towar;
            st.magazyn[w].handyshelf.miejsce[p].towar = 65535;
        }
        else
        {
            st.magazyn[w].handyshelf.miejsce[p].towar += A;
            suma += A;
        }
    }
}

void putr(unsigned short s, unsigned short p, unsigned short A)
{
    if (s >= st.podregal.pilosc || p >= st.podregal.polka[s].milosc)
        cout << "error" << endl;
    else
    {
        if (65535 < st.podregal.polka[s].miejsce[p].towar + A)
        {
            suma += 65535 - st.podregal.polka[s].miejsce[p].towar;
            st.podregal.polka[s].miejsce[p].towar = 65535;
        }
        else
        {
            st.podregal.polka[s].miejsce[p].towar += A;
            suma += A;
        }
    }
}

void puts(unsigned short p, unsigned short A)
{
    if (p >= st.podpolka.milosc)
        cout << "error" << endl;
    else
    {
        if (65535 < st.podpolka.miejsce[p].towar + A)
        {
            suma += 65535 - st.podpolka.miejsce[p].towar;
            st.podpolka.miejsce[p].towar = 65535;
        }
        else
        {
            st.podpolka.miejsce[p].towar += A;
            suma += A;
        }
    }
}

////////////////////////fill//////////////////////

void fill(unsigned long long w, unsigned long long r, unsigned long long s, unsigned long long p, unsigned long long A)
{
    st.podpolka.milosc = p;
    st.podregal.pilosc = s;

    suma = 0;
    suma += A * w * r * s * p;
    suma += A * w * p;
    suma += A * p;
    suma += A * s * p;

    for (int i = 0; i < w; i++)
    {
        for (int x = 0; x < r; x++)
        {
            for (int y = 0; y < s; y++)
            {
                for (int z = 0; z < p; z++)
                {
                    i_miejsce2(st.magazyn[i].regal[x].polka[y].miejsce[z]);
                    st.magazyn[i].regal[x].polka[y].miejsce[z].towar = A;
                }

                st.magazyn[i].regal[x].polka[y].milosc = p;
                st.magazyn[i].handyshelf.milosc = p;
                st.podregal.polka[y].milosc = p;
            }
            st.magazyn[i].regal[x].pilosc = s;
        }
        st.magazyn[i].rilosc = r;
    }

    st.silosc = w;

    for (int i = 0; i < w; i++)
    {
        for (int z = 0; z < p; z++)
        {
            i_miejsce2(st.magazyn[i].handyshelf.miejsce[z]);
            st.magazyn[i].handyshelf.miejsce[z].towar = A;
        }
    }

    for (int z = 0; z < p; z++)
    {
        i_miejsce2(st.podpolka.miejsce[z]);
        st.podpolka.miejsce[z].towar = A;
    }

    for (int y = 0; y < s; y++)
    {
        for (int z = 0; z < p; z++)
        {
            i_miejsce2(st.podregal.polka[y].miejsce[z]);
            st.podregal.polka[y].miejsce[z].towar = A;
        }
    }
}

////////////////////pop//////////////////////////

void popw(unsigned short w, unsigned short r, unsigned short s, unsigned short p, unsigned short A)
{
    if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc || p >= st.magazyn[w].regal[r].polka[s].milosc)
        cout << "error" << endl;
    else
    {
        if (st.magazyn[w].regal[r].polka[s].miejsce[p].towar - A < 0)
        {
            suma -= st.magazyn[w].regal[r].polka[s].miejsce[p].towar;
            st.magazyn[w].regal[r].polka[s].miejsce[p].towar = 0;
        }
        else
        {
            st.magazyn[w].regal[r].polka[s].miejsce[p].towar -= A;
            suma -= A;
        }
    }
}

void poph(unsigned short w, unsigned short p, unsigned short A)
{
    if (w >= st.silosc || p >= st.magazyn[w].handyshelf.milosc)
        cout << "error" << endl;
    else
    {
        if (st.magazyn[w].handyshelf.miejsce[p].towar - A < 0)
        {
            suma -= st.magazyn[w].handyshelf.miejsce[p].towar;
            st.magazyn[w].handyshelf.miejsce[p].towar = 0;
        }
        else
        {
            st.magazyn[w].handyshelf.miejsce[p].towar -= A;
            suma -= A;
        }
    }
}

void popr(unsigned short s, unsigned short p, unsigned short A)
{
    if (s >= st.podregal.pilosc || p >= st.podregal.polka[s].milosc)
        cout << "error" << endl;
    else
    {
        if (st.podregal.polka[s].miejsce[p].towar - A < 0)
        {
            suma -= st.podregal.polka[s].miejsce[p].towar;
            st.podregal.polka[s].miejsce[p].towar = 0;
        }
        else
        {
            st.podregal.polka[s].miejsce[p].towar -= A;
            suma -= A;
        }
    }
}

void pops(unsigned short p, unsigned short A)
{
    if (p >= st.podpolka.milosc)
        cout << "error" << endl;
    else
    {
        if (st.podpolka.miejsce[p].towar - A < 0)
        {
            suma -= st.podpolka.miejsce[p].towar;
            st.podpolka.miejsce[p].towar = 0;
        }
        else
        {
            st.podpolka.miejsce[p].towar -= A;
            suma -= A;
        }
    }
}

/////////////////////////////get//////////////////////////

void getw(unsigned long long w)
{
    unsigned long long ilosc = 0;

    for (int x = 0; x < st.magazyn[w].rilosc; x++)
    {
        for (int y = 0; y < st.magazyn[w].regal[x].pilosc; y++)
        {
            for (int z = 0; z < st.magazyn[w].regal[x].polka[y].milosc; z++)
            {
                ilosc += st.magazyn[w].regal[x].polka[y].miejsce[z].towar;
            }
        }
    }

    for (int n = 0; n < st.magazyn[w].handyshelf.milosc; n++)
    {
        ilosc += st.magazyn[w].handyshelf.miejsce[n].towar;
    }

    cout << ilosc << endl;
}

void getrw(unsigned long long w, unsigned long long r)
{
    unsigned long long ilosc = 0;
    for (int m = 0; m < st.magazyn[w].regal[r].pilosc; m++)
    {
        for (int n = 0; n < st.magazyn[w].regal[r].polka[m].milosc; n++)
        {
            ilosc += st.magazyn[w].regal[r].polka[m].miejsce[n].towar;
        }
    }
    cout << ilosc << endl;
}

void getrh()
{
    unsigned long long ilosc = 0;

    for (int i = 0; i < st.podregal.pilosc; i++)
    {
        for (int n = 0; n < st.podregal.polka[i].milosc; n++)
        {
            ilosc += st.podregal.polka[i].miejsce[n].towar;
        }
    }

    cout << ilosc << endl;
}

void getsw(unsigned short w, unsigned long long r, unsigned long long s)
{
    long long ilosc = 0;

    for (int n = 0; n < st.magazyn[w].regal[r].polka[s].milosc; n++)
    {
        ilosc += st.magazyn[w].regal[r].polka[s].miejsce[n].towar;
    }

    cout << ilosc << endl;
}

void getsh(unsigned long long w)
{
    unsigned long long ilosc = 0;

    for (int n = 0; n < st.magazyn[w].handyshelf.milosc; n++)
    {
        ilosc += st.magazyn[w].handyshelf.miejsce[n].towar;
    }

    cout << ilosc << endl;
}

void getsr(unsigned long long s)
{
    unsigned long long ilosc = 0;

    for (int n = 0; n < st.podregal.polka[s].milosc; n++)
    {
        ilosc += st.podregal.polka[s].miejsce[n].towar;
    }

    cout << ilosc << endl;
}

void gets()
{
    unsigned long long ilosc = 0;

    for (int n = 0; n < st.podpolka.milosc; n++)
    {
        ilosc += st.podpolka.miejsce[n].towar;
    }

    cout << ilosc << endl;
}

//////////////////etykietowe////////////////////////

void setlw(unsigned long long w, unsigned short r, unsigned short s, unsigned short p, char et1, char et2)
{
    st.magazyn[w].regal[r].polka[s].miejsce[p].e[0] = et1;
    st.magazyn[w].regal[r].polka[s].miejsce[p].e[1] = et2;
}

void setlh(unsigned short w, unsigned short p, char et1, char et2)
{
    st.magazyn[w].handyshelf.miejsce[p].e[0] = et1;
    st.magazyn[w].handyshelf.miejsce[p].e[1] = et2;
}

void setlr(unsigned short s, unsigned short p, char et1, char et2)
{
    st.podregal.polka[s].miejsce[p].e[0] = et1;
    st.podregal.polka[s].miejsce[p].e[1] = et2;
}

void setls(unsigned short p, char et1, char et2)
{
    st.podpolka.miejsce[p].e[0] = et1;
    st.podpolka.miejsce[p].e[1] = et2;
}

void getlw(unsigned short w, unsigned short r, unsigned short s, unsigned short p)
{
    cout << st.magazyn[w].regal[r].polka[s].miejsce[p].e[0];
    cout << st.magazyn[w].regal[r].polka[s].miejsce[p].e[1] << endl;
}

void getlh(unsigned short w, unsigned short p)
{
    cout << st.magazyn[w].handyshelf.miejsce[p].e[0];
    cout << st.magazyn[w].handyshelf.miejsce[p].e[1] << endl;
}

void getlr(unsigned short s, unsigned short p)
{
    cout << st.podregal.polka[s].miejsce[p].e[0];
    cout << st.podregal.polka[s].miejsce[p].e[1] << endl;
}

void getls(unsigned short p)
{
    cout << st.podpolka.miejsce[p].e[0];
    cout << st.podpolka.miejsce[p].e[1] << endl;
}

int main()
{
    unsigned long long w, r, s, p, A, ww, rr, ss;
    char etykieta1, etykieta2;
    char operacja[6];

    while (operacja[0] != 'E' && operacja[1] != 'N' && operacja[2] != 'D')
    {
        cin >> operacja;

        if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'A' && operacja[5] == 'P')
        {
            cin >> w >> r >> s >> p;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc || p > 128)
                cout << "error" << endl;
            else
                setap(w, r, s, p, st.magazyn[w].regal[r].polka[s]);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'A' && operacja[5] == 'S')
        {
            cin >> w >> r >> s >> p;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc || s > 128 || p > 128)
                cout << "error" << endl;
            else
                setas(w, r, s, p, st.magazyn[w].regal[r]);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'A' && operacja[5] == 'R')
        {
            cin >> w >> r >> s >> p;
            if (w >= st.silosc || r > 128 || s > 128 || p > 128)
                cout << "error" << endl;
            else
                setar(w, r, s, p, st.magazyn[w]);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'A' && operacja[5] == 'W')
        {
            cin >> w >> r >> s >> p;
            if (w > 128 || r > 128 || s > 128 || p > 128)
                cout << "error" << endl;
            else
                setaw(w, r, s, p, st);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'H' && operacja[5] == 'W')
        {
            cin >> w >> p;
            if (w >= st.silosc || p > 128)
                cout << "error" << endl;
            else
                setap(w, 0, 0, p, st.magazyn[w].handyshelf);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'H' && operacja[5] == 'R')
        {
            cin >> s >> p;
            if (s > 128 || p > 128)
                cout << "error" << endl;
            else
                setas(0, 0, s, p, st.podregal);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'H' && operacja[5] == 'S')
        {
            cin >> p;
            if (p > 128)
                cout << "error" << endl;
            else
                setap(0, 0, 0, p, st.podpolka);
        }

        else if (operacja[0] == 'P' && operacja[1] == 'U' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'W')
        {
            cin >> w >> r >> s >> p >> A;
            putw(w, r, s, p, A);
        }

        else if (operacja[0] == 'P' && operacja[1] == 'U' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'H')
        {
            cin >> w >> p >> A;
            puth(w, p, A);
        }

        else if (operacja[0] == 'P' && operacja[1] == 'U' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'R')
        {
            cin >> s >> p >> A;
            putr(s, p, A);
        }

        else if (operacja[0] == 'P' && operacja[1] == 'U' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'S')
        {
            cin >> p >> A;
            puts(p, A);
        }

        else if (operacja[0] == 'F' && operacja[1] == 'I' && operacja[2] == 'L' && operacja[3] == 'L')
        {
            cin >> w >> r >> s >> p >> A;
            if (w > 128 || r > 128 || s > 128 || p > 128)
                cout << "error" << endl;
            else
                fill(w, r, s, p, A);
        }

        else if (operacja[0] == 'P' && operacja[1] == 'O' && operacja[2] == 'P' && operacja[3] == '-' && operacja[4] == 'W')
        {
            cin >> w >> r >> s >> p >> A;
            popw(w, r, s, p, A);
        }

        else if (operacja[0] == 'P' && operacja[1] == 'O' && operacja[2] == 'P' && operacja[3] == '-' && operacja[4] == 'H')
        {
            cin >> w >> p >> A;
            poph(w, p, A);
        }

        else if (operacja[0] == 'P' && operacja[1] == 'O' && operacja[2] == 'P' && operacja[3] == '-' && operacja[4] == 'R')
        {
            cin >> s >> p >> A;
            popr(s, p, A);
        }

        else if (operacja[0] == 'P' && operacja[1] == 'O' && operacja[2] == 'P' && operacja[3] == '-' && operacja[4] == 'S')
        {
            cin >> p >> A;
            pops(p, A);
        }

        else if (operacja[0] == 'M' && operacja[1] == 'O' && operacja[2] == 'V' && operacja[3] == '-' && operacja[4] == 'W')
        {
            cin >> w >> r >> s >> ww >> rr >> ss >> p >> A;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc || p >= st.magazyn[w].regal[r].polka[s].milosc || ww >= st.silosc || rr >= st.magazyn[w].rilosc || ss >= st.magazyn[w].regal[r].pilosc)
                cout << "error" << endl;
            else
            {
                for (int i = 0; i < A; i++)
                {
                    if (st.magazyn[w].regal[r].polka[s].miejsce[p].towar - 1 < 0 || 65535 < st.magazyn[ww].regal[rr].polka[ss].miejsce[p].towar + 1)
                        break;
                    else
                    {
                        st.magazyn[w].regal[r].polka[s].miejsce[p].towar -= 1;
                        st.magazyn[ww].regal[rr].polka[ss].miejsce[p].towar += 1;
                    }
                }
            }
        }

        else if (operacja[0] == 'M' && operacja[1] == 'O' && operacja[2] == 'V' && operacja[3] == '-' && operacja[4] == 'H')
        {
            cin >> w >> r >> s >> p >> A;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc || p >= st.magazyn[w].regal[r].polka[s].milosc || p >= st.magazyn[w].handyshelf.milosc)
                cout << "error" << endl;
            else
            {
                for (int i = 0; i < A; i++)
                {
                    if (st.magazyn[w].regal[r].polka[s].miejsce[p].towar - 1 < 0 || 65535 < st.magazyn[w].handyshelf.miejsce[p].towar + 1)
                        break;
                    else
                    {
                        st.magazyn[w].regal[r].polka[s].miejsce[p].towar -= 1;
                        st.magazyn[w].handyshelf.miejsce[p].towar += 1;
                    }
                }
            }
        }

        else if (operacja[0] == 'M' && operacja[1] == 'O' && operacja[2] == 'V' && operacja[3] == '-' && operacja[4] == 'R')
        {
            cin >> w >> r >> s >> ss >> p >> A;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc || p >= st.magazyn[w].regal[r].polka[s].milosc || ss >= st.podregal.pilosc || p >= st.podregal.polka[ss].milosc)
                cout << "error" << endl;
            else
            {
                for (int i = 0; i < A; i++)
                {
                    if (st.magazyn[w].regal[r].polka[s].miejsce[p].towar - 1 < 0 || 65535 < st.podregal.polka[ss].miejsce[p].towar + 1)
                        break;
                    else
                    {
                        st.magazyn[w].regal[r].polka[s].miejsce[p].towar -= 1;
                        st.podregal.polka[ss].miejsce[p].towar += 1;
                    }
                }
            }
        }

        else if (operacja[0] == 'M' && operacja[1] == 'O' && operacja[2] == 'V' && operacja[3] == '-' && operacja[4] == 'S')
        {
            cin >> s >> p >> A;
            if (s >= st.podregal.pilosc || p >= st.podregal.polka[s].milosc || p >= st.podpolka.milosc)
                cout << "error" << endl;
            else
            {
                for (int i = 0; i < A; i++)
                {
                    if (st.podregal.polka[s].miejsce[p].towar - 1 < 0 || 65535 < st.podpolka.miejsce[p].towar + 1)
                        break;
                    else
                    {
                        st.podregal.polka[s].miejsce[p].towar -= 1;
                        st.podpolka.miejsce[p].towar += 1;
                    }
                }
            }
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'E')
        {
            cout << suma << endl;
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'W')
        {
            cin >> w;
            if (w >= st.silosc)
                cout << "error" << endl;
            else
                getw(w);
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'R' && operacja[5] == 'W')
        {
            cin >> w >> r;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc)
                cout << "error" << endl;
            else
                getrw(w, r);
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'R' && operacja[5] == 'H')
        {
            getrh();
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'S' && operacja[5] == 'W')
        {
            cin >> w >> r >> s;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc)
                cout << "error" << endl;
            else
                getsw(w, r, s);
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'S' && operacja[5] == 'H')
        {
            cin >> w;
            if (w >= st.silosc)
                cout << "error" << endl;
            else
                getsh(w);
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'S' && operacja[5] == 'R')
        {
            cin >> s;
            if (s >= st.podregal.pilosc)
                cout << "error" << endl;
            else
                getsr(s);
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'S')
        {
            gets();
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'L' && operacja[5] == 'W')
        {
            cin >> w >> r >> s >> p >> etykieta1 >> etykieta2;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc || p >= st.magazyn[w].regal[r].polka[s].milosc)
                cout << "error" << endl;
            else
                setlw(w, r, s, p, etykieta1, etykieta2);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'L' && operacja[5] == 'H')
        {
            cin >> w >> p >> etykieta1 >> etykieta2;
            if (w >= st.silosc || p >= st.podpolka.milosc)
                cout << "error" << endl;
            else
                setlh(w, p, etykieta1, etykieta2);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'L' && operacja[5] == 'R')
        {
            cin >> s >> p >> etykieta1 >> etykieta2;
            if (s >= st.podregal.pilosc || p >= st.podregal.polka[s].milosc)
                cout << "error" << endl;
            else
                setlr(s, p, etykieta1, etykieta2);
        }

        else if (operacja[0] == 'S' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'L' && operacja[5] == 'S')
        {
            cin >> p >> etykieta1 >> etykieta2;
            if (p >= st.podpolka.milosc)
                cout << "error" << endl;
            else
                setls(p, etykieta1, etykieta2);
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'L' && operacja[5] == 'W')
        {
            cin >> w >> r >> s >> p;
            if (w >= st.silosc || r >= st.magazyn[w].rilosc || s >= st.magazyn[w].regal[r].pilosc || p >= st.magazyn[w].regal[r].polka[s].milosc)
                cout << "error" << endl;
            else
            {
                if (st.magazyn[w].regal[r].polka[s].miejsce[p].e[0] == '0' && st.magazyn[w].regal[r].polka[s].miejsce[p].e[1] == '0')
                    cout << "--" << endl;
                else
                    getlw(w, r, s, p);
            }
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'L' && operacja[5] == 'H')
        {
            cin >> w >> p;
            if (w >= st.silosc || p >= st.podpolka.milosc)
                cout << "error" << endl;
            else
            {
                if (st.magazyn[w].handyshelf.miejsce[p].e[0] == '0' && st.magazyn[w].handyshelf.miejsce[p].e[1] == '0')
                    cout << "--" << endl;
                else
                    getlh(w, p);
            }
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'L' && operacja[5] == 'R')
        {
            cin >> s >> p;
            if (s >= st.podregal.pilosc || p >= st.podregal.polka[s].milosc)
                cout << "error" << endl;
            else
            {
                if (st.podregal.polka[s].miejsce[p].e[0] == '0' && st.podregal.polka[s].miejsce[p].e[1] == '0')
                    cout << "--" << endl;
                else
                    getlr(s, p);
            }
        }

        else if (operacja[0] == 'G' && operacja[1] == 'E' && operacja[2] == 'T' && operacja[3] == '-' && operacja[4] == 'L' && operacja[5] == 'S')
        {
            cin >> p;
            if (p >= st.podpolka.milosc)
                cout << "error" << endl;
            else
            {
                if (st.podpolka.miejsce[p].e[0] == '0' && st.podpolka.miejsce[p].e[1] == '0')
                    cout << "--" << endl;
                else
                    getls(p);
            }
        }
    }
}
