myall: main.o parser.o Node.o diff_prog.o create_tex_doc.o
	g++ -o myall main.o  parser.o Node.o diff_prog.o create_tex_doc.o
parser.o: parser.cpp diff_prog.h
	g++ -O -c parser.cpp
Node.o: Node.cpp diff_prog.h
	g++ -O -c Node.cpp
diff_prog.o: diff_prog.cpp diff_prog.h
	g++ -O -c diff_prog.cpp
create_tex_doc.o: create_tex_doc.cpp diff_prog.h
	g++ -O -c create_tex_doc.cpp
main.o: main.cpp diff_prog.h
	g++ -O -c main.cpp
clean:
	rm -f myall main.o parser.o Node.o diff_prog.o create_tex_doc.o
