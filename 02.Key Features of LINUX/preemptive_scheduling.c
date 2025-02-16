#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <time.h>

void perform_task() {
    long long int i;
    for (i = 0; i < 10000000000; i++); // Simple loop to consume time
}

int main() {
    pid_t pid1, pid2;
    clock_t start, end;
    double cpu_time_used;

    // Create first child process
    pid1 = fork();
    if (pid1 == 0) {
        // In child process 1
        start = clock();
        printf("Child 1 PID: %d, Priority: %d\n", getpid(), getpriority(PRIO_PROCESS, 0));
        nice(10); // Increase nice value by 10
        printf("Child 1 new Priority: %d\n", getpriority(PRIO_PROCESS, 0));
        perform_task(); // Perform the task
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Child 1 elapsed time: %f seconds\n", cpu_time_used);
        exit(0);
    } else {
        // Create second child process
        pid2 = fork();
        if (pid2 == 0) {
            // In child process 2
            start = clock();
            printf("Child 2 PID: %d, Priority: %d\n", getpid(), getpriority(PRIO_PROCESS, 0));
            nice(-10); // Decrease nice value by 10
            printf("Child 2 new Priority: %d\n", getpriority(PRIO_PROCESS, 0));
            perform_task(); // Perform the task
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Child 2 elapsed time: %f seconds\n", cpu_time_used);
            exit(0);
        } else {
            // In parent process
            printf("Parent PID: %d\n", getpid());
            wait(NULL); // Wait for child processes to finish
            wait(NULL); // Wait for child processes to finish
        }
    }

    return 0;
}
