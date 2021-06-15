run:
	g++ run.cpp -o run

dbg:
	g++ -g run.cpp -o run && gdb ./run

install: run
	mkdir -p ${DESTDIR}/usr/local/bin
	cp run ${DESTDIR}/usr/local/bin/

uninstall:
	rm ${DESTDIR}/usr/local/bin/run

clean:
	rm run

