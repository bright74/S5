#ifndef DEF_ARBRE
#define DEF_ARBRE

#include <iostream>

	//méthodes
	public:
		Arbre(int nind, Arbre narbg, Arbre narbd, int ntaille);
		
		Arbre(int nind);

		int getInd(Arbre * arb);

		void ajoute(int elem, Arbre arb);
		
		void retire(int elem, Arbre arb);
};

#endif