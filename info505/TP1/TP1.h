#ifndef DEF_ARBRE
#define DEF_ARBRE

#include <iostream>

	//méthodes
		Arbre(int nind, Arbre narbg, Arbre narbd, int ntaille);
		
		Arbre(int nind);

		void ajoute(int elem, Arbre * arb);
		
		int maxA(Arbre * arb);

		void retire(int elem, Arbre * arb);

#endif