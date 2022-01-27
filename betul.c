#include <stdio.h>
#include <string.h>
#include "print/print.h"
#include "mult/mult.h"
#include "sum/sum.h"


typedef int (*input_callback_t)(int a, int b);
typedef void (*output_callback_t)(int a);
typedef int ozturk;

typedef struct module1_t
{
	input_callback_t input_callback;
	output_callback_t output_callback;

}module1_t;

module1_t module1;

//typedef enum{
//	SUM = 1,
//	MULT
//}input_function_t;
//
//typedef enum{
//	DEC = 1,
//	HEX
//}output_function_t;

#define SUM '1'
#define MULT '2'

#define DEC '1'
#define HEX '2'

int main()
{

	int a = 0,b =0;
	char choice;
	char prt = 0;


    //choice=getchar();
    //getchar();
    //printf("choice = %d\n",choice);

    //printf("SUM = %d\n",SUM);

	first:
	printf("enter to 1: dec, 2: hex\n");
	scanf("\r");
	scanf("%c",&prt);




	//prt=getchar();
	//printf("prt = %d\n",prt);
	switch(prt){
		case HEX:{
			module1.output_callback = print_hex;
			break;
		}
		case DEC:{
			module1.output_callback = print_dec;
			break;
		}
		default:{
			printf("hatalı seçim yaptınız.\n");
			goto first;
		}
	}

	second:

	printf("enter to 1: sum, 2: mult\n");
	scanf("\r");
	scanf("%c",&choice);


	switch(choice){
		case SUM:{
			module1.input_callback = sum;
			break;
			}
		case MULT:{
			module1.input_callback = mult;
			break;
			}
		default:{
			printf("hatalı seçim yaptınız.\n");
			goto second;
			}
		}



	printf("enter two numbers:\n");
	scanf("%d%d",&a,&b);

	printf("first number :%d\n",a);
	printf("second number %d\n",b);


	int value = module1.input_callback(a,b);
    module1.output_callback(value);

   return (0);
}



