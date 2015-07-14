

CC=gcc
CFLAGS = -Wall
MYSQLFLAGS=`mysql_config --libs --cflags`
OPTIONS= -Wall

all:
	$(CC) $(CFLAGS)  cJSON.c mysqlJson.c $(MYSQLFLAGS) -o mysqlJson
clean:
	rm -rv  mysqlJson
