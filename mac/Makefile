.PHONY: all
all: main

main: JpegDecoder.o ReceiverSocket.o main.o
	g++ -v -L. *.o -omain -lopencv_core.3.2 -lopencv_imgcodecs.3.2 -lopencv_highgui.3.2
	install_name_tool -add_rpath '.' main

%.o: %.cpp *.h
	g++ -std=c++11 -Iinclude $< -c

.PHONY: clean
clean:
	-rm *.o main