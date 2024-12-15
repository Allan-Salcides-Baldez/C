#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include<pthread.h>
#include <sys/shm.h> // shmget
#include <sys/ipc.h> // ???
//#include <sys/itc.h>



int main(void){

  //sem_t mutex;
  sem_t *semf1;
  sem_t *semf2;
  sem_t *semf3;  
  semf1 = sem_open ("/semf1", O_EXCL, 0644, 1);
  semf2 = sem_open ("/semf2", O_EXCL, 0644, 1);
  semf3 = sem_open ("/semf3", O_EXCL, 0644, 1);  
  //sem_init(&semp, 0, 1); 
  pid_t pid1, pid2, pid3;
  pid1 = fork();
 
  if(pid1 == 0) {
    sem_wait(semf1);
    puts("Processo filho 1 arrancou...");
    printf("Processo filho 1 - pid: %d / pai: %d\n", getpid(), getppid());
    pthread_t thread_id[0]; //identificadores das threads
                           
    //sem_post(semf1);
    sleep(4);
    puts("Processo filho 1 terminou.");
  }
  else{
    pid2 = fork();
 
    if(pid2 == 0){
      sem_wait(semf2);      
      puts("Processo filho 2 arrancou...");
      printf("Processo filho 2 - pid: %d / pai: %d\n", getpid(), getppid());
      //sem_post(semf2);     
      sleep(1);
      puts("Processo filho 2 terminou.");
    }
    else{    
      pid3 = fork();
  
      if(pid3 == 0){
        sem_wait(semf3);        
        puts("Processo filho 3 arrancou...");
        printf("Processo filho 3 - pid: %d / pai: %d\n", getpid(), getppid());
        //sem_post(semf3);        
        sleep(1);
        puts("Processo filho 3 terminou.");
      }
      else{

          puts("Processo pai");
          printf("Processo pai - pid: %d / filho 1: %d / filho 2: %d / filho 3: %d\n", getpid(), pid1, pid2, pid3);
          sem_post(semf1);  
          sem_post(semf2);
          sem_post(semf3);  
          sem_close(semf1);
          sem_close(semf2);
          sem_close(semf3);                    
          sem_unlink("/semf1");
          sem_unlink("/semf2");
          sem_unlink("/semf3");                            
          waitpid(pid1, NULL, 0);
          waitpid(pid2, NULL, 0);
          waitpid(pid3, NULL, 0);            
          puts("Fim");
      }    
    } 
  }
 
  return 0;
}
