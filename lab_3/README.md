## Constraints

Тут о том почему мы используем `a`, `d` и `c` в качестве `constraint`'ов

### other-letters

> Other letters can be defined in machine-dependent fashion to stand for particular classes of registers or other arbitrary operand types. ‘d’, ‘a’ and ‘f’ are defined on the 68000/68020 to stand for data, address and floating point registers.

## Clobbers

### "cc"

> The "cc" clobber indicates that the assembler code modifies the flags register. On some machines, GCC represents the condition codes as a specific hardware register; "cc" serves to name this register. On other machines, condition code handling is different, and specifying "cc" has no effect. But it is valid no matter what the target.

### "memory"

> The "memory" clobber tells the compiler that the assembly code performs memory reads or writes to items other than those listed in the input and output operands (for example, accessing the memory pointed to by one of the input parameters). To ensure memory contains correct values, GCC may need to flush specific register values to memory before executing the asm. Further, the compiler does not assume that any values read from memory before an asm remain unchanged after that asm; it reloads them as needed. Using the "memory" clobber effectively forms a read/write memory barrier for the compiler.

> Note that this clobber does not prevent the processor from doing speculative reads past the asm statement. To prevent that, you need processor-specific fence instructions.

### Links

- https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html#OutputOperands
- https://gcc.gnu.org/onlinedocs/gcc/Simple-Constraints.html#Simple-Constraints
