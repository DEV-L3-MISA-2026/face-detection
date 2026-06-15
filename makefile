facial_detection:main.cpp
# ++ main.cpp -o app -I/usr/include/opencv5/ -L/usr/lib/opencv5/ -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_objdetect -lopencv_dnn
	g++ auth.cpp -o app `pkg-config --cflags --libs opencv5` -o app
run:
	./app