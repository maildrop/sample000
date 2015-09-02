CPP := g++
CPPFLAGS := -std=c++11 -O2 -Wall -Werror -pthread 

all_TARGET := HelloWorld 
clean_TARGET := $(all_TARGET)

all: $(all_TARGET)

clean:
	@for var in  $(clean_TARGET) ; do if [ -f $$var ] ; then rm $$var ; fi ; done;

