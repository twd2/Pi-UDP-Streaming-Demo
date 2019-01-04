#include "ReceiverSocket.h"
#include "JpegDecoder.h"

int main(int argc, char **argv) {

	ReceiverSocket receiver(argv[1], 17788);

	if (!receiver.isConnect())
		return -1;

	JpegDecoder jdecoder;

	vector<unsigned char> data;


	while (receiver.isConnect()) {

		double t = (double)getTickCount();
		while (!receiver.getFrontData(data)) {
			this_thread::sleep_for(chrono::duration<int, std::milli>(5));
			//cout << "wait receive data" << endl;
		}

		jdecoder.showJpeg(data);
	}

    return 0;
}
