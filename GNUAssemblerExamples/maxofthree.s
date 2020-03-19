#Mixing C and Assembly Language
#This 64-bit program is a very simple function that takes in three 64-bit integer parameters and returns the maximum value. It shows how to extract integer parameters: They will have been pushed on the stack so that on entry to the function, they will be in rdi, rsi, and rdx, respectively. The return value is an integer so it gets returned in rax.
#
#maxofthree.s
# -----------------------------------------------------------------------------
# A 64-bit function that returns the maximum value of its three 64-bit integer
# arguments.  The function has signature:
#
#   int64_t maxofthree(int64_t x, int64_t y, int64_t z)
#
# Note that the parameters have already been passed in rdi, rsi, and rdx.  We
# just have to return the value in rax.
# -----------------------------------------------------------------------------

        .globl  maxofthree
        
        .text
maxofthree:
        mov     %rdi, %rax              # result (rax) initially holds x
        cmp     %rsi, %rax              # is x less than y?
        cmovl   %rsi, %rax              # if so, set result to y
        cmp     %rdx, %rax              # is max(x,y) less than z?
        cmovl   %rdx, %rax              # if so, set result to z
        ret                             # the max will be in eax
