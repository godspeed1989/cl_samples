include ../clconfigs.mk

TARGET=Hello

all: $(TARGET)

$(TARGET).o: $(TARGET).cpp

$(TARGET): $(TARGET).o
	$(CC) -o $@ $+ $(LIBS)

clean:
	rm -rf $(TARGET) $(TARGET).o