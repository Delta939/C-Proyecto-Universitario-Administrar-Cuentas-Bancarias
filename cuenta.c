#include "cuenta.h"
void menu(){
      printf("\n MENU PRINCIPAL."); 
      printf("\n 1. Administrar Cuenta.");      
      printf("\n 2. Transaccion");  
      printf("\n 3. Salir");
     }

cuenta* menu2(cuenta *inicio){  
    int opcion;
    do{
      printf("\n-----Administrar Cuenta-----");  
      printf("\n 1. Alta.");  
      printf("\n 2. Modificar Cuenta");
      printf("\n 3. Borrar Cuenta");    
      printf("\n 4. Salir ");       //Almacenar en disco y en texto guardar
        
      printf("\n Elige una opcion=");
      scanf("%d", &opcion); 
         switch(opcion){
         case 1: inicio=(cuenta *)Alta(inicio);
                 break;
         case 2: modificar(inicio);  //inicio=(cuenta *)modificar(inicio);
                 break;
         case 3: inicio= borrarNodo(inicio);
                 break;                    
         case 4: guardarListaTexto(inicio);
                 printf("\n Au Revoir "); 
                 break;        
         default: printf("\n Opcion incorrecta\n");
                 break;                 
      }
      
    }while(opcion!=4);
    
     return inicio;
}

cuenta* Alta(cuenta *inicio){
cuenta *nuevo;
cuenta *nodoSiguiente;
nuevo=(cuenta *)malloc(sizeof(cuenta));

nuevo->id=999;
//char pass[9]="estrella";  //Cambiar DICIEMBRE  
//strcpy(nuevo->pass,"estrella");    // copea estrella en nuevo->pass

printf("\nNombre=");scanf(" %[^\n]",nuevo->nombre);
printf("\nCurp=");scanf(" %[^\n]",nuevo->curp);
printf("\nRfc=");scanf(" %[^\n]",nuevo->rfc);
printf("\nEdad=");scanf(" %d",&nuevo->edad); 
printf("\ndomicilio=");scanf(" %[^\n]",nuevo->domicilio);
printf("\ntelefono=");scanf(" %[^\n]",nuevo->telefono);                  
printf("\nemail=");scanf(" %[^\n]",nuevo->email);
do{
printf("\nIntroduzca una cantidad para su saldo inicial=");
scanf("%f",&nuevo->saldo); 
if(nuevo->saldo>0){
}else  printf("\nIntroduzca una cantidad POSITIVA para su saldo inicial");
}while(nuevo->saldo<0);
//printf("\n Su numero de Cuenta es: %d y su password es: %s ",nuevo->id, nuevo->pass);
printf("\n Su numero de Cuenta es: %d",nuevo->id);
printf("\nTeclee su password(debe contener 4 caracteres): ");

char passi[4];
 int cont; 
for (cont=0; cont<=4;
 cont++)   
{ 
if (cont<4)
{ 
passi[cont]=getch(); 
printf("*"); 
} 
else passi[cont]='\0';
}     

strcpy(nuevo->pass,passi);// copea lo que introduzca el usuario en nuevo->pass

printf("\n Password:%s \n ",nuevo->pass);
system("pause");
system("cls");
      nuevo->sig=NULL;
      if (inicio== NULL){
       inicio= nuevo;
   }else{ nodoSiguiente=inicio;
   while(nodoSiguiente->sig != NULL ){
         nodoSiguiente=nodoSiguiente->sig;                      
    }
      nodoSiguiente->sig=nuevo; 
   }   return inicio;
}


void menudetransacciones(){
      printf("\n TRANSACCION."); 
      printf("\n 1. Deposito.");      
      printf("\n 2. Retiro");  
      printf("\n 3. Consultar saldo");
      printf("\n 4. Reporte");
      printf("\n 5. Salir");
      
}

void password(cuenta *inicio){
cuenta *nuevo;
nuevo=inicio;     
     int idu=0;
     char passu[4];
do{
     printf("\n Introduce tu Id:");   
      scanf("%d", &idu); 
      printf("\n Introduce tu contraseña:");      
          int cont;     
          for (cont=0; cont<4; cont++)  
          { 
               passu[cont]=getch(); 
               printf("*"); 
          }
             passu[cont]='\0';
          if(strcmp(nuevo->pass,passu)==0){   
    }else printf("password incorrecto");
  }while(nuevo->pass == passu);  
system("\npause");
system("cls");
   
}

void id(cuenta *inicio){
     int opcion;
     printf("\n===Transaccion===");   
   password(inicio); 
   do{ 
      menudetransacciones();
       printf("\n Elige una opcion=");
        scanf("%d", &opcion); 
        switch(opcion){
         case 1:  inicio=(cuenta *)Deposito(inicio); 
                 break;
         case 2: inicio=(cuenta *)Retiro(inicio); 
                 break;
         case 3: ConsultarSaldo(inicio); // inicio=(cuenta *) leerListaTexto(inicio); 
                 break;                    
         case 4: Reporte(inicio);
                 break;   
         case 5:printf("\n Au revoir \n");  guardarListaTexto(inicio);
                 break;         
         default: printf("\n Opcion incorrecta\n");
                 break;  
        }
       
   }while(opcion!=5);
   printf("\n \n");
 system("pause");

}

cuenta* Deposito(cuenta *inicio){
     cuenta *nuevo;cuenta *nodoSiguiente;
     nuevo=inicio;
     int opcion; int exito=0;
     printf("===Deposito===");
     menudeposito();
      printf("\nTeclee la Cantidad que desea depositar: ");
       scanf(" %f",&nuevo->saldod);
       nuevo->saldo=nuevo->saldo+nuevo->saldod;
       printf("\nDeposito Satisfactorio");
      nuevo->sig=NULL;      if (inicio== NULL){       inicio= nuevo;   }else{ nodoSiguiente=inicio;
   while(nodoSiguiente->sig != NULL ){         nodoSiguiente=nodoSiguiente->sig; }
      nodoSiguiente->sig=nuevo; 
   }   return inicio;
}
     void menudeposito(){
      printf("\nUsted Desea Depositar esta Cantidad"); 
      printf("\n50 pesos.");      
      printf("\n100 pesos.");      
      printf("\n200 pesos");  
      printf("\n500 pesos");
      printf("\n1000 pesos");
      printf("\n2000 pesos");
      printf("\n5000 pesos");
      }
     
     
  cuenta* Retiro(cuenta *inicio){
     cuenta *nuevo;cuenta *nodoSiguiente;
      nuevo=inicio;
     int opcion;
     printf("===Retiro===");
      menudeposito();
      do{
      printf("\nTeclee la cantidad que desea Retirar: ");
      scanf(" %f",&nuevo->saldor);
      if(nuevo->saldor<nuevo->saldo){
      nuevo->saldo=nuevo->saldo-nuevo->saldor;
      printf("\nRetiro Satisfactorio");
      }else printf("No puede retirar mas dinero del que dispone");
      }while(nuevo->saldor>nuevo->saldo);
      nuevo->sig=NULL;      if (inicio== NULL){       inicio= nuevo;   }else{ nodoSiguiente=inicio;
   while(nodoSiguiente->sig != NULL ){         nodoSiguiente=nodoSiguiente->sig; }
      nodoSiguiente->sig=nuevo; 
   }   return inicio;
}
     
     
void ConsultarSaldo(cuenta *inicio){
    time_t tiempo;
 char cad[80];
 struct tm *tmPtr;
 tiempo=time(NULL);
 tmPtr=localtime(&tiempo);
 strftime(cad,80,"HORA:%H:%M, FECHA:%d/%m/%Y",tmPtr ); //codigo de la hora
 cuenta *ultimo;                 //Codigo de Consultar saldo
     if(inicio == NULL) 
           printf("\nNO HAY LISTA\n");
    else{  
       ultimo=inicio; 
       //printf("\nLISTA");
      
     // do{
printf("\n=====CONSULTA DE SALDO===========");                            
printf("\n                   %s ",cad);
printf("\nID: %d",ultimo->id);   // 
printf("\nNombre: %s",ultimo->nombre);  
printf("\n=================================");
printf("\nSu Saldo es: %.2f", ultimo->saldo );
printf("\n=================================");         
         
         ultimo=ultimo->sig;
    //  }while(ultimo != NULL );
    } 
}  
void Reporte(cuenta *inicio){
     time_t tiempo;
 char cad[80];
 struct tm *tmPtr;
 tiempo=time(NULL);
 tmPtr=localtime(&tiempo);
  strftime(cad,80,"HORA:%H:%M, FECHA:%d/%m/%Y",tmPtr ); //Codigo de la Hora
 cuenta *ultimo;    //  Codigo de Reporte
     if(inicio == NULL) 
           printf("\nNO HAY LISTA\n");
    else{  
       ultimo=inicio; 
       //printf("\nLISTA");
   // do{
printf("\n=====REPORTE===================="); 
printf("\n                  %s ",cad);
printf("\nID: %d",ultimo->id);   
printf("\nNombre: %s",ultimo->nombre);     
printf("\n=====Concepto==================");       
printf("\nDeposito: %.2f", ultimo->saldod);  
printf("\nRetiro: %.2f", ultimo->saldor);  
printf("\nSaldo: %.2f", ultimo->saldo);
printf("\n================================");         
         
         ultimo=ultimo->sig;
     // }while(ultimo != NULL );
    } 
}  
void guardarListaTexto(cuenta *inicio){
   FILE *pf;
   cuenta *ultimo;
   if(inicio !=NULL){
      pf=fopen("datos.txt", "w");   //modo escritura
      if(pf==NULL)
              printf("\n NO ES POSIBLE ALMACENAR\n");        
      else{
       ultimo=inicio;                    
       printf("\n LISTA GUARDADA\n");
                    
          fprintf(pf,"%s\n",ultimo->nombre);
          fprintf(pf,"%d\n",ultimo->id);
          fprintf(pf,"%s",ultimo->pass);
          fprintf(pf,"%s", ultimo->telefono);
          fprintf(pf,"\n%s",ultimo->domicilio); 
          fprintf(pf,"\n%d",ultimo->edad);
          fprintf(pf,"\n%.2f",ultimo->saldo);
          fprintf(pf,"\n%.2f",ultimo->saldod);
          fprintf(pf,"\n%.2f",ultimo->saldor);
          fprintf(pf,"\n%s",ultimo->curp);
          fprintf(pf,"\n%s",ultimo->rfc);
          fprintf(pf,"\n%s",ultimo->email);
           
        
      fclose(pf);
     }
   }else 
      printf("No Hay información para almacenar");
}


cuenta* leerListaTexto(cuenta *inicio){
   FILE *pf;
   cuenta *nuevo,*ultimo;
   pf=fopen("datos.txt", "r");     // modo lectura
   if(pf== NULL)
     printf("\n NO ES POSIBLE LEER\n");        
   else{                        
        nuevo= (cuenta *)malloc(sizeof(cuenta));
        // fscanf(pf, " %lf", &nuevo->promG ); 
         fscanf(pf,"%[^\n]",nuevo->nombre);
          fscanf(pf,"%d",&ultimo->id);
        fscanf(pf,"%s",ultimo->pass); 
         fscanf(pf,"%[^\n]",nuevo->telefono); 
         fscanf(pf,"%[^\n]",nuevo->domicilio);
          fscanf(pf,"%d", &nuevo->edad);
          fscanf(pf,"%f", &nuevo->saldo);    
        fscanf(pf,"%f", &nuevo->saldod);                
        fscanf(pf,"%f", &nuevo->saldor); 
        fscanf(pf,"%s",ultimo->curp);
        fscanf(pf,"%s",ultimo->rfc);
        fscanf(pf,"%[^\n]",nuevo->email);
              
        nuevo->sig =NULL;       
        inicio= nuevo;
        ultimo=nuevo;
        do{
           nuevo= (cuenta *)malloc(sizeof(cuenta));
           fscanf(pf,"%[^\n]",nuevo->nombre);
           if (!feof(pf)){                              //si no es fin de archivo sigo leyendo
               fscanf(pf,"%[^\n]",nuevo->nombre);
          fscanf(pf,"%d",&ultimo->id);
        fscanf(pf,"%s",ultimo->pass); 
         fscanf(pf,"%[^\n]",nuevo->telefono); 
         fscanf(pf,"%[^\n]",nuevo->domicilio);
          fscanf(pf,"%d", &nuevo->edad);
          fscanf(pf,"%f", &nuevo->saldo);    
        fscanf(pf,"%f", &nuevo->saldod);                
        fscanf(pf,"%f", &nuevo->saldor); 
        fscanf(pf,"%s",ultimo->curp);
        fscanf(pf,"%s",ultimo->rfc);
        fscanf(pf,"%[^\n]",nuevo->email);
                         
              nuevo->sig =NULL;
              ultimo->sig=nuevo;
              ultimo=nuevo;
           }else
              free(nuevo);   //si no hay informacion libero la memoria 
        }while(!feof(pf));      //si es fin de archivo termina
        fclose(pf);               //cierro el archivo
   }
   return inicio;
}

void modificar(cuenta *inicio){  
  cuenta *nuevo;
   cuenta *nodoSiguiente;
  nuevo=inicio;
  int opcion;
  int exito=0;
    int idb;
      
  printf("\n Introduce el id que quieres modificar: ");
     scanf("%d",&idb);
     
      do{           
        if(idb == nuevo->id){  
              printf("\n-----Id:-----");
              printf("\n-----%d------",nuevo->id);
            menuparamodificar();
              printf("\n Introduce el numero del Campo que quieres cambiar: ");
              scanf("%d",&opcion);
              switch(opcion) {
              case 1: printf("\n    Nombre=");
                      scanf(" %[^\n]",nuevo->nombre);
                      exito=1;
                      break;
              case 2: printf("\n Modifica   Password");
                      passwordparamodificar(inicio);
                      exito=1;   
                      break;
              case 3: printf("\n    RFC=");
                      scanf(" %[^\n]",nuevo->rfc);
                      exito=1;
                      break;
              case 4: printf("\n Curp=");
                      scanf(" %[^\n]",nuevo->curp);
                      break;
              case 5: printf("\n    telefono=");
                      scanf(" %[^\n]",nuevo->telefono);                  
                      exito=1;
                      break;
              case 6: printf("\n    domicilio=");
                      scanf(" %[^\n]",nuevo->domicilio);
                      exito=1;
                      break;
              case 7: printf("\n    Edad=");
                      scanf("%d",&nuevo->edad);             
                      exito=1;
                      break;
              case 8:  printf("\n    email=");
                      scanf(" %[^\n]",nuevo->email);
                      exito=1;
                      break;
              case 9: guardarListaTexto(inicio);
                        printf("\n Au revoir \n");
                        exito=1;
                      break;
              default: printf("\n Opcion incorrecta\n");
                       break;                 
             }
              
          }   
   }while(opcion!=9);
  printf("\n\n");
  system("pause");
}


void passwordparamodificar(cuenta *inicio){
  cuenta *nuevo; nuevo=inicio;
  int cont;char passm[4];
  
     printf("\n Introduce tu contraseña para modificar :"); 
          for (cont=0; cont<4; cont++)  
          { 
            passm[cont]=getch(); 
            printf("*"); 
          }     
          passm[cont]='\0';
         // printf("Password m: %s",passm);
          strcpy(nuevo->pass,passm);       
       //  printf("Password Nuevo: %s",nuevo->pass);
        
     
}


                            
void menuparamodificar(){
      printf("\n CAMPOS A MODIFICAR."); 
      printf("\n 1. Nombre."); 
      printf("\n 2. Password");  
      printf("\n 3. RFC"); 
      printf("\n 4. Curp");
      printf("\n 5. Telefono");      
      printf("\n 6. Domicilio");
      printf("\n 7. Edad");
      printf("\n 8. Email");
      printf("\n 9. Salir");
}


cuenta *borrarNodo(cuenta *inicio){
  cuenta *n;
  cuenta *selector;
  cuenta *anterior;
  int exito=0;
  n=inicio;
  int idc;
  printf("\n Introduce el id de la cuenta que desea borrar: ");
  scanf(" %d", &idc);  

  if (inicio !=NULL){          
     anterior=(cuenta *) buscarNodoAnterior(idc,inicio);
     if (anterior==NULL){
        selector= inicio;
        inicio = inicio->sig;
        free(selector);
        printf("\n ***ID INICIAL BORRADA***\n");
     }else{  
        selector=anterior->sig;
        anterior->sig= selector->sig;
        free(selector);
        printf("\n ***ID BORRADA***\n");
     }
  }else   
     printf("\n ***NO Hay lista***\n");
  return inicio;
}
 
 
cuenta *buscarNodoAnterior(int dato, cuenta *inicio){
int exito=0;
cuenta *selector;
cuenta *anterior=NULL;

      if(inicio == NULL)
          printf("\n No hay lista");
      else{
               selector=inicio;
               anterior=NULL;
               do{

                        
                  if (dato == selector->id){
                     exito=1;
                  } else{
                    anterior=selector;
                    selector=selector->sig;
                  }
               }while(selector!=NULL && exito==0);
       }
            //return anterior;
       if(anterior == NULL)
           printf("\n ***Primer elemento hallado***\n");       
       return anterior;
}  


 
