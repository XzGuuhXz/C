#include <stdio.h>
#include <stdlib.h>

struct Hora
{
    int Hora;
    int Minutos;
    int Segundos;

};

int main()
{
    system("clear");
    
    struct Hora a[6];
    int i;

    for(i = 0; i < 4; i++)
    {
        printf("Digite a Hora: ");
        scanf("%d", &a[i].Hora);

        printf("Digite os Minutos: ");
        scanf("%d", &a[i].Minutos);

        printf("Digite os Segundos: ");
        scanf("%d", &a[i].Segundos);
        
    }   

    for(i = 0; i < 4; i++)
    {
        if(i == 0)
        {
            a[4].Hora = a[i].Hora;
            a[4].Minutos = a[i].Minutos;
            a[4].Segundos = a[i].Segundos;
        }
        else
        {
            if(a[i].Hora < a[4].Hora)
            {
                a[4].Hora = a[i].Hora;
                a[4].Minutos = a[i].Minutos;
                a[4].Segundos = a[i].Segundos;
            }
            else
            {
                if((a[4].Hora == a[i].Hora) && (a[i].Minutos < a[4].Minutos))
                {
                    a[4].Hora = a[i].Hora;
                    a[4].Minutos = a[i].Minutos;
                    a[4].Segundos = a[i].Segundos;

                }

                else
                {
                    if((a[4].Hora == a[i].Hora) && (a[i].Minutos == a[4].Minutos) && (a[i].Segundos < a[4].Segundos))
                    {
                        a[4].Hora = a[i].Hora;
                        a[4].Minutos = a[i].Minutos;
                        a[4].Segundos = a[i].Segundos;

                    }

                
                }
            }
            
        }
        
    }

    system("clear");

    for(i = 0; i < 4; i++)
    {
        printf("Horas, Minutos e Segundos Cadastrados: \n");
        printf("H:%d\nM:%d\nS:%d\n", a[i].Hora, a[i].Minutos,a[i].Segundos);

    }


    printf("A menor é Hora: \n");
    printf("Hora:%d\nMinutos:%d\nSegundos:%d \n",a[4].Hora,a[4].Minutos,a[4].Segundos);

    a[5].Hora = 0;
    a[5].Minutos = 0;
    a[5].Segundos = 0;
    
    for(i = 0; i < 4; i++)
    {
        a[5].Segundos = a[5].Segundos + a[i].Segundos;
        if(a[5].Segundos >= 60)
        {
            a[5].Minutos ++;
            a[i].Segundos - 60;
        }

        a[5].Minutos = a[5].Minutos + a[i].Minutos;
        if(a[5].Minutos >= 60)
        {
            a[5].Hora ++;
            a[i].Minutos - 60;
        }
        a[5].Hora = a[5].Hora + a[i].Hora;

    
    } 
    
    printf("A soma da horas são: \n");
    printf("Hora:%d\nMinutos:%d\nSegundos:%d \n", a[5].Hora,a[5].Minutos,a[5].Segundos);
    

    return 0;
}