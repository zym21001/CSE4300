#include <types.h> 
#include <kern/unistd.h> 
#include <lib.h> 
#include <syscall.h> 
#include <thread.h> 
#include <curthread.h> 
void _exit(int exitCode) { 
kprintf("Process exiting with code %d\n", exitCode); 
thread_exit();        
// terminates the thread 
} 
int  
sys_printint(int c) { 
kprintf("%d\n", c);  // print the integer given  
 
    // returns 0 if the integer is divisible by 5 otherwise return 1 
    if (c % 5 == 0) { 
        return 0; 
    } else { 
        return 1; 
    } 
} 
 
int sys_reversestring(const char* str, int len){ 
 
 int i = 0; 
 
 kprintf("String to reverse: %s\n", str); 
 kprintf("Reverse of string: "); 
 
 for(i = len - 1; i >= 0; i--){  // reverses the string 
 
  if(str[i] == NULL){ 
 
   continue; 
 
  } 
 
  kprintf("%c", str[i]); 
 
 } 
 
 kprintf("\n"); 
 
 if(len % 2 == 0){ // if length of string is multiple of 2 or not 
 
  return 0; 
 
 } else { 
 
  return 1; 
 
 }
