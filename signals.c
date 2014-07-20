#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Future enhancement translate the pid to the process name if possible

void sigterm_handler(int signal, siginfo_t *info, void *_unused)
{
  fprintf(stderr, "Received SIGTERM from process with pid = %u\n",info->si_pid);
  exit(0);
}

int main (void)
{
  struct sigaction action = {
    .sa_handler = NULL,
    .sa_sigaction = sigterm_handler,
    .sa_mask = 0,
    .sa_flags = SA_SIGINFO,
    .sa_restorer = NULL
  };

  sigaction(SIGTERM, &action, NULL);
  sleep(60);

  return 0;
}
