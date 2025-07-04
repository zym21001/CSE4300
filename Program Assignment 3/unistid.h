#ifndef _UNISTD_H_ 
#define _UNISTD_H_ 
#include <sys/types.h> 
/* 
* Get the various constants (flags, codes, etc.) for calls from 
* kernel includes. This way user-level code doesn't need to know 
* about the kern/ headers. 
*/ 
#include <kern/unistd.h> 
#include <kern/ioctl.h> 
/* 
* Prototypes for OS/161 system calls. 
* 
* Note that the following system calls are prototyped in other 
* header files, as follows: 
* 
*     stat:     sys/stat.h 
*     fstat:    sys/stat.h 
*     lstat:    sys/stat.h 
*     mkdir:    sys/stat.h 
* 
* If this were standard Unix, more prototypes would go in other 
* header files as well, as follows: 
*  
*     waitpid:  sys/wait.h 
*     open:     fcntl.h or sys/fcntl.h 
*     reboot:   sys/reboot.h 
*     ioctl:    sys/ioctl.h 
*     remove:   stdio.h 
*     rename:   stdio.h 
*     time:     time.h 
* 
* Also note that the prototypes for open() and mkdir() contain, for 
* compatibility with Unix, an extra argument that is not meaningful 
* in OS/161. This is the "mode" (file permissions) for a newly created 
* object. (With open, if no file is created, this is ignored, and the 
* call prototype is gimmicked so it doesn't have to be passed either.) 
*  
* You should ignore these arguments in the OS/161 kernel unless you're 
* implementing security and file permissions.  
* 
* If you are implementing security and file permissions and using a  
* model different from Unix so that you need different arguments to 
* these calls, you may make appropriate changes, or define new syscalls 
* with different names and take the old ones out, or whatever.  
* 
* As a general rule of thumb, however, while you can make as many new 
* syscalls of your own as you like, you shouldn't change the 
* definitions of the ones that are already here. They've been written 
* to be pretty much compatible with Unix, and the teaching staff has 
* test code that expects them to behave in particular ways. 
* 
* Of course, if you want to redesign the user/kernel API and make a 
* lot of work for yourself, feel free, just contact the teaching 
* staff beforehand. :-) 
* 
* The categories (required/recommended/optional) are guesses - check 
* the text of the various assignments for an authoritative list. 
*/ 
/* 
* NOTE NOTE NOTE NOTE NOTE 
* 
* This file is *not* shared with the kernel, even though in a sense 
* the kernel needs to know about these prototypes. This is because, 
* due to error handling concerns, the in-kernel versions of these 
* functions will usually have slightly different signatures. 
*/ 
#ifdef __GNUC__ 
/* GCC gets into a snit if _exit isn't declared to not return */ 
#define __DEAD __attribute__((__noreturn__)) 
#else 
#define __DEAD 
#endif 
/* Required. */ 
__DEAD void _exit(int code); 
int execv(const char *prog, char *const *args); 
pid_t fork(void); 
int waitpid(pid_t pid, int *returncode, int flags); 
/*  
* Open actually takes either two or three args: the optional third 
* arg is the file mode used for creation. Unless you're implementing 
* security and permissions, you can ignore it. 
*/ 
int open(const char *filename, int flags, ...); 
int read(int filehandle, void *buf, size_t size); 
int write(int filehandle, const void *buf, size_t size); 
int close(int filehandle); 
int reboot(int code); 
int printint(int c); 
int reversestring(char *str,int len); 
int sync(void); 
/* mkdir - see sys/stat.h */ 
int rmdir(const char *dirname); 
/* Recommended. */ 
int getpid(void); 
int ioctl(int filehandle, int code, void *buf); 
int lseek(int filehandle, off_t pos, int code); 
int fsync(int filehandle); 
int ftruncate(int filehandle, off_t size); 
int remove(const char *filename); 
int rename(const char *oldfile, const char *newfile); 
int link(const char *oldfile, const char *newfile); 
/* fstat - see sys/stat.h */ 
int chdir(const char *path); 
/* Optional. */ 
void *sbrk(int change); 
int getdirentry(int filehandle, char *buf, size_t buflen); 
int symlink(const char *target, const char *linkname); 
int readlink(const char *path, char *buf, size_t buflen); 
int dup2(int filehandle, int newhandle); 
int pipe(int filehandles[2]); 
time_t __time(time_t *seconds, unsigned long *nanoseconds); 
int __getcwd(char *buf, size_t buflen); 
/* stat - see sys/stat.h */ 
/* lstat - see sys/stat.h */ 
/* 
* These are not themselves system calls, but wrapper routines in libc. 
*/ 
char *getcwd(char *buf, size_t buflen);  
time_t time(time_t *seconds);  
/* calls __getcwd */ 
/* calls __time */ 
#endif /* _UNISTD_H_ */
