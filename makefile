CXX      = g++
CXXFLAGS = -Wall -g
TARGET   = contact_book
SRCS     = main.cpp contact_book.cpp contact.cpp

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

run: all
	./$(TARGET)

leak: all
	leaks --atExit -- ./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run leak clean