INPUT := input01.txt

all: main_template

main_template: 
	gcc -o main.out main_template.c

run: 
	./main.out

mine: 
	./main.out < $(INPUT) > myoutput.txt

yoram: 
	./task02.out < $(INPUT) > yoramoutput.txt

test: mine yoram
