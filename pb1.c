//1. Intr-o lista inlantuita sunt mai multe litere mici.
//Afisati literele distincte aflate in lista..

#include <stdio.h>
#include <stdlib.h>

struct lista
{
	char key;
	struct lista *next;
};

typedef struct lista node;

node *init()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->next=NULL;
	return p;
}

void *add_elem(node* cap_lista)
{
	node *p, *q;
	p=cap_lista;
	while(p->next!=NULL)
		p=p->next;
	q=init();
	printf("Baga valoarea: ");
	scanf("%c",q->key);
	p->next=q;
}

void write(node *cap_lista)
{
	node *p, *q;
	int c;
	p=cap_lista->next;

	printf("%c ",&p->key);
	for(p=p->next;p!=NULL;p=p->next)
	{	
		c=0;
		for(q=cap_lista->next;q!=p;q=q->next)
		{
			if(q->key==p->key)
				c++;
		}
		if(c==0) 
			printf("%c ",&p->key);
	}
}

int main() 
{
	node* cap_lista;
	int n, i;
	cap_lista=init();
	printf("Zi cate elemente are lista: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
		add_elem(cap_lista);
		
	write(cap_lista);

	return 0;
}