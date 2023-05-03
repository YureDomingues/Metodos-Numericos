//Método da Bissecção

#include <stdio.h>
#include <math.h>

//Função f(x) escrever dentro do return a expressão
double f(double x){
	return(4*pow(x,5)+7*pow(x,2)+4*x+3);
}

int main(void){
	double a, b;
	printf("Digite o valor 'a' do intervalo [a,b]: ");
	scanf("%lf", &a);
	printf("Agora digite o valor 'b' do intervalo [a,b]: ");
	scanf("%lf", &b);

	if(f(a)*f(b)>0){
		printf("Pare! Inicie novamente com outro intervalo de busca.");
	}

	int n=1;
	double x = (a+b)/2;
	double x_old;
	double Er;
	double Ex;
	double e = pow(10, -8);

	do{
		if(f(x)==0){
			printf("Um zero da função foi encontrado em x = %lf", x);
			break;
		}
		n++;

		x_old = x;

		if(f(a)*f(x)<0){
			b=x;
		}else{
			a=x;
		}
		
		x = (a+b)/2;

		if(f(x)<0){
			Er = -f(x);
		}else{
			Er = f(x);
		}

		if( (x-x_old) < 0){
			Ex = -(x-x_old);
		}else{
			Ex = (x-x_old);
		}

		printf("iteração %d: \nx = %.15lf \nEr = %.15lf \nEx = %.15lf\n\n", n-1, x, Er, Ex);

	}while(Er > e && Ex > e);

	printf("Resultado final: \niterações = %d \nx = %.15lf \nEr = %.15lf \nEx = %.15lf", n, x, Er, Ex);

	return 0;
}