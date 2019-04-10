wordie: word_count.c
	gcc word_count.c -Wall -o wordie `pkg-config --cflags --libs glib-2.0`
