CC 		= gcc
LD 		= gcc
OBJS 		= $(CFILES:.c=.o)
LIBS 		= `xml-config --libs` 
INCLUDES	= -I/usr/include/libxml2
CFLAGS 		= -Wall -g -O2 `xml-config --cflags`
CFILES 		= areprotoparser.c
TARGET 		= xmlparser2

all: $(TARGET)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@ $(LIBS) $(INCLUDES)

clean:
	rm -f *.o $(TARGET)

