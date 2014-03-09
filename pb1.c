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
	printf("zi litera: ");
	scanf("%c",&p->key);
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
	p->next=q;
}

int main() 
{
	node* cap_lista;
	int n, i;
	cap_lista=init();
	printf("Zi cate elemente are lista: ");
	scanf("%d", &n);
	for(i=1;i<n;i++)
		add_elem(cap_lista);


	return 0;
}