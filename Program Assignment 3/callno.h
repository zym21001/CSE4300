#ifndef _KERN_CALLNO_H_ 
#define _KERN_CALLNO_H_ 
/* 
* System call numbers. 
*/ 
/*CALLBEGIN*/ 
#define SYS__exit        
#define SYS_execv        
#define SYS_fork         
0 
1 
2 
#define SYS_waitpid      
#define SYS_open         
3 
4 
#define SYS_read         
#define SYS_write        
#define SYS_close        
#define SYS_reboot       
#define SYS_sync         
#define SYS_sbrk         
#define SYS_getpid       
#define SYS_ioctl        
#define SYS_lseek        
#define SYS_fsync        
5 
6 
7 
8 
9 
10 
11 
12 
13 
14 
#define SYS_ftruncate    15 
#define SYS_fstat        
16 
#define SYS_remove       
#define SYS_rename       
17 
18 
#define SYS_link         
19 
#define SYS_mkdir        
#define SYS_rmdir        
#define SYS_chdir        
20 
21 
22 
#define SYS_getdirentry  23 
#define SYS_symlink      
24 
#define SYS_readlink     25 
#define SYS_dup2         
#define SYS_pipe         
#define SYS___time       
26 
27 
28 
#define SYS___getcwd     29 
#define SYS_stat         
#define SYS_lstat        
30 
31 
#define SYS_printint     32 
#define SYS_reversestring 33 
/*CALLEND*/ 
#endif /* _KERN_CALLNO_H_ */
