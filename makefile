facial_detection:main.cpp
	# compiling with opencv5 g++ main.cpp -o app -I/usr/include/opencv5/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lopencv_objdetect
	# opencv4
	g++ main.cpp -o app `pkg-config --cflags --libs opencv4` -o app
run:
	./app