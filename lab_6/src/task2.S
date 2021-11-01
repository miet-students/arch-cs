.globl task2
task2:
  xor %eax, %eax
  cmp $3, %edi

  jge more_than_3

  movl $4, %eax
  jmp end

  more_than_3:
    lea -52(%eax, %edi, 8), %eax

  end:
  ret
