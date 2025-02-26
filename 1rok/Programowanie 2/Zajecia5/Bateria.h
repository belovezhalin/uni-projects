#ifndef __BATERIA_H__
#define __BATERIA_H__

class Bateria
{
public:
	Bateria();
	void rozladuj(unsigned ile);
	unsigned getStanNaladowania() const;

private:
	unsigned stanNaladowania;
};

#endif
