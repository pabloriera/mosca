#ifndef _OSC_PB
    #define _OSC_PB

    class OSC_pb
    {
        private:

        class paquete
            {
                public:
                paquete(float _x, float _minX, _maxX, _minY, _maxY)
                            {x = _x; minX = _minX, etc	}

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
