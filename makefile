PROJ_NAME=FTC_TPFinal

HEADERS=$(wildcard headers/*.h)

SOURCES=$(wildcard sources/*.c)

MAIN=main.c

all:
	clear
	@ gcc $(MAIN) $(SOURCES) -o $(PROJ_NAME)
	@ ./$(PROJ_NAME)