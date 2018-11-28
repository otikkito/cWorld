	.file	"applicationstub.c"
	.text
	.globl	_logfile
	.data
	.align 4
_logfile:
	.ascii "./text-data-files/logfile.txt\0"
	.comm	_fp, 4, 2
	.comm	_processid, 4, 2
	.comm	_cd, 1, 0
	.comm	_start_time, 8, 2
	.comm	_elapsed_time, 8, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "clock_gettime\0"
LC1:
	.ascii "Unable to set atexit()\0"
LC2:
	.ascii "a+\0"
	.align 4
LC3:
	.ascii "Error with fopen(). Unable to open the application log\0"
LC4:
	.ascii "Application started.\0"
	.align 4
LC5:
	.ascii "Successfully read the configuration file.\0"
LC6:
	.ascii "Application terminated.\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$_start_time, 4(%esp)
	movl	$4, (%esp)
	call	_clock_gettime
	movl	%eax, 28(%esp)
	cmpl	$-1, 28(%esp)
	jne	L2
	movl	$LC0, (%esp)
	call	_perror
	movl	$1, (%esp)
	call	_exit
L2:
	movl	$_bye, (%esp)
	call	_atexit
	movl	%eax, 28(%esp)
	cmpl	$0, 28(%esp)
	je	L3
	movl	$LC1, (%esp)
	call	_perror
	movl	_fp, %eax
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	movl	$1, (%esp)
	call	_exit
L3:
	call	_getpid
	movl	%eax, _processid
	movl	$LC2, 4(%esp)
	movl	$_logfile, (%esp)
	call	_fopen
	movl	%eax, _fp
	movl	_fp, %eax
	testl	%eax, %eax
	jne	L4
	movl	$LC3, (%esp)
	call	_perror
	movl	$1, (%esp)
	call	_exit
L4:
	call	_printApplicationHeaderToConsole
	movl	_fp, %eax
	movl	$LC4, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	call	_readConfigurationFile
	movl	%eax, 24(%esp)
	cmpl	$0, 24(%esp)
	jne	L5
	movl	_fp, %eax
	movl	$LC5, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
L5:
	movzbl	_cd, %eax
	testb	%al, %al
	je	L6
	call	_initializeSignalHandles
L6:
	movl	$6000, (%esp)
	call	_sleep
	movl	_fp, %eax
	movl	$LC6, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.section .rdata,"dr"
	.align 4
LC7:
	.ascii "The process id of this application is: %d\12\0"
	.align 4
LC8:
	.ascii "Welcome to the application stub.\12The  purpose of this program \0"
	.align 4
LC9:
	.ascii "is to build a solid framework \12for the application development \0"
LC10:
	.ascii "process.\0"
	.align 4
LC11:
	.ascii "----------------------------------------------------------------\0"
	.align 4
LC12:
	.ascii "The process name of this process is: %s \12\0"
	.text
	.globl	_printApplicationHeaderToConsole
	.def	_printApplicationHeaderToConsole;	.scl	2;	.type	32;	.endef
_printApplicationHeaderToConsole:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_processid, %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC8, (%esp)
	call	_printf
	movl	$LC9, (%esp)
	call	_printf
	movl	$LC10, (%esp)
	call	_puts
	movl	$LC11, (%esp)
	call	_puts
	movl	_processid, %eax
	movl	%eax, (%esp)
	call	_getProcessNameByPid
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.section .rdata,"dr"
LC13:
	.ascii "r\0"
LC14:
	.ascii "applicationstub.conf\0"
	.align 4
LC15:
	.ascii "Unable to open the configuration file.\12\0"
	.align 4
LC16:
	.ascii "Unable to open the configuration file for the applicationstub.c\0"
LC17:
	.ascii "%s = %s\0"
LC18:
	.ascii "initialize_signal_handler\0"
	.align 4
LC19:
	.ascii "Unable to close the configuration file.\0"
	.text
	.globl	_readConfigurationFile
	.def	_readConfigurationFile;	.scl	2;	.type	32;	.endef
_readConfigurationFile:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$936, %esp
	movl	$LC13, 4(%esp)
	movl	$LC14, (%esp)
	call	_fopen
	movl	%eax, -12(%ebp)
	movb	$0, _cd
	cmpl	$0, -12(%ebp)
	jne	L13
	movl	$LC15, (%esp)
	call	_perror
	movl	_fp, %eax
	movl	$LC16, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	movl	$1, %eax
	jmp	L19
L17:
	movzbl	-316(%ebp), %eax
	cmpb	$35, %al
	je	L13
	movzbl	-316(%ebp), %eax
	cmpb	$32, %al
	je	L13
	movzbl	-316(%ebp), %eax
	cmpb	$10, %al
	jne	L15
	jmp	L13
L15:
	movl	$300, 8(%esp)
	movl	$0, 4(%esp)
	leal	-916(%ebp), %eax
	movl	%eax, (%esp)
	call	_memset
	movl	$300, 8(%esp)
	movl	$0, 4(%esp)
	leal	-616(%ebp), %eax
	movl	%eax, (%esp)
	call	_memset
	leal	-616(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-916(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC17, 4(%esp)
	leal	-316(%ebp), %eax
	movl	%eax, (%esp)
	call	_sscanf
	movl	$LC18, 4(%esp)
	leal	-916(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L13
	movb	$1, _cd
L13:
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$300, 4(%esp)
	leal	-316(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	testl	%eax, %eax
	jne	L17
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	L18
	movl	$0, %eax
	jmp	L19
L18:
	movl	$LC19, (%esp)
	call	_perror
	movl	$1, %eax
L19:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.section .rdata,"dr"
LC20:
	.ascii "%c\0"
LC21:
	.ascii "%s %s \12\0"
	.text
	.globl	_printLogFile
	.def	_printLogFile;	.scl	2;	.type	32;	.endef
_printLogFile:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$136, %esp
	movl	$0, (%esp)
	call	_time
	movl	%eax, -112(%ebp)
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_localtime
	movl	%eax, 12(%esp)
	movl	$LC20, 8(%esp)
	movl	$100, 4(%esp)
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	_strftime
	movl	12(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-108(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC21, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fflush
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.globl	_initializeSignalHandles
	.def	_initializeSignalHandles;	.scl	2;	.type	32;	.endef
_initializeSignalHandles:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$_signalHandler, -20(%ebp)
	movl	$2, -12(%ebp)
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$3, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$5, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$6, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$9, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$30, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$11, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$31, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$13, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$14, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$15, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$20, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$19, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$17, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$18, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$21, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$22, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$16, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$24, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$25, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$26, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$27, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$28, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$23, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$29, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$12, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$33, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$34, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$35, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$36, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$37, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$38, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$39, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$40, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$41, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$42, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$43, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$44, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$45, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$46, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$47, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$18, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$20, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$21, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$22, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$23, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$24, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$25, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$26, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$27, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$28, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$29, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$30, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$31, (%esp)
	call	_sigaction
	movl	$0, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_sigaction
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.section .rdata,"dr"
	.align 4
LC22:
	.ascii "The application received signal %d from pid: %u with process name %s\0"
	.align 4
LC23:
	.ascii "Received SIGINT from process with pid = %u \12\0"
	.align 4
LC24:
	.ascii "Received signal SIGINT and will be shutting down application.c \0"
	.align 4
LC25:
	.ascii "Received SIGTERM from process with pid = %u \12\0"
	.align 4
LC26:
	.ascii "Received signal SIGTERM and will be shutting down application.c\0"
	.align 4
LC27:
	.ascii "The user has requested to dump debug data\0"
	.text
	.globl	_signalHandler
	.def	_signalHandler;	.scl	2;	.type	32;	.endef
_signalHandler:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$340, %esp
	.cfi_offset 3, -12
	movl	$300, 8(%esp)
	movl	$0, 4(%esp)
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	_memset
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	_getProcessNameByPid
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC22, 4(%esp)
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	_sprintf
	movl	_fp, %eax
	leal	-308(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	movl	8(%ebp), %eax
	cmpl	$15, %eax
	je	L26
	cmpl	$30, %eax
	je	L27
	cmpl	$2, %eax
	je	L28
	jmp	L29
L28:
	movl	12(%ebp), %eax
	movl	8(%eax), %ebx
	call	___getreent
	movl	8(%eax), %eax
	movl	%ebx, 8(%esp)
	movl	$LC23, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
	movl	$LC24, 4(%esp)
	movl	$3, (%esp)
	call	_syslog
	movl	$1, (%esp)
	call	_exit
L26:
	movl	12(%ebp), %eax
	movl	8(%eax), %ebx
	call	___getreent
	movl	8(%eax), %eax
	movl	%ebx, 8(%esp)
	movl	$LC25, 4(%esp)
	movl	%eax, (%esp)
	call	_fprintf
	movl	$LC26, 4(%esp)
	movl	$3, (%esp)
	call	_syslog
	movl	$1, (%esp)
	call	_exit
L27:
	movl	_fp, %eax
	movl	$LC27, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	call	_printDebugInfo
	nop
L29:
	nop
	addl	$340, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.section .rdata,"dr"
LC28:
	.ascii "Kernel\0"
LC29:
	.ascii "Systemd\0"
LC30:
	.ascii "/proc/%d/cmdline\0"
	.text
	.globl	_getProcessNameByPid
	.def	_getProcessNameByPid;	.scl	2;	.type	32;	.endef
_getProcessNameByPid:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$1, 4(%esp)
	movl	$1024, (%esp)
	call	_calloc
	movl	%eax, -12(%ebp)
	cmpl	$0, 8(%ebp)
	jne	L31
	movl	$LC28, %eax
	jmp	L32
L31:
	cmpl	$1, 8(%ebp)
	jne	L33
	movl	$LC29, %eax
	jmp	L32
L33:
	cmpl	$0, -12(%ebp)
	je	L34
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC30, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_sprintf
	movl	$LC13, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fopen
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	je	L34
	movl	-16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1024, 8(%esp)
	movl	$1, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	je	L35
	movl	-20(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$10, %al
	jne	L35
	movl	-20(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
L35:
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
L34:
	movl	-12(%ebp), %eax
L32:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.section .rdata,"dr"
	.align 4
LC31:
	.ascii "This application has an uptime of %d mins and %d seconds\0"
	.text
	.globl	_printApplicationUptime
	.def	_printApplicationUptime;	.scl	2;	.type	32;	.endef
_printApplicationUptime:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$344, %esp
	movl	$_elapsed_time, 4(%esp)
	movl	$4, (%esp)
	call	_clock_gettime
	movl	%eax, -12(%ebp)
	cmpl	$-1, -12(%ebp)
	jne	L37
	movl	$LC0, (%esp)
	call	_perror
	movl	$1, (%esp)
	call	_exit
L37:
	movl	_elapsed_time, %edx
	movl	_start_time, %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	imull	%edx
	leal	(%edx,%ecx), %eax
	sarl	$5, %eax
	movl	%eax, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%ebp)
	movl	_elapsed_time, %edx
	movl	_start_time, %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	imull	%edx
	leal	(%edx,%ecx), %eax
	sarl	$5, %eax
	movl	%eax, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	imull	$60, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC31, 4(%esp)
	leal	-320(%ebp), %eax
	movl	%eax, (%esp)
	call	_sprintf
	movl	_fp, %eax
	leal	-320(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_printDebugInfo
	.def	_printDebugInfo;	.scl	2;	.type	32;	.endef
_printDebugInfo:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$0, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.section .rdata,"dr"
	.align 4
LC32:
	.ascii "The program is now shutting down.\0"
	.align 4
LC33:
	.ascii "The application has ended now.\0"
	.align 4
LC34:
	.ascii "------------------------------\0"
	.text
	.globl	_bye
	.def	_bye;	.scl	2;	.type	32;	.endef
_bye:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC32, (%esp)
	call	_puts
	call	_printApplicationUptime
	movl	_fp, %eax
	movl	$LC33, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	movl	_fp, %eax
	movl	$LC34, 4(%esp)
	movl	%eax, (%esp)
	call	_printLogFile
	movl	_fp, %eax
	movl	%eax, (%esp)
	call	_fclose
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.ident	"GCC: (GNU) 7.3.0"
	.def	_clock_gettime;	.scl	2;	.type	32;	.endef
	.def	_perror;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
	.def	_getpid;	.scl	2;	.type	32;	.endef
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_sleep;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	_sscanf;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_fgets;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_localtime;	.scl	2;	.type	32;	.endef
	.def	_strftime;	.scl	2;	.type	32;	.endef
	.def	_fprintf;	.scl	2;	.type	32;	.endef
	.def	_fflush;	.scl	2;	.type	32;	.endef
	.def	_sigaction;	.scl	2;	.type	32;	.endef
	.def	_sprintf;	.scl	2;	.type	32;	.endef
	.def	___getreent;	.scl	2;	.type	32;	.endef
	.def	_syslog;	.scl	2;	.type	32;	.endef
	.def	_calloc;	.scl	2;	.type	32;	.endef
	.def	_fread;	.scl	2;	.type	32;	.endef
