#include "gm.c"

main()
{
	//setlocale(LC_ALL,"Portuguese");
	
	LCD * newList = _init();
	char * name;
	int i, n;
	
	printf("Quantos elementos deseja inserir na lista: ");
	scanf("%i", &n);
	
	for(i = 0; i< n; i++)
	{
		fflush(stdin);
		gets(name);
		fflush(stdin);
		newList = _insertInStart(newList, name);
	}
	
	_print(newList, newList);
	
	newList = _remove(newList);
	
	printf("\n");
	
	_print(newList, newList);
	
	

	
}
