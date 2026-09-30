#include <stdio.h>
 
int main (int argc, char *argv[]) {
 
    char ID[5][10], nombre[5][20];
    int stock[5], numVentas, numReabastecer;
    float precio[5], ganancias = 0, total = 0;
    int selP;
    int cantP = 0;

    int opc, opc2;
 
    do{
        printf("Seleccione una opcion:\n");
        printf("1.Registrar producto\n");
        printf("2.Vender producto\n");
        printf("3.Reabastecer producto\n");
        printf("4.Informacion producto\n");
        printf("5.Mostrar ganancias\n");
        printf("6.Salir\n");
        printf(">> ");
        scanf("%d",&opc);
 
        switch (opc)
        {
        case 1:
            printf("Ingrese los datos del producto\n");
            printf("ID: ");
            scanf("%s",&ID[cantP]);
            printf("Nombre: ");
            scanf("%s",&nombre[cantP]);
            printf("Stock: ");
            scanf("%d",&stock[cantP]);
            printf("Precio: ");
            scanf("%f",&precio[cantP]);
            cantP++;
            break;
        case 2:

            printf("Seleccione el numero de producto que desea vender");
            printf("#\t\tId\t\tNombre\t\tStock\t\tPrecio\n");

            for (int i = 0; i < cantP; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",i,ID[i],nombre[i],stock[i],precio[i]);
            }
            printf(">> ");
            scanf("%d",&selP);



            printf("Ingrese las unidades que desea vender: ");
            scanf("%d",&numVentas);
            if (numVentas>stock[selP]){
                printf("Error: No se puede realizar la venta, no existe suficiente stock\n");
                break;
            }
            stock-=numVentas;
            total = numVentas * precio;
            printf("El valor de la venta es: %.2f\n",total);
            printf("El nuevo stock es: %d\n",stock);
            break;
        case 3:
            //printf("Ingrese las unidades que desea reabastecer: ");
            //scanf("%d",&numReabastecer);
            //stock+=numReabastecer;
            //printf("El nuevo stock es: %d\n",stock);
            break;
        case 4:
            printf("Id\t\tNombre\t\tStock\t\tPrecio\n");

            for (int i = 0; i < cantP; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%.2f\n",ID[i],nombre[i],stock[i],precio[i]);
            }
    
            break;
        default:
            break;
        }
 
        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        scanf("%d",&opc2);
    }while(opc2 == 1);
 
   
    return 0;
}