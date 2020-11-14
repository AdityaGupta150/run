all:
	g++ run.cpp -o run

dbg:
	g++ -g run.cpp -o run && gdb ./run

clean:
	rm run