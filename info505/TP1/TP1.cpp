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
		if (arb == NULL) {
			arb = new Arbre(elem);
			}
		else{
			(arb->taille)++;
			if (elem < (arb->ind)){
				ajoute(elem, arb->arbg);
				(arb->arbg->taille)++;
			}	
			else {
				if(arb->arbd != NULL)
				{
					ajoute(elem, (arb->arbd));
					(arb->arbd->taille)++;
				}
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
				elem_Rang(arb->arbd, (rang-rg_pere)); //ERREUR DE SEGMENTATION
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
			(1+(arb->arbg->taille)) + rang_Elem(arb->arbd, elem); //ERREUR DE SEGMENTATION
		}
	}

	
	}

	 int main ()
	 {
	 	Arbre * arb = new Arbre(4, new Arbre(2), new Arbre(5));
	 	ajoute(3, arb);
	 	retire(4, arb);
	 	int a = rang_Elem(arb, 3);
	 	cout << a << endl;
	 	//for (int i=0; i>(arb->taille);i++){
	 	//	cout << (elem_Rang(arb,i)) <<endl;
	 	//}
	 	return 1;
	 }