#include <stdio.h>
#include <stdlib.h>

#define HAUTEUR 10
#define LARGEUR 15
#define NB_PIECES 2
#define HAUTEUR_MAX_DES_PIECES 4

typedef char Grille[HAUTEUR][LARGEUR];

struct SPiece {
	int hauteur;
	int largeur;
	char* forme [HAUTEUR_MAX_DES_PIECES];
};

typedef struct SPiece Piece;

void initialiseGrille (Grille g) {
	for (int j=0; j<HAUTEUR; j++) {
		for (int i=0;i<LARGEUR;i++){
			g[j][i] = ' ';
		}
	}
}

char lireCase (Grille g, int lig, int col){
	if ((lig >= 0 && lig < HAUTEUR) && (col >= 0 && col < LARGEUR)){
		return g[lig][col];
	}
	else {
		printf("Valeur invalide!\n");
		return NULL;
	}
}

void ecrireCase(Grille g, int lig, int col, char c) {
		g[lig][col]=c;
}

int hauteurPlat(Grille g, int premcol, int dercol){
	int max=0;
	for ( int i = premcol; i <= dercol; i++ ){
		for ( int j = HAUTEUR-1; j >= 0; j--){
			if ((lireCase(g,j,i)!=' ') && (j+1 > max)){
				max = j+1;
			}
		}
	}
	return max;
}

void gameOver(Grille g) {
	printf("GAME OVER !\n");
	initialiseGrille(g);

}

void supprimerLigne(Grille g, int lig) {
	for(int i = lig; i<HAUTEUR-1; i++){
		for(int j = 0; j<LARGEUR; j++){
			ecrireCase(g, i, j, g[i+1][j]);
		}
	}
	for(int j = 0; j<LARGEUR; j++){
		ecrireCase(g, HAUTEUR-1, j, ' ');
	}
}

int nettoyer(Grille g) {
	printf("nettoie\n");
	int cmp=0;
	int j=0;
	for(int i=HAUTEUR-1; i>=0; i--) {
		printf("0\n");
		while(j!=LARGEUR) {
			printf("1\n");
			if(g[i][j]==' ') {
				printf("2\n");
				j=LARGEUR;
			} 
			else {
				printf("3\n");
				if(j==LARGEUR-1) {
					printf("4\n");
					supprimerLigne(g, i);
					cmp++;
				}
				else {
					printf("5\n");
					j++;
				}
			}
		}

	}
	return cmp;
}

void ecrirePiece(Grille g, Piece p, int col, int haut){
	if ((haut + p.hauteur-1)>=HAUTEUR){
		gameOver(g);
	}
	else{
		for(int i = 0 ; i < p.hauteur ; i++){
			for (int j = 0 ; j < p.largeur ; j++){
				ecrireCase(g, i+haut, j+col, p.forme[i][j]);
			}
		}
	}
	nettoyer(g);
}

void afficheGrille (Grille g){
	for (int i=HAUTEUR-1; i>=0; i--){
		printf("%d ||",i);
		for (int j=0;j<LARGEUR;j++){
			printf("%c", lireCase(g, i, j));
		}
		printf("||\n");
	}
	printf("  |||||||||||||||||||\n");
	printf("    0         1    \n");
	printf("    012345678901234\n");
}
void genererPieces(Piece tabPiece[]) {

	tabPiece[0].hauteur = 2;
	tabPiece[0].largeur = 2;
	tabPiece[0].forme[1] = "@@";
	tabPiece[0].forme[0] = "@@";

	tabPiece[1].hauteur = 4;
	tabPiece[1].largeur = 1;
	tabPiece[1].forme[3] = "l";
	tabPiece[1].forme[2] = "l";
	tabPiece[1].forme[1] = "l";
	tabPiece[1].forme[0] = "l";
}

void affichePiece(Piece p) {
	int tmp = 0;
	for(int i=0; i<p.hauteur; i++) {
		printf("          %s\n", p.forme[i]);
	}

}

int pieceAleatoire() {
	return (int)((double)random()/(double)RAND_MAX * (NB_PIECES));
}

int main(){

	Grille g;
	Piece tabPiece[NB_PIECES];
	initialiseGrille(g);
	genererPieces(tabPiece);
	int col;
	int p;
	int dercol;

	while (col !=-1) {
		p=1;//pieceAleatoire();
		affichePiece(tabPiece[p]);
		afficheGrille(g);
		printf("Où voulez-vous mettre la piece ?\n");
		scanf("%d", &col);
		dercol = col + tabPiece[p].largeur-1;
		ecrirePiece(g, tabPiece[p], col, hauteurPlat(g , col , dercol));
	}

	return 0;
}