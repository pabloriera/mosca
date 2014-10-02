#ifndef _OSC_PB

    #define _OSC_PB

    #include <map>
    #include <string>
    #include "stdlib.h"
    #include "ofxOsc.h"

    using namespace std;


    class OSC_pb
    {
        private:

        class paquete
        {
            public:
            paquete(float* _x, float _minX, float _maxX, float _minY, float _maxY)
            {
                x = _x;
                minX = _minX;
                maxX = _maxX;
                minY = _minY;
                maxY = _maxY;
            }

            float* x;
            float minX, maxX, minY, maxY;
        };

        typedef map<string, paquete> map_receive;

        map_receive m;

        ofxOscReceiver oscreceiver;
        ofxOscSender oscsender;

        void call_ofMap(const string& keyString, float valor);

        public:

            OSC_pb(){};

            void OSCmap_receive(string label, float* x, float minX, float maxX, float minY, float maxY);



            void setup(string ip, int send_port,int receive_port);

            void update(ofEventArgs & args);


    };

#endif
