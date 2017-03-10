#include <stdio.h>
#include <time.h>
#include <sys/types.h> //clockid_t

/*https://gist.github.com/pfigue/9ce8a2c0b14a2542acd7
*/
int main(int argc, char **argv)
{

  int result;
  struct timespec tp;
  clockid_t clk_id;

//  clk_id = CLOCK_REALTIME;
  clk_id = CLOCK_MONOTONIC;
//  clk_id = CLOCK_BOOTTIME;
//  clk_id = CLOCK_PROCESS_CPUTIME_ID;

  // int clock_gettime(clockid_t clk_id, struct timespec *tp);
  result = clock_gettime(clk_id, &tp);
  printf("result: %i\n", result);
  printf("tp.tv_sec: %lld\n", tp.tv_sec);
  printf("tp.tv_nsec: %ld\n", tp.tv_nsec);

  result = clock_getres(clk_id, &tp);
  printf("result: %i\n", result);
  printf("tp.tv_sec: %lld\n", tp.tv_sec);
  printf("tp.tv_nsec: %ld\n", tp.tv_nsec);


}
/*OUTPUT
[root@localhost timing]# ./a.out 
result: 0
tp.tv_sec: 20003
tp.tv_nsec: 886402943
result: 0
tp.tv_sec: 0
tp.tv_nsec: 1

*/


/*
       CLOCK_REALTIME
              System-wide clock that measures real (i.e., wall-clock) time.  Setting this clock requires appropriate privileges.  This clock is affected by discontinuous jumps in the sys‐
              tem time (e.g., if the system administrator manually changes the clock), and by the incremental adjustments performed by adjtime(3) and NTP.
       CLOCK_REALTIME_COARSE (since Linux 2.6.32; Linux-specific)
              A faster but less precise version of CLOCK_REALTIME.  Use when you need very fast, but not fine-grained timestamps.
       CLOCK_MONOTONIC
              Clock that cannot be set and represents monotonic time since some unspecified starting point.  This clock is not affected by discontinuous jumps in the system time (e.g., if
              the system administrator manually changes the clock), but is affected by the incremental adjustments performed by adjtime(3) and NTP.
       CLOCK_MONOTONIC_COARSE (since Linux 2.6.32; Linux-specific)
              A faster but less precise version of CLOCK_MONOTONIC.  Use when you need very fast, but not fine-grained timestamps.
       CLOCK_MONOTONIC
              Clock that cannot be set and represents monotonic time since some unspecified starting point.  This clock is not affected by discontinuous jumps in the system time (e.g., if
              the system administrator manually changes the clock), but is affected by the incremental adjustments performed by adjtime(3) and NTP.
       CLOCK_MONOTONIC_COARSE (since Linux 2.6.32; Linux-specific)
              A faster but less precise version of CLOCK_MONOTONIC.  Use when you need very fast, but not fine-grained timestamps.
       CLOCK_MONOTONIC_RAW (since Linux 2.6.28; Linux-specific)
              Similar to CLOCK_MONOTONIC, but provides access to a raw hardware-based time that is not subject to NTP adjustments or the incremental adjustments performed by adjtime(3).
       CLOCK_BOOTTIME (since Linux 2.6.39; Linux-specific)
              Identical  to CLOCK_MONOTONIC, except it also includes any time that the system is suspended.  This allows applications to get a suspend-aware monotonic clock without having
              to deal with the complications of CLOCK_REALTIME, which may have discontinuities if the time is changed using settimeofday(2).
       CLOCK_PROCESS_CPUTIME_ID (since Linux 2.6.12)
              Per-process CPU-time clock (measures CPU time consumed by all threads in the process).
       CLOCK_THREAD_CPUTIME_ID (since Linux 2.6.12)
              Thread-specific CPU-time clock.
 */
