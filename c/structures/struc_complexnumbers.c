/*****************************
Juan Carlos Carrasco López

struct.c

Crea una estructura para el manejo de números complejos e implemente una función para cada operación
básica con números complejos (suma, resta, multiplicación y división).

Cada función recibe como parámetros estructuras del tipo complejo y regresa como resultado
otra estructura de tipo complejo

******************************/
#include<stdio.h>
#include <stdlib.h>

struct complejo
{
float x;
float y;
};
typedef struct complejo Complejo;

Complejo suma( Complejo, Complejo);
Complejo resta(Complejo z1,Complejo z2);
Complejo producto( Complejo, Complejo);
Complejo division(Complejo,Complejo);
Complejo leer_complejo (void);
void escribir_complejo(Complejo);

int main()
{
        Complejo z,z1,z2;
        z1= leer_complejo();
        z2= leer_complejo();
        z= suma(z1,z2);
        printf("\n");
        printf("La suma es: \n");
        escribir_complejo(z);
        printf("\n");
        z= resta(z1,z2);
        printf("La resta es: \n");
        escribir_complejo(z);
        printf("\n");
        z=producto (z1,z2);
        printf("El producto es: \n");
        escribir_complejo(z);
        printf("\n");
        z=division(z1,z2);
        printf("La division es: \n");
        escribir_complejo(z);
        printf("\n");

    return 0;
}

Complejo leer_complejo(void)
{
Complejo z;
printf("Introduce la parte real del complejo: ");
scanf("%f",&z.x);
printf("Introduce la parte imaginaria del complejo: ");
scanf("%f",&z.y);
return z;
}

void escribir_complejo(Complejo z)
{
printf ("El numero complejo es: (%f ,%f) \n",z.x,z.y);
return;
}

Complejo suma(Complejo z1,Complejo z2)
{
Complejo z;
z.x =z1.x + z2.x;
z.y =z1.y + z2.y;
return z;
}

Complejo resta(Complejo z1,Complejo z2)
{
Complejo z;
z.x =z1.x - z2.x;
z.y =z1.y - z2.y;
return z;
}


Complejo producto (Complejo z1, Complejo z2)
{
Complejo z;
z.x= (z1.x *z2.x) -( z1.y * z2.y);
z.y= (z1.x *z2.y) +( z1.y * z2.x);
return z;
}

Complejo division (Complejo z1, Complejo z2)
{
Complejo z;
float den;
den = z2.x * z2.x + z2.y * z2.y;
z.x = ((z1.x * z2.x) + ( z1.y * z2.y))/den;
z.y = ((-z1.x * z2.y) + (z1.y * z2.x))/den;
return z;
}


