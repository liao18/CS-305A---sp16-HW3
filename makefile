#define the compiler-executable path
COMPILE = gcc $(COMPILE_SWITCHES)
OFILES = receipt.o retail_item.o main.o

runtest: $(OFILES)
	$(COMPILE) -o runtest $(OFILES)

receipt.o: receipt.c receipt.h retail_item.h
	$(COMPILE) -c receipt.c

retail_item.o: retail_item.c retail_item.h
	$(COMPILE) -c retail_item.c

main.o: main.c retail_item.h receipt.h
	$(COMPILE) -c main.c

# this defines the command for cleaning up
# all generated files
clean:
	/bin/rm -f *.o test
