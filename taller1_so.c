#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Recurso compartido
int variable_compartida = 0;

// Mutex para Exclusión Mutua en la variable compartida
pthread_mutex_t mutex_variable;

// Semáforos POSIX para Sincronización de secuencia
sem_t semA_C; // Notifica a C que A escribió Cifra 1
sem_t semC_B; // Notifica a B que C leyó y limpió la variable
sem_t semB_C; // Notifica a C que B escribió Cifra 2

// --- INTEGRANTE 1: Hilo A ---
void* HiloA(void* arg) {
    int cifra_a = 15;
    
    // TO-DO Proteger escritura con Mutex e inicializar variable compartida
    
    
    // TO-DO Notificar a Hilo C
    return NULL;
}

// --- Santiago Perez: Hilo B ---
void* HiloB(void* arg) {
    int cifra_b = 25;
    //Esperar a que Hilo C haya leido Cifra 1 y limpiado la variable

    sem_wait(&semC_B);

    //Proteger escritura con Mutex y actulizar variable compartida

    pthread_mutex_lock(&mutex_variable);
        variable_compartida = cifra_b
        printf("[Hilo B - Dev: Santiago Perez] Escribio cifra 2: %d\n", variable_compartida);

    pthread_mutex_unlock(&mutex_variable);

    //Notificar a Hilo C
    sem_post(&semB_C);


    return NULL;
}

// --- INTEGRANTE 3: Hilo C ---
// --- INTEGRANTE 3: Hilo C ---
void* HiloC(void* arg) {
    int cifra1 = 0, cifra2 = 0;

    // --- PARTE 1: Procesar Cifra 1 ---
    sem_wait(&semA_C); // Esperar a que A escriba

    // Proteger lectura y limpieza con Mutex
    pthread_mutex_lock(&mutex_variable);
    cifra1 = variable_compartida;
    printf("[Hilo C - Dev: Miguel Goncalves] Leyó Cifra 1: %d. Limpiando variable...\n", cifra1);
    variable_compartida = 0;
    pthread_mutex_unlock(&mutex_variable);

    // Dar paso a Hilo B
    sem_post(&semC_B);

    // --- PARTE 2: Procesar Cifra 2 y Consolidar ---
    sem_wait(&semB_C); // Esperar a que B escriba

    // Proteger lectura con Mutex
    pthread_mutex_lock(&mutex_variable);
    cifra2 = variable_compartida;
    printf("[Hilo C - Dev: Miguel Goncalves] Leyó Cifra 2: %d.\n", cifra2);
    pthread_mutex_unlock(&mutex_variable);

    // Renderizado final
    printf("\n================ RENDERIZADO DE RESULTADOS ================\n");
    printf("-> Cifra enviada por Hilo A: %d\n", cifra1);
    printf("-> Cifra enviada por Hilo B: %d\n", cifra2);
    printf("-> SUMA TOTAL CALCULADA POR HILO C: %d\n", cifra1 + cifra2);
    printf("===========================================================\n");

    return NULL;
}
int main(int argc, char *argv[]) {
    pthread_t hA, hB, hC;

    // TO-DO Inicialización de Mutex y Semáforos


    printf("=== INICIO DE LA PRUEBA DE FUEGO ===\n\n");

    // TO-DO Creación de hilos


    // TO-DO Esperar a que terminen


    // TO-DO Destrucción de recursos


    printf("\n=== FIN DE LA EJECUCIÓN ===\n");
    return 0;
}