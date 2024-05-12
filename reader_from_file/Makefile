main:main.o reader.o
  gcc main.o reader.o -o myreader
main.o:
  gcc -c main.c
reader.o:
  gcc -c reader.c
clean:
  rm -f main.o reader.o myreader