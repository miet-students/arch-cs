.globl task1
task1:
  xor %eax, %eax // clean rax, not sure we need it
  cmp $7, %edi
  setl %al
  ret
