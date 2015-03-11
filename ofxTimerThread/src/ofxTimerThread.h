#ifndef _THREADED_OBJECT
#define _THREADED_OBJECT

#include "ofMain.h"
#include <chrono>
#include <thread>

template <class T>
class ofxTimerThread : public ofThread{


	public:
	    typedef void (T::*fn)( );

        ofxTimerThread(T& trg, fn op)
            : m_rTarget(trg)
            , m_Operation(op)
            { interval = Interval(1);  }

	    int count;
        typedef chrono::microseconds Interval;
        Interval interval;

		//--------------------------
		void threadedObject(){
		    count = 0;
		}

		void start(){
            startThread(true, true);   // blocking, verbose
        }

        void stop(){
            stopThread();
        }

        void setInterval(long int interval_)
        {
//            if(isThreadRunning() == 0)
                interval = Interval(interval_);
        }

        void setCallback()
        {
            if(isThreadRunning() == 0);

        }

		//--------------------------
		void threadedFunction(){

			while( isThreadRunning() != 0 ){

				if( lock() ){
                    this_thread::sleep_for( interval );

                    (m_rTarget.*m_Operation)();
//                    callback.Execute();

                    unlock();

				}
			}
		}


   private:
        T& m_rTarget;
        fn m_Operation;

};

#endif
