ex_compile: ex_compile.c
	gcc ex_compile.c -Wall -o ex_compile `pkg-config --cflags --libs glib-2.0`
