.data
  x: .double 1.3
  y: .double 3.5
  a: .double 5.3
  msg: .string "Printing from ASM: %d\n"
.text
.globl main
main:
  vmovsd x, %xmm0
  vmovsd y, %xmm1

  sub $8, %rsp

  sub $32, %rsp
  call fp_var_math
  add $32, %rsp

  vmovsd x, %xmm0
  vmovsd a, %xmm1
  vmovsd y, %xmm2

  sub $32, %rsp
  call add
  add $32, %rsp

  sub $32, %rsp
  call cubrt
  add $32, %rsp

  vmovsd y, %xmm1

  sub $32, %rsp
  call add
  add $32, %rsp

  add $8, %rsp
  xor %eax, %eax

  ret

