.globl task2
task2:
  imul $4, %eax
  add %edx, %eax
  add $234, %eax
  ret

.data
  msg: .string "Calling from ASM: %d\n"
.text

.globl main
main:
  sub  $8, %rsp

  movl $1, %eax
  movl $0, %edx

  call task2

  mov %eax, %esi
  lea msg(%rip), %rdi
  mov $0, %al
  call printf

  add $8, %rsp
  xor %eax, %eax
  ret
