	.file	"applicationstub.c"
	.globl	logfile
	.data
	.align 16
	.type	logfile, @object
	.size	logfile, 30
logfile:
	.string	"./text-data-files/logfile.txt"
	.comm	fp,8,8
	.comm	processid,4,4
	.section	.rodata
.LC0:
	.string	"Unable to set atexit()"
.LC1:
	.string	"Unable to set atexit()\n"
.LC2:
	.string	"a+"
	.align 8
.LC3:
	.string	"Error with fopen(). Unable to open the application log"
.LC4:
	.string	"Application started.\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	movl	%edi, -164(%rbp)
	movq	%rsi, -176(%rbp)
	movq	$signal_handler, -160(%rbp)
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$2, %edi
	call	sigaction
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$15, %edi
	call	sigaction
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$11, %edi
	call	sigaction
	movl	$bye, %edi
	call	atexit
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L2
	movl	$.LC0, %edi
	call	perror
	movq	fp(%rip), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	print_log_file
	movl	$1, %edi
	call	exit
.L2:
	call	getpid
	movl	%eax, processid(%rip)
	movl	$.LC2, %esi
	movl	$logfile, %edi
	call	fopen
	movq	%rax, fp(%rip)
	movq	fp(%rip), %rax
	testq	%rax, %rax
	jne	.L3
	movl	$.LC3, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L3:
	movl	$0, %eax
	call	print_application_header
	movq	fp(%rip), %rax
	movl	$.LC4, %esi
	movq	%rax, %rdi
	call	print_log_file
	movl	$60000, %edi
	call	sleep
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC5:
	.string	"The process id of this application is: %d\n"
	.align 8
.LC6:
	.string	"Welcome to the application stub.\nThe  purpose of this program "
	.align 8
.LC7:
	.string	"is to build a solid framework \nfor the application development "
.LC8:
	.string	"process."
	.align 8
.LC9:
	.string	"----------------------------------------------------------------"
	.align 8
.LC10:
	.string	"The process name of this process is: %s \n"
	.text
	.globl	print_application_header
	.type	print_application_header, @function
print_application_header:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	processid(%rip), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC8, %edi
	call	puts
	movl	$.LC9, %edi
	call	puts
	movl	processid(%rip), %eax
	movl	%eax, %edi
	call	get_process_name_by_pid
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	printf
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	print_application_header, .-print_application_header
	.section	.rodata
.LC11:
	.string	"%c"
.LC12:
	.string	"%s %s \n"
	.text
	.globl	print_log_file
	.type	print_log_file, @function
print_log_file:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$144, %rsp
	movq	%rdi, -136(%rbp)
	movq	%rsi, -144(%rbp)
	movl	$0, %edi
	call	time
	movq	%rax, -120(%rbp)
	leaq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	localtime
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rcx
	movl	$.LC11, %edx
	movl	$100, %esi
	movq	%rax, %rdi
	call	strftime
	movq	-144(%rbp), %rcx
	leaq	-112(%rbp), %rdx
	movq	-136(%rbp), %rax
	movl	$.LC12, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	fflush
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	print_log_file, .-print_log_file
	.section	.rodata
	.align 8
.LC13:
	.string	"Received SIGINT from process with pid = %u \n"
	.align 8
.LC14:
	.string	"Received signal SIGINT and will be shutting down application.c "
	.align 8
.LC15:
	.string	"Received SIGSEGV from process with pid = %u \n"
	.align 8
.LC16:
	.string	"Received signal SIGSEGV and will be shutting down application.c "
	.align 8
.LC17:
	.string	"Received SIGTERM from process with pid = %u \n"
	.align 8
.LC18:
	.string	"Received signal SIGTERM and will be shutting down application.c"
	.text
	.globl	signal_handler
	.type	signal_handler, @function
signal_handler:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movl	-4(%rbp), %eax
	cmpl	$11, %eax
	je	.L9
	cmpl	$15, %eax
	je	.L10
	cmpl	$2, %eax
	jne	.L12
	movq	-16(%rbp), %rax
	movl	16(%rax), %edx
	movq	stdout(%rip), %rax
	movl	$.LC13, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$.LC14, %esi
	movl	$3, %edi
	movl	$0, %eax
	call	syslog
	movl	$1, %edi
	call	exit
.L9:
	movq	-16(%rbp), %rax
	movl	16(%rax), %edx
	movq	stdout(%rip), %rax
	movl	$.LC15, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$.LC16, %esi
	movl	$3, %edi
	movl	$0, %eax
	call	syslog
	movl	$1, %edi
	call	exit
.L10:
	movq	-16(%rbp), %rax
	movl	16(%rax), %edx
	movq	stdout(%rip), %rax
	movl	$.LC17, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$.LC18, %esi
	movl	$3, %edi
	movl	$0, %eax
	call	syslog
	movl	$1, %edi
	call	exit
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	signal_handler, .-signal_handler
	.section	.rodata
.LC19:
	.string	"/proc/%d/cmdline"
.LC20:
	.string	"r"
	.text
	.globl	get_process_name_by_pid
	.type	get_process_name_by_pid, @function
get_process_name_by_pid:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movl	$1, %esi
	movl	$1024, %edi
	call	calloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L14
	movl	-36(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	$.LC19, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf
	movq	-8(%rbp), %rax
	movl	$.LC20, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L14
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rcx
	movl	$1024, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	fread
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L15
	movq	-24(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$10, %al
	jne	.L15
	movq	-24(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
.L15:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
.L14:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	get_process_name_by_pid, .-get_process_name_by_pid
	.section	.rodata
	.align 8
.LC21:
	.string	"The program is now shutting down."
	.align 8
.LC22:
	.string	"The application has ended now \n"
	.text
	.globl	bye
	.type	bye, @function
bye:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC21, %edi
	call	puts
	movq	fp(%rip), %rax
	movq	%rax, %rcx
	movl	$31, %edx
	movl	$1, %esi
	movl	$.LC22, %edi
	call	fwrite
	movq	fp(%rip), %rax
	movq	%rax, %rdi
	call	fclose
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	bye, .-bye
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-11)"
	.section	.note.GNU-stack,"",@progbits
