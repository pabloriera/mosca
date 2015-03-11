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

        class receive_data
        {
            public:
            receive_data(float* _x, float _minX, float _maxX, float _minY, float _maxY)
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

        //template<typename U>
        class send_data
        {
            public:
                send_data(float* _fx)
                {
                    typex = "float";
                    fx = _fx;
                    fx_old = *_fx;
                }


                send_data(int* _ix)
                {
                    typex = "int";
                    ix = _ix;
                    ix_old = *_ix;
                }

                string typex;

                float* fx;
                float fx_old;
                int* ix;
                int ix_old;

        };

        typedef map<string, receive_data> map_receive;
        typedef map<string, send_data> map_send;

        //template<typename U> struct A {};
        //typedef map<string, send_data<U,A<U>> map_send;

        map_receive receives_list;
        map_send sends_list;

        ofxOscReceiver oscreceiver;
        ofxOscSender oscsender;

        void call_ofMap(const string& keyString, float valor);

        public:

            OSC_pb(){};

            void OSCreceive_map(string label, float* x, float minX, float maxX, float minY, float maxY);
            void OSCsend_map(string label, float* x);
            void OSCsend_map(string label, int* x);

            void setup(string ip, int send_port,int receive_port);

            void update(ofEventArgs & args);
            void test(const void * sender,ofEventArgs & args);

            ofEvent<ofEventArgs> newEvent;

            void send(string label,string s);
            void send(string label,float f);
            void send(string label,int i);
    };

#endif
