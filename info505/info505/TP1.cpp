#include <iostream>
#include <stdlib.h>


using namespace std;

	struct Arbre
	{
		int ind;
		struct Arbre * arbg;
		struct Arbre * arbd;
		int taille;

		Arbre(int elem)
		{
			ind = elem;
			arbg = NULL;
			arbd = NULL;
			taille = 1;
		}

		Arbre(int elem, Arbre * a1, Arbre * a2)
		{
			ind = elem;
			arbg = a1;
			arbd = a2;
			taille = 1 + a1->taille + a2->taille;
		}
	};
	
	void ajoute(int elem, Arbre * arb)
	{
		if (arb = NULL) {
			arb = new Arbre(elem);
			}
		else{
			arb->taille++;
			if (elem <= arb->ind){
				ajoute(elem, arb->arbg);
				arb->arbg->taille++;
			}
			else {
				ajoute(elem, arb->arbd);
				arb->arbd->taille++;
			}
		}
	}

	Arbre * MaxA(Arbre * arb){
		Arbre * a_int = arb;
		while(a_int->arbd != NULL)
		{
			a_int = a_int->arbd;
		}
		return a_int;
	}

	void retire(int elem, Arbre * arb){
	 	if ((arb == NULL) or (arb->ind == 0)) {
	 		cout << "impossible" << endl;
	 	}
	 	else{
	 		if (arb->ind == elem){
	 			if ((arb->arbg == NULL) && (arb->arbd == NULL))
	 			{
	 				*arb = 0;
	 			}
	 			else
	 			{
	 				if (arb->arbg == NULL)
	 				{
	 					arb = arb->arbd;
	 				}
	 				else
	 				{
	 					if(arb->arbd == NULL)
	 					{
	 						arb = arb->arbg;
	 					}
	 					else
	 					{
	 						arb->ind = (MaxA(arb->arbg))->ind;
	 						retire((MaxA(arb->arbg)->ind), arb->arbg);
	 					}
	 				}
	 			}
	 		}
	 		else 
	 		{
	 			if (arb->ind > elem)
	 			{
	 				retire(elem, arb->arbg);
	 			}
	 			else
	 			{
	 				retire(elem, arb->arbd);
	 			}
	 		}
	 	}
	}
	
	int elem_Rang(Arbre * arb, int rang){
		int rg_pere = (1 + arb->arbg->taille);
		if(rg_pere == rang){
			return arb->ind;
		}
		else{
			if(rg_pere>rang){
				elem_Rang(arb->arbg, rang);
			}
			else{
					elem_Rang(arb->arbd, (rang-rg_pere));
			}
		}
	}

	int rang_Elem(Arbre * arb, int elem){
	if (arb->ind == elem){
		return (1+arb->arbg->taille);
	}
	else{
		if(arb->ind > elem){
			rang_Elem(arb->arbg, elem);
		}
		else{
			(1+(arb->arbg->taille)) + rang_Elem(arb->arbd, elem);
		}
	}

	
	}

	 int main ()
	 {
	 	Arbre * arb = new Arbre(4);
	 	cout << arb->ind << endl;
	 	retire(4, arb);
	 	cout << arb->ind << endl;
	 	retire(0, arb);
	 	return 1;
	 }