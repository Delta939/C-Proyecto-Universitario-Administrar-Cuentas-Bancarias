#include "cuenta.h"
main(){
     int opcion=0; int n;
    cuenta *inicio= NULL; 
   do{system("cls");
      menu();
      printf("\n opcion=");
      scanf("%d", &opcion);
      switch(opcion){
         case 1: inicio=(cuenta *)menu2(inicio);   //menu2(inicio); 
                 break;
         case 2: id(inicio);  // inicio=(cuenta *)id(inicio); 
                 break;
         case 3: guardarListaTexto(inicio);
                 printf("\n Au Revoir "); 
                  break;        
                                                                        
         default: printf("\n Opcion incorrecta\n");
                 break;                 
      }
                   
   }while(opcion!=3);
   printf("\n \n");
      system("pause");  
}
