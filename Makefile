SRC = main.cpp user.cpp message.cpp
TARGET = mypro
PREFIX = /home/server/ref

mypro: $(SRC)
	g++ -o $(TARGET) $(SRC)

clean: 
	rm -rf *.o *.a

install:
	install $(TARGET) $(PREFIX)

uninstall:
	rm -rf $(PREFIX)/$(TARGET)

