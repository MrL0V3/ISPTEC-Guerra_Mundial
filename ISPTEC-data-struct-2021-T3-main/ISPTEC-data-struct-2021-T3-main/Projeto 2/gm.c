#include "gm_tad.h"

 struct no {
	char name[20];
	struct no * next, *prev;
};

LCD * _init () {
	return NULL;
}

LCD * _insertInStart( LCD * l, char * name )  {
	
	LCD * novo = ( LCD * )malloc( sizeof( LCD ) ) , * aux = l ; 
	
	if( novo == NULL ){
		printf("Memória cheia!\n\n");
		return l;
	}
	
	strcpy(novo->name,name);
	 
	if( l == NULL ){
		novo->next =  novo;
		novo->prev = novo;
		return novo;
	}
	
	
	if( aux->next == l ){
		novo->next = aux;
		novo->prev = aux;
		aux->next = novo;
		aux->prev = novo;
			
	}else {
		
		novo->next = l;
		novo->prev = aux->prev;
		
		aux->prev->next = novo;
		aux->prev = novo;	
	}
	
	
	return novo;
}


LCD  * _remove( LCD * l)
{
	LCD * aux = l, * ptr = l, * aux2 = NULL;
	char * name = _sortName(l);
	int number,i = 0;
	time_t t;
	
	if(strcmp(name," ") == 0)
	{
		printf("Lista Vazia\n");
		return aux;
	}
	
	srand((unsigned) time(&t));
	
	number = rand() % 10 + 1;
	
	//Apresentar Numero Sorteado
	printf("\nNumero Sortedo: %d\n\n", number);
	system("pause");
	
	//Identificar o No do Soldado Sorteado
	while(aux->name != name)
		aux = aux->next;
	
	printf("\n");
	
	while(aux->next != aux) //Verificar Se a Lista Contem Um So Elemento
	{
		i = 0;
		while(i != number)//Contagem Anti-Horaria
		{
			aux = aux->prev;
			i++;
			
			printf("%d - %s\n", i, aux->name);
		}
		
		printf("\n");
		
		system("pause");
		
		
		aux2 = aux; 
		
		printf("\nSoldado Removido: %s\n\n", aux2->name);
		
		aux->prev->next = aux->next;
		aux->next->prev = aux->prev;
		aux = aux->next;
		 
		_destroy(aux2);
	}
	
	return aux;	
}

char * _sortName( LCD * l )
{
	LCD * aux = l;
	char * str;
	int number;
	time_t t;
	
	if(aux == NULL)
	{
		strcpy(str," ");
		printf("Lista Vazia");
		return str;
	}
	
	srand((unsigned) time(&t));
	
	number = rand() % 51 + 1;
	
	while(number != 0)
	{
		aux= aux->next;
		number--;
	}
	
	//Apresentar Nome Sorteado
	printf("\nNome Sorteado: %s\n\n", aux->name);
	
	return aux->name;
}

void _print( LCD * l, LCD * start ) {
	
	printf("%s\n", l->name);
	
	if( l->next != start )
		_print( l->next,  start );
}

void _destroy( LCD * l){
	free( l );
}


