#Command Line Arguments
#You know that in C, main is just a plain old function, and it has a couple parameters of its own:
#
#    int main(int argc, char** argv)
#Here is a program that uses this fact to simply echo the commandline arguments to a program, one per line:
#
#echo.s
# -----------------------------------------------------------------------------
# A 64-bit program that displays its commandline arguments, one per line.
#
# On entry, %rdi will contain argc and %rsi will contain argv.
# -----------------------------------------------------------------------------

        .global main

        .text
main:
        push    %rdi                    # save registers that puts uses
        push    %rsi
        sub     $8, %rsp                # must align stack before call

        mov     (%rsi), %rdi            # the argument string to display
        call    puts                    # print it

        add     $8, %rsp                # restore %rsp to pre-aligned value
        pop     %rsi                    # restore registers puts used
        pop     %rdi

        add     $8, %rsi                # point to next argument
        dec     %rdi                    # count down
        jnz     main                    # if not done counting keep going

        ret
format:
        .asciz  "%s\n"
#$ clang echo.s && ./a.out 25782 dog huh $$
#./a.out
#25782
#dog
#huh
#9971
#$ clang echo.s && ./a.out 25782 dog huh '$$'
#./a.out
#25782
#dog
#huh
#$$
#Note that as far as the C Library is concerned, command line arguments are always strings. If you want to treat them as integers, call atoi.
