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
		novo->next =  l;
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
	
	number = rand() % 51 + 1;
	
	printf("%d", number);
	
	while(aux->name != name)
		aux = aux->next;
	
	while(aux->next != aux)
	{
		i = 0;
		while(i != number)
		{
			ptr = ptr->prev;
			i++;
		}
		
		aux2 = ptr; 
		
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		
		ptr = ptr->next;
		 
		printf("Soldado Removido: %s \n", aux2->name);
		
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
	
	printf("%s", aux->name);
	system("pause");
	
	return aux->name;
}

void _print( LCD * l, LCD * start ) {
	
	printf("Imprimir %s\n", l->name);
	
	if( l->next != start )
		_print( l->next,  start );
}

void _destroy( LCD * l){
	free( l );
}



