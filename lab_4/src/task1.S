.globl task1
task1:
  imul $5, %eax
  imul $2, %edx
  add %edx, %eax
  add $657, %eax
  ret
