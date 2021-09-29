# for convenience, define variable $(OBJS) to list of object files
OBJS= tokenizer.o uimain.o history.o

#target
all: tokenizer

#file dependenices
tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h history.h

# (target) depends on all object files (prerequisites)
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)
  
# all object files built from c files that include .h
$(OBJS): tokenizer.h history.h

#delete files
clean:
	rm -f *.o tokenizer history

run: tokenizer
	./tokenizer
