#pragma once
#include "Gracz.h"

class Kasyno;
class Bot : public Gracz {
private:
	int odwaga;
public:
	Bot();
	~Bot();

	void nazwij_bot(int _n);
	void ustaw_odwage();
	void wybor_bot();	
};