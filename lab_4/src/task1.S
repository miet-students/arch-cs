.globl task1
task1:
  imul $4, %eax
  add %edx, %eax
  add $234, %eax
  ret
