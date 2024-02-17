# Assignment 2

Compile+Run :

        gcc -o main.out main_template.c
        ./main.out
        ./main.out < input01.txt > myoutput01.txt

Memory Leak test :

        valgrind --track-origins=yes --show-leak-kinds=all --leak-check=full ./main.out < myinput.txt 2>&1 | tee MemLeak/valgrind.txt