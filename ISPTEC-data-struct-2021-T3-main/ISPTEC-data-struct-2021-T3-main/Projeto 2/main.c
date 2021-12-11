#include "gm.c"

main()
{	
	LCD * newList = _init();
	char * name;
	int i, n;
	
	printf("Quantos elementos desejas inserir na lista: ");
	scanf("%i", &n);
	
	for(i = 0; i< n; i++)
	{
		fflush(stdin);
		printf("Nome do Soldado (%d): ", i+1);
		gets(name);
		fflush(stdin);
		newList = _insertInStart(newList, name);
	}
	
	printf("\n");
	_print(newList, newList);
	
	newList = _remove(newList);
	
	printf("\n");
	printf("Escolhido: %s", newList->name);
	

	
}
