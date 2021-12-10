#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no LCD;

LCD  * _init ();
LCD  * _insertInStart( LCD * l, char * name );
LCD  * _remove( LCD * l);

char * _sortName( LCD * l );

void _print( LCD * l, LCD * start);
void _destroy( LCD * l);



