section .data
    hello db "Hello, Holberton",0
    format db "%s", 10, 0   ; Format string for printf with a new line character

section .text
    global main

    extern printf
    main:
        push rbp
        mov rdi, format     ; Format string
        mov rsi, hello      ; Address of the string
        call printf

        pop rbp
        ret
