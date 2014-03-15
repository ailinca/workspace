/* arbelnod.cpp - programul construieste recursiv si tipareste un arbore
   de numere intregi, utilizand functiile recursive: 'inserare', 'listare'.
   Arborele contine pe langa valorile intregi ordonate (SRD)
   si numarul de aparitii pentru valorile ce se repeta.
   Programul permite elimiarea unei anumite valori (chei), adica
   un nod din arbore ce contine cheia, pastrand arborele de cautare (SRD).
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct tnod
	{
	int	nr;
	int	ap;
	struct	tnod *pstg;
	struct	tnod *pdr;
	} ARB;
int nel = 0;
ARB *e;

void inserare (ARB * &v, int val){
ARB *pc;
int gasit;
if (!v)
	{v = new ARB; v->nr=val; v->ap=1;
	v->pstg=NULL; v->pdr=NULL;}
else if (v->nr > val)
		inserare(v->pstg, val);
else if (v->nr < val)
		inserare(v->pdr, val);
else
	v->ap++;
}

void inlocuire_nod(ARB * &n){ // n - nodul de eliminat
// se inlocuieste cu maximul de pe subarborele stang (acum maximul din n),
// care este pe ramura dreapta a lui 'n',
// sau cu minimul de pe subarborele drept (adica minimul din arborele n),
// rezultatul final fiind acelasi, adica un arbore de cautare
if (n->pdr)
	inlocuire_nod(n->pdr);
else	{e->nr=n->nr;	// e - nodul care se elimina (continutul sau)
	e->ap=n->ap;	// se actualizeaza valorile lui 'e' cu maximul din
	e=n;		// arborele nodului 'n' , ramura dreapta
	n=n->pstg; 	// pastrez legatura la ramura stanga a nodului
	free(e);	// pentru care elimin ramura dreapta, a carei
	}            	// valori s-au mutat in nodul 'eliminat' (inlocuit)
}

void elimina_nod (ARB * &a, int x){// a-arbore, x-valoarea de eliminat
if (!a)
	printf("\nCheia cautata %d nu este in arbore!\n", x);
else if (x < a->nr)	// se cauta pozitia valorii 'x'
	elimina_nod (a->pstg, x);
else if (x > a->nr)
	elimina_nod (a->pdr, x);
else	// s-a gasit pozitia lui 'x'
	{e=a;
	if (!a->pstg){	// are subarborele stang vid
		a=a->pdr;	// se conecteaza subarborele drept
		free(e);	// si eliberez spatiul alocat
		}		// nodului eliminat
	else if (!a->pdr){	// are subarborele drept vid
		a=a->pstg;	// se conecteaza subarborele stang
		free(e);	// si eliberez spatiul alocat
		}		// nodului eliminat
	else
		inlocuire_nod(a->pstg); // sau cu parametru 'a->pdr'
	}      		// cu modificarile respective in functia de inlocuire
}

void listare_SRD (ARB *v){
if (v)
	{if (v->pstg)
		listare_SRD (v->pstg);
	printf("%3d(%d) -> ", v->nr, v->ap);
	nel++;
	if (nel%7==0)
		printf("\n");
	if (v->pdr)
		listare_SRD(v->pdr);
	}
}

main()
{
ARB *pl;
int valoare;
pl = NULL;
clrscr();
printf("Se construieste un arbore de cautare si permite elimarea unui nod.\n");
printf ("\nIntroduceti un sir de valori, terminat cu EOF.\n");
printf ("Valoare:");
while ( scanf ("%d", &valoare) != EOF) {
	inserare (pl,valoare);
	printf ("Valoare:");
	}
/* afisare arbore */
printf("\nListare arbore SRD:\n");
listare_SRD (pl);
printf ("NULL\n");
printf("\nValoare de eliminat: ");
scanf("%d", &valoare);
elimina_nod(pl, valoare);
/* afisare arbore dupa eliminare */
printf("\nListare arbore SRD, dupa eliminarea valorii %d:\n", valoare);
nel=0;	// initializare contor afisare pe ecran
listare_SRD (pl);
printf ("NULL\n");
printf("Terminare dupa apasarea unei taste!\n");
getch();
}
