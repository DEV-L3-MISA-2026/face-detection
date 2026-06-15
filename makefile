facial_detection:main.cpp
	g++ main.cpp -o app  -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio
run:
	./app