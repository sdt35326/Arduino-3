/**
 * \file interval.h
 * \brief Arduino Library to handle time interval (in milliseconds). Time library is required.
 *
 * \author Marco Boeris Frusca
 *
 */
#ifndef INTERVAL_H_
#define INTERVAL_H_

#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif

namespace smrtobj
{

  namespace timer
  {
    
    /**
     * The Interval class handles time interval (in milliseconds). An interval has an instant where
     * it starts. Calling the time() function it is possible to know how much time has passed from
     * the starting time.
     */
    class Interval
    {
      public:
        /**
         * Default Constructor
         * It sets all internal variables and counters.
         */
        Interval();
  
        /**
         * Constructor
         * It sets the start time at a given value (number of milliseconds).
         *
         * \param[in] start number of milliseconds to use as start time
         */
        Interval(unsigned long start);
  
        /**
         * Copy Constructor
  	   *
         * \param[in] s Interval in mills
         */
        Interval(const Interval& s);
  
        /**
         * Destructor
         */
        virtual ~Interval();
  
        /**
         * Updates the start time at current time.
         *
         */
        void update();
  
        /**
         * Returns the start time (in milliseconds).
         *
         * \return start time
         */
       unsigned long start();
   
        /**
         * Resets the start time to now().
         *
         * \param[in] start new starting time
         */
        void reset(unsigned long start = 0);
  
        /**
         * Returns the time passed from the start time (in milliseconds).
         *
         * \param[in] tref external reference time, if 0 use system time
         *
         * \return time passed
         */
        unsigned long time(unsigned long tref = 0);
  
        /**
         * Returns the remaining time calculated as endTime - m_start (in milliseconds).
         *
         * \param[in] endTime end time of an interval
         * \param[in] tref external reference time, if 0 use system time
         *
         * \return residual time
         */
        unsigned long residualTime(unsigned long endTime, unsigned long tref = 0);
  
        /**
         *  Overload operator =
         *
         */
        Interval& operator=(const Interval&);
  
      protected:
        //! start time (in milliseconds)
        unsigned long m_start;
  
    };
  
    inline unsigned long Interval::start()
    {
      return m_start;
    }
  
    inline void Interval::update()
    {
      m_start = millis();
    }
  
  } /* namespace timer */

} /* namespace smrtobj */

#endif /* INTERVAL_H_ */
