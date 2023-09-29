#include <stdio.h>
#include <signal.h>

void signal_handler(int signum) {
    switch (signum) {
        case SIGINT:
            printf("Received SIGINT (Ctrl+C)\n");
            break;
        case SIGTERM:
            printf("Received SIGTERM\n");
            break;
        case SIGHUP:
            printf("Received SIGHUP\n");
            break;
        // Add more cases for other signals as needed
        default:
            printf("Received signal %d\n", signum);
            break;
    }
}

int main() {
    // Install the signal handler for all signals
    for (int i = 1; i < NSIG; i++) {
        if (i != SIGKILL && i != SIGSTOP) {
            signal(i, signal_handler);
        }
    }

    printf("Signal handler installed. Waiting for signals...\n");

    while (1) {
        // Your application logic here
    }

    return 0;
}
/*
 Standard Signals: https://www.gnu.org/software/libc/manual/html_node/Standard-Signals.html

In C programming, it is not recommended to create a single signal handler that handles all signals indiscriminately because different signals have different meanings and should be handled accordingly. However, you can create a generic signal handler that can catch multiple signals and print a message indicating which signal was received. Here's an example of how you can do this:

```c


In this example:

1. We define a `signal_handler` function that takes an integer argument `signum`, which represents the signal number.
2. In the `main` function, we install the `signal_handler` for all signals except `SIGKILL` and `SIGSTOP`. These two signals cannot be caught or ignored by user programs, so they are excluded.
3. In the `signal_handler` function, we use a `switch` statement to handle specific signals like `SIGINT`, `SIGTERM`, and `SIGHUP` differently, printing a message for each. For all other signals, it prints the signal number.

Keep in mind that handling signals this way might not be appropriate for all situations. It's essential to understand the implications of handling each signal and design your signal handling strategy accordingly for your specific use case.


Logging inside a signal handler is generally not considered safe because signal handlers can interrupt the normal flow of your program, and they run asynchronously with respect to the main program.

Here are a few reasons why logging inside a signal handler is problematic:

Reentrancy: Signal handlers can interrupt the execution of your program at any point, including while the program is in the middle of another operation, such as writing to a file or manipulating data structures. If the signal handler attempts to perform logging operations, it may interfere with other ongoing operations, leading to data corruption or other unexpected behavior.

Asynchronous Signal Delivery: Signals can be delivered asynchronously, and the timing of signal delivery is not under your control. If a signal is delivered while your program is in the middle of another critical operation, logging inside the signal handler can lead to race conditions and unpredictable results.

Reentrancy of Standard Library Functions: Many standard library functions, including those used for logging (e.g., printf), are not reentrant or signal-safe. Calling these functions from a signal handler can lead to undefined behavior or program crashes.

To address these concerns, it's generally recommended to keep signal handlers as simple and deterministic as possible. Instead of performing complex operations like logging directly within a signal handler, it's often better to use the signal handler to set a flag or update a data structure indicating that a signal was received. Then, in your main program, you can periodically check this flag or data structure and perform logging or other actions in a controlled, safe manner.

If you need to perform logging or other I/O operations in response to signals, it's best to use signal handling to set a flag or trigger some other form of synchronization mechanism and then perform the actual logging or I/O operation outside the signal handler, in a controlled and thread-safe context.
*/
