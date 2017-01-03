/* Noah Udofia
*file rmcomment.c
*removes comments
*/

#include <stdio.h>
#include <ctype.h>

#define INCINQ 3            /*inside comment and in quote*/
#define INQOUTC 2          /*inside quote and out of comment*/
#define INCOUTQ 1           /*inside comment and out of quote*/
#define OUTCOUTQ 0          /*out of comment and out of quote*/

int main(void){
int c, nl, nw, nc, state;


state = OUTCOUTQ;
nl=0;
while((c = getchar()) != EOF) {
	nw=0;
	nc=c;
	if (c == '\n'){
		nl++;
		if (state==INQOUTC || state== INCOUTQ){
		printf("Error at line: %d \n", nl);
		state= OUTCOUTQ;
		}
	}
	else if (c== '/'){
		nc= getchar();
		if (nc== '*'){
		
			if (state==INQOUTC){
				state= INQOUTC;
			}
			else if (state==INCOUTQ){
				state= INCOUTQ;
			}
			else if (state==OUTCOUTQ){
				state= INCOUTQ;
			}
		}
	}
	else if (c=='*'){
		nc= getchar();
		if (nc== '/'){
			if (state==INCINQ){
				state= INQOUTC;
			}
			else if (state==INCOUTQ){
				state= OUTCOUTQ;
				nw=1;
				printf(" ");
			}

		}
	}
	else if (c=='"'){
		if (state==INQOUTC){
			state= OUTCOUTQ;
		}
		else if (state==INCOUTQ){
			state= INCOUTQ;
		}
		else if (state==OUTCOUTQ){
			state= INQOUTC;
		}
	}
	if (state==INQOUTC){
		putchar(c);
		}
	else if (state==OUTCOUTQ){
		if (nw != 1){
			putchar(c);
		if (nc=='/'){
		putchar(nc);
		}
		}
	}
}
return 0;
}

