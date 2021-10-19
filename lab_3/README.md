## Constraints

Тут о том почему мы используем `a`, `d` и `c` в качестве `constraint`'ов

### other-letters

> Other letters can be defined in machine-dependent fashion to stand for particular classes of registers or other arbitrary operand types. ‘d’, ‘a’ and ‘f’ are defined on the 68000/68020 to stand for data, address and floating point registers.

## Clobbers

### "cc"

> The "cc" clobber indicates that the assembler code modifies the flags register. On some machines, GCC represents the condition codes as a specific hardware register; "cc" serves to name this register. On other machines, condition code handling is different, and specifying "cc" has no effect. But it is valid no matter what the target.

### Links

- https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html#OutputOperands
- https://gcc.gnu.org/onlinedocs/gcc/Simple-Constraints.html#Simple-Constraints
