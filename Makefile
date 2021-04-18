#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: sortowanie
	./sortowanie

obj:
		mkdir -p obj

sortowanie: obj/main.o obj/introspective.o obj/quicksort.o obj/scalanie.o obj/functions.o obj/test.o
	g++ -Wall -pedantic -o sortowanie obj/main.o obj/scalanie.o obj/quicksort.o obj/introspective.o obj/functions.o obj/test.o
								   

obj/main.o: src/main.cpp inc/introspective.hh inc/quicksort.hh inc/scalanie.hh\
     inc/scalanie.hh inc/quicksort.hh inc/functions.hh inc/test.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/introspective.o: src/introspective.cpp inc/introspective.hh inc/quicksort.hh inc/scalanie.hh inc/functions.hh
	g++ ${CPPFLAGS} -o obj/introspective.o src/introspective.cpp

obj/quicksort.o: src/quicksort.cpp inc/quicksort.hh inc/scalanie.hh inc/functions.hh
	g++ ${CPPFLAGS} -o obj/quicksort.o src/quicksort.cpp

obj/scalanie.o: src/scalanie.cpp inc/scalanie.hh inc/functions.hh
	g++ ${CPPFLAGS} -o obj/scalanie.o src/scalanie.cpp

obj/functions.o: src/functions.cpp inc/functions.hh
	g++ ${CPPFLAGS} -o obj/functions.o src/functions.cpp

obj/test.o: src/test.cpp inc/test.hh
	g++ ${CPPFLAGS} -o obj/test.o src/test.cpp

clean:
	rm -f obj/*.o sortowanie