#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>

void perform_task() {
    long long int i;
    for (i = 0; i < 1000000000; i++); // Simple loop to consume time
}

int main() {
    pid_t pid1, pid2;

    // Create first child process
    pid1 = fork();
    if (pid1 == 0) {
        // In child process 1
        printf("Child 1 PID: %d, Priority: %d\n", getpid(), getpriority(PRIO_PROCESS, 0));
        nice(10); // Increase nice value by 10
        printf("Child 1 new Priority: %d\n", getpriority(PRIO_PROCESS, 0));
        perform_task(); // Perform the task
        exit(0);
    } else {
        // Create second child process
        pid2 = fork();
        if (pid2 == 0) {
            // In child process 2
            printf("Child 2 PID: %d, Priority: %d\n", getpid(), getpriority(PRIO_PROCESS, 0));
            nice(-10); // Decrease nice value by 10
            printf("Child 2 new Priority: %d\n", getpriority(PRIO_PROCESS, 0));
            perform_task(); // Perform the task
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
