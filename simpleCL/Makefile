include ../clconfigs.mk

CFLAGS+=-Wall

TARGET1=simpleCL
TARGET2=main

all: $(TARGET1)

$(TARGET1).o: $(TARGET1).c  $(TARGET1).h
$(TARGET2).o: $(TARGET2).c

$(TARGET1): $(TARGET1).o $(TARGET2).o
	$(CC) -o $@ $+ $(LIBS)

clean:
	rm -rf $(TARGET1) $(TARGET1).o $(TARGET2).o

