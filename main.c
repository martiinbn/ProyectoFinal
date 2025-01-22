#include <stdio.h>

int main(int argc, char *argv[])
{

    float tarifa = 0, distancia = 0, costo, pago, cambio, t1 = 0, d1 = 0;
    int opc, opc2;
    int c1, c2, c5, c05, c01, c005, c001, ce;

    do
    {
        printf("1. Ingresar distancia en km\n");
        printf("2. Ingresar tarifa por km\n");
        printf("3. Calculo costo boleto\n");
        printf("4. Calculo cambio\n");
        printf(">> ");
        scanf("%d", &opc2);

        switch (opc2)
        {
        case 1:
            do
            {
                printf("Ingrese la distancia en km: ");
                scanf("%f", &distancia);

                if (distancia <= 0)
                {
                    printf("ERROR. Debe ingresar un valor superior a cero\n");
                }
            } while (distancia <= 0);

            d1 = distancia;
            break;

        case 2:
            do
            {
                printf("Ingrese la tarifa (en pesos) por km: ");
                scanf("%f", &tarifa);

                if (tarifa <= 0)
                {
                    printf("ERROR. Debe ingresar un valor superior a cero\n");
                }
            } while (tarifa <= 0);

            t1 = tarifa;
            break;

        case 3:
            distancia = d1;
            tarifa = t1;

            if (distancia == 0 || tarifa == 0)
            {
                printf("ERROR. Primero debe ingresar la distancia y tarifa\n");
            }
            else
            {
                costo = distancia * tarifa;

                printf("El costo del boleto es: %.2f\n", costo);
            }
            break;

        case 4:
            if (distancia == 0 || tarifa == 0)
            {
                printf("ERROR. Primero debe ingresar la distancia y tarifa\n");
            }
            else
            {
                do
                {
                    printf("Ingrese el monto total pagado: ");
                    scanf("%f", &pago);

                    if (pago < costo)
                    {
                        printf("ERROR. Debe ingresar un valor igual o superior al costo\n");
                    }
                } while (pago < costo);

                cambio = pago - costo;

                if (pago > costo)
                {
                    ce = cambio * 100;
                    c5 = ce / 500;
                    ce %= 500;
                    c2 = ce / 200;
                    ce %= 200;
                    c1 = ce / 100; 
                    ce %= 100;
                    c05 = ce / 50;
                    ce %= 50;
                    c01 = ce / 10;
                    ce %= 10;
                    c005 = ce / 5;
                    ce %= 5;
                    c001 = ce / 1;
                    ce %= 1;

                    printf("Su cambio es de: %.2f\n", cambio);
                    printf("El cambio se entrega con %d monedas de 5, %d monedas de 2, %d monedas de 1, %d monedas de 50 centavos, %d monedas de 10 centavos, %d monedas de 5 centavos y %d monedas de 1 centavo\n", c5, c2, c1, c05, c01, c005, c001);
                }

                if (pago == costo)
                {
                    printf("Su cambio es de: %.2f\n", cambio);
                }
            }
            break;

        default:
            printf("ERROR. Debe escoger una de las 4 opciones\n");
            break;
        }

        printf("Desea ingresar otra opcion?\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf(">> ");
        scanf("%d", &opc);
    } while (opc == 1);

    printf("RESUMEN\n");
    printf("El costo del boleto es: %.2f\n", costo);
    printf("El monto pagado es: %.2f\n", pago);
    printf("El cambio entregado es: %.2f\n", cambio);
    
    return 0;
    }