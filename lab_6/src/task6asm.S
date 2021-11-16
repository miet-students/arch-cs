.data
eps: .double 0.000001
two: .double 2
.text
.globl task6
task6:
  xor %rax, %rax //s1
  xor %rbx, %rbx //s2
  xor %rcx, %rcx //sum
  xor %rdx, %rdx //end
  movq two, %rdx

while_true:
  push  %rdx
  fldl (%rsp)            //end
  pop  %rdx
  fmul %st(0), %st(0)    //end*end
  fld1                   //1 end*end
  fsubrp %st(0), %st(1)  //end*end-1
  push  %rdx
  fldl (%rsp)            //end end*end-1
  pop  %rdx
  fdivr %st(0), %st(1)   //end (end*end-1)/end
  fdivr %st(0), %st(1)   //end (end*end-1)/end/end
  fdivrp %st(0), %st(1)  //(end*end-1)/end/end/end
  fldl eps               //eps (end*end-1)/end/end/end
  fcomi
  jnbe for_loop
  fstp %st(0)
  fstp %st(0)           //стек пуст
  push  %rdx
  fldl (%rsp)            //end
  pop  %rdx
  fldl two               //2 end
  faddp %st(0), %st(1)   //2+end
  fstpl 16(%rbp)
  movq 16(%rbp), %rdx    //end = end+2
  jmp while_true

for_loop:
  push  %rdx
  fldl (%rsp)            //end
  pop  %rdx
  fld1                   //1 end
  fcomi
  jnbe end
  fstp %st(0)            //end
  fmul %st(0), %st(0)    //end*end
  fld1                   //1 end*end
  fsubrp %st(0), %st(1)  //end*end-1
  push  %rdx
  fldl (%rsp)            //end end*end-1
  pop  %rdx
  fdivr %st(0), %st(1)   //end (end*end-1)/end
  fdivr %st(0), %st(1)   //end (end*end-1)/end/end
  fdivrp %st(0), %st(1)  //(end*end-1)/end/end/end
  fstpl 16(%rbp)
  movq 16(%rbp), %rax    //s1

  push  %rdx
  fldl (%rsp)            //end
  pop  %rdx
  fld1                   //1 end
  fsubrp %st(0), %st(1)  //end-1 next 10 lines
  fmul %st(0), %st(0)    //end*end
  fld1                   //1 end*end
  fsubrp %st(0), %st(1)  //end*end-1
  push  %rdx
  fldl (%rsp)            //end end*end-1
  pop  %rdx
  fld1                   //1 end end*end-1
  fsubrp  %st(0), %st(1) //end-1 end*end-1
  fdivr %st(0), %st(1)   //end-1 (end*end-1)/end
  fdivr %st(0), %st(1)   //end-1 (end*end-1)/end/end
  fdivrp %st(0), %st(1)  //(end*end-1)/end/end/end

  push  %rax
  fldl (%rsp)            //f(end) f(end-1)
  pop  %rax
  fsubp %st(0), %st(1)  //f(end)-f(end-1)
  push  %rcx
  fldl (%rsp)            //sum f(end)-f(end-1)
  pop  %rcx
  faddp %st(0), %st(1)   //sum+f(end)-f(end-1)
  fstpl 16(%rbp)
  movq 16(%rbp), %rcx
  push  %rdx
  fldl (%rsp)           //end
  pop  %rdx
  fldl two              //2 end
  fsubrp %st(0), %st(1)  //end-2
  fstpl 16(%rbp)
  movq 16(%rbp), %rdx
  jmp for_loop



end:
  movq %rcx, %xmm0
  xor %eax, %eax
  ret
