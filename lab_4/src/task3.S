.globl main
main:
  sub $8, %rsp

  mov $0, %rdi
  mov $1, %rsi
  mov $2, %rdx
  mov $3, %rcx
  mov $4, %r8
  mov $5, %r9
  push $6
  push $7

  call print

  add $16, %rsp

  add $8, %rsp
  xor %eax, %eax
  ret
