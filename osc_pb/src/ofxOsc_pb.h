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
                paquete(float _x, float _minX, float _maxX, float _minY, float _maxY)
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

        ofxOSCreceiver oscreceiver;
        ofxOSCsender oscreceiver;

        public:

            OSC_pb(){};

    }

#endif
