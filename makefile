CCFLAGS=-g -DMAIN

tube: tube.o

tube.o: tube.c tube.h
	$(CC) -o tube.o -c $(CCFLAGS) tube.c

tube.i: tube.c tube.h
	$(CC) -o tube.i -E tube.c

tube.s: tube.c tube.h
	$(CC) -o tube.s -S tube.c

tube.x86: tube.s
	ln -s tube.x86 tube.s tube.x86

tube.mips: tube.o
	echo "Go to the website: http://reliant.colab.duke.edu/c2mips/"
	echo "enter the file tube.c"
	touch tube.mips

clean:
	rm -f tube tube.o tube.i tube.s tube.x86
	rm -f *~ \#*



