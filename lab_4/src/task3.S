.globl main
main:
  sub $8, %rsp

  mov $0, %rdi
  mov $1, %rsi
  mov $2, %rdx
  mov $3, %rcx
  mov $4, %r8

  call print

  add $8, %rsp
  xor %eax, %eax
  ret
