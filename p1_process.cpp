#include "p1_process.h"

void get_statistics(std::string class_name[], int num_processes, int num_threads) {

	// You need to create multiple processes here (each process
	// handles at least one file.)
	
	
	// Each process should use the sort function which you have defined  		
	// in the p1_threads.cpp for multithread sorting of the data. 
	
	// Your code should be able to get the statistics and / You can use the following code as a template for your code.
  // You can modify the code to suit your needs.
  // You can also use the code as a starting point for your own codeenerate
	// the required outputs for any number of child processes and threads.
	
  int pids[num_processes];
  for(int i=0;i<num_processes;i++) {
    if ((pids[i] = fork()) < 0) {
      perror("Error in forking.\n");
      exit(EXIT_FAILURE);
    }
    else if (pids[i] == 0) {
      std::cout << "Child Process Created. (pid: " << getpid() << ")" <<std::endl;
      // Distributing the amount of files to the amount of processes
      std::cout << "Child Process Ended. (pid: " << getpid() << ")" <<std::endl;
      kill(getpid(), SIGKILL);
    }
    while(wait(NULL) > 0);
  }
}


