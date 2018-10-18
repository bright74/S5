#ifndef _TETRIS_H_
#define _TETRIS_H_

/* Constantes */
#define HAUTEUR 10
#define LARGEUR 15
#define NB_PIECES 2
#define HAUTEUR_MAX_DES_PIECES 4
/* ... */

/* Types */
typedef char Grille[HAUTEUR][LARGEUR];
struct SPiece {
	int hauteur;
	int largeur;
	char* forme [HAUTEUR_MAX_DES_PIECES];
};
typedef struct SPiece Piece;
/* ... */

/* Fonctions */
extern void initialiseGrille(Grille g);
extern void genererPieces(Piece tabPiece[ NB_PIECES ]);
extern void affichePieces(Piece p);
extern char lireCase(Grille g, int lig, int col);
extern void ecrireCase(Grille g, int lig, int col, char c);
extern int hauteurPlat(Grille g, int premcol, int dercol);
extern void gameOver(Grille g);
extern void supprimerLigne(Grille g, int lig);
extern int nettoyer(Grille g);
extern void ecrirePiece(Grille g, Piece p, int col, int haut);
extern void afficheGrille(Grille g);
extern int pieceAleatoire();

#endif 