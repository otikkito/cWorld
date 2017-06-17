#include <stdio.h>
#include <unistd.h>

functionA();
functionB();
functionC();
increment(int *i);
decrement(int *i);

//https://software.intel.com/sites/default/files/managed/39/c5/325462-sdm-vol-1-2abcd-3abcd.pdf

int main(){
	int i=0;
	printf("The size of a int is: %ld bytes\n",sizeof(i));
	for(i=0;;i++){
		if((i > 2147483640) || (i<10)){
			printf("i= %d ",i);
			if(i <0 && i != -2147483648){
			  printf("\n");
			  return 0;
			}
	
		}
	}
	return 0;
}


/*
This function will do the same as what the main function but will indicate if overflow
occurred.
Indication that overflow occurred happens when goes from positive to negative
Return 0 if no over flow occurred and return 1 if overflow occurred
*/
functionA(){
 printf("Now in function A where we will explore option 1\n");
	for(i=0;;i++){

}

//Conclusion overflow happens and does not give a runtime error. In code I will have to check for overflow.
//TODO Find solutions and best practice for overflow protection

/*
/usr/bin/time -v ./a.out 
The size of a int is: 4 bytes
i= 0 i= 1 i= 2 i= 3 i= 4 i= 5 i= 6 i= 7 i= 8 i= 9 i= 2147483641 i= 2147483642 i= 2147483643 i= 2147483644 i= 2147483645 i= 2147483646 i= 2147483647 i= -2147483648 i= -2147483647 
	Command being timed: "./a.out"
	User time (seconds): 4.10
	System time (seconds): 0.00
	Percent of CPU this job got: 100%
	Elapsed (wall clock) time (h:mm:ss or m:ss): 0:04.10
	Average shared text size (kbytes): 0
	Average unshared data size (kbytes): 0
	Average stack size (kbytes): 0
	Average total size (kbytes): 0
	Maximum resident set size (kbytes): 1680
	Average resident set size (kbytes): 0
	Major (requiring I/O) page faults: 0
	Minor (reclaiming a frame) page faults: 130
	Voluntary context switches: 1
	Involuntary context switches: 416
	Swaps: 0
	File system inputs: 0
	File system outputs: 0
	Socket messages sent: 0
	Socket messages received: 0
	Signals delivered: 0
	Page size (bytes): 4096
	Exit status: 0

*/

 /*
  [otikkito@localhost ~]$ cat /proc/cpuinfo 
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 61
model name	: Intel(R) Core(TM) i5-5200U CPU @ 2.20GHz
stepping	: 4
microcode	: 0x24
cpu MHz		: 2333.890
cache size	: 3072 KB
physical id	: 0
siblings	: 4
core id		: 0
cpu cores	: 2
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 20
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx est tm2 ssse3 fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch ida arat epb pln pts dtherm intel_pt tpr_shadow vnmi flexpriority ept vpid fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid rdseed adx smap xsaveopt
bogomips	: 4389.79
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:


*/