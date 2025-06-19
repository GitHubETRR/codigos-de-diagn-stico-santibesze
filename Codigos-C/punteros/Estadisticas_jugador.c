#include <stdio.h>


#define MAX_CHAR 20


typedef struct 
{
    char nombre_jugador[MAX_CHAR];
    char apellido_jugador[MAX_CHAR];
    int goles;
    int asistencias;
    int amarillas;
    int rojas;
    int partidos_jugados;
    float prom_asistencias;
    float prom_goles;
    float prom_amarillas;
    float prom_rojas;
    int GA;
}jugador_t;


jugador_t Jugador();
jugador_t StatsAvanzadas(jugador_t jugador);
void ImprimirEstadisticas(jugador_t jugador);


int main(){
    jugador_t jugador = Jugador();
    jugador = StatsAvanzadas(jugador);
    void ImprimirEstadisticas(jugador_t jugador);
}



jugador_t Jugador() {
    jugador_t jugador;
    printf("Cual es el nombre del jugador\n");
    scanf("%s", jugador.nombre_jugador);
    printf("Cual es el apellido del jugador?\n");
    scanf("%s", jugador.apellido_jugador);
    printf("Cuantos goles anoto %s %s?\n",jugador.nombre_jugador, jugador.apellido_jugador);
    scanf(" %d", &jugador.goles);
    printf("Cuantas asistencias dio %s %s'\n",jugador.nombre_jugador, jugador.apellido_jugador);
    scanf("%d", &jugador.asistencias);
    printf("Cuantas amarillas tiene %s %s?\n",jugador.nombre_jugador, jugador.apellido_jugador);
    scanf("%d",&jugador.amarillas);
    printf("Cuantas rojas tiene %s %s?\n",jugador.nombre_jugador, jugador.apellido_jugador);
    scanf("%d", &jugador.rojas);
    printf("Cuantos partidos jugó %s %s?\n",jugador.nombre_jugador, jugador.apellido_jugador);
    scanf("%d", &jugador.partidos_jugados);
    return jugador;
}

jugador_t StatsAvanzadas(jugador_t jugador){
    jugador.GA = jugador.asistencias + jugador.goles;
    if (jugador.partidos_jugados != 0)
    {
        jugador.prom_asistencias = (float)jugador.asistencias / jugador.partidos_jugados;
        jugador.prom_goles = (float)jugador.goles / jugador.partidos_jugados;
        jugador.prom_amarillas = (float)jugador.amarillas / jugador.partidos_jugados;
        jugador.prom_rojas = (float)jugador.rojas / jugador.partidos_jugados;
    }
    else{
        jugador.prom_asistencias = 0;
        jugador.prom_goles = 0;
        jugador.prom_amarillas = 0;
        jugador.prom_rojas = 0;
    }
    return jugador;
}
void ImprimirEstadisticas(jugador_t jugador){
    printf("Las estadisticas de %s %s:\n",jugador.nombre_jugador,jugador.apellido_jugador);
    printf("Partidos jugados: %d\n",jugador.partidos_jugados);
    printf("Goles totales: %d\n",jugador.goles);
    printf("Asitencias totales: %d\n", jugador.asistencias);
    printf("Goles+Asistencias: %d\n",jugador.GA);
    printf("Promedio de goles por partido: %.2f\n", jugador.prom_goles);
    printf("Promedio de asistencias por partido: %.2f\n", jugador.prom_asistencias);
    printf("Promedio de amarilas por partido: %.2f\n", jugador.prom_amarillas);
    printf("Promedio de rojas por partido: %.2f\n", jugador.prom_rojas);
}