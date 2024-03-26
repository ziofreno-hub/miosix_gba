/***************************************************************************
 *   Copyright (C) 2009, 2010, 2011, 2012 by Terraneo Federico             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   As a special exception, if other files instantiate templates or use   *
 *   macros or inline functions from this file, or you compile this file   *
 *   and link it with other works to produce a work based on this file,    *
 *   this file does not by itself cause the resulting work to be covered   *
 *   by the GNU General Public License. However the source code for this   *
 *   file must still be made available in accordance with the GNU General  *
 *   Public License. This exception does not invalidate any other reasons  *
 *   why a work based on this file might be covered by the GNU General     *
 *   Public License.                                                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#ifndef GPIO_IMPL_H
#define	GPIO_IMPL_H

#include "hardware_mappings/hwmapping.h"

namespace miosix {

/**
 * This class just encapsulates the Mode_ enum so that the enum names don't
 * clobber the global namespace.
 */
class Mode
{
public:
    /**
     * GPIO mode (INPUT, OUTPUT, ...)
     * \code pin::mode(Mode::INPUT); \endcode
     */
    enum Mode_
    {
        INPUT              = 0x0, ///Floating  Input
        OUTPUT             = 0x1, ///Push Pull Output
    };
private:
    Mode(); //Just a wrapper class, disallow creating instances
};

/**
 * This class allows to easiliy pass a Gpio as a parameter to a function.
 * Accessing a GPIO through this class is slower than with just the Gpio,
 * but is a convenient alternative in some cases. Also, an instance of this
 * class occupies a few bytes of memory, unlike the Gpio class.
 */
class GpioPin
{
public:
    /**
     * Constructor
     * \param p Only GPIO_BASE
     * \param n which pin (0 to 3)
     */
    GpioPin(unsigned int p, unsigned char n)
        : p(reinterpret_cast<gpio_registers*>(p)), n(n) {}
        
    /**
     * Set the GPIO to the desired mode (INPUT, OUTPUT)
     * \param m enum Mode_
     */
    void mode(Mode::Mode_ m)
    {
        if(m==Mode::INPUT)
        {
            p->DIR &= ~(1<<n);
        } else {
            p->DIR |= (1<<n);
        }
    }

    /**
     * Set the pin to 1, if it is an output
     */
    void high()
    {
        p->DATA |= 1<<n;
    }

    /**
     * Set the pin to 0, if it is an output
     */
    void low()
    {
        p->DATA &= ~(1<<n);
    }

    /**
     * Allows to read the pin status
     * \return 0 or 1
     */
    int value()
    {
        return (p->DATA & 1<<n) ? 1 : 0;
    }
    
    /**
     * \return the pin port. One of the constants PORT0_BASE, PORT1_BASE, ...
     */
    unsigned int getPort() const { return reinterpret_cast<unsigned int>(p); }
    
    /**
     * \return the pin number, from 0 to 3
     */
    unsigned char getNumber() const { return n; }

private:
    gpio_registers *p; //Pointer to the port
    unsigned char n;     //Number of the GPIO within the port
};



/**
 * Gpio template class
 * \param P GPIO_BASE, only one port available
 * \param N which pin (0 to 3)
 * The intended use is to make a typedef to this class with a meaningful name.
 * \code
 * typedef Gpio<GPIO0_BASE,0> green_led;
 * green_led::mode(Mode::OUTPUT);
 * green_led::high();//Turn on LED
 * \endcode
 */
template<unsigned int P, unsigned char N>
class Gpio
{
public:
    /**
     * Set the GPIO to the desired mode (INPUT, OUTPUT)
     * \param m enum Mode_
     */
    static void mode(Mode::Mode_ m)
    {
        // Sets DIR and DATA registers as read/writable
        reinterpret_cast<gpio_registers *>(P)->CTRL |= 1;

        if(m==Mode::INPUT)
        {
            reinterpret_cast<gpio_registers *>(P)->DIR &= ~(1<<N);
            //GPIO_BASE->IODIR &= ~(1<<N);
        } else {
            reinterpret_cast<gpio_registers*>(P)->DIR |= 1<<N;
        }
    }

    /**
     * Set the pin to 1
     */
    static void high()
    {
        reinterpret_cast<gpio_registers*>(P)->DATA |= 1<<N;
    }

    /**
     * Set the pin to 0
     */
    static void low()
    {
        reinterpret_cast<gpio_registers*>(P)->DATA &= ~(1<<N);
    }

    /**
     * Allows to read the pin status
     * \return 0 or 1
     */
    static int value()
    {
        return ((reinterpret_cast<gpio_registers*>(P)->DATA & 1<<N)? 1 : 0);
    }

    /**
     * \return this Gpio converted as a GpioPin class 
     */
    static GpioPin getPin()
    {
        return GpioPin(P,N);
    }
    
    /**
     * \return the pin port. Only 1 port
     */
    unsigned int getPort() const { return P; }
    
    /**
     * \return the pin number, from 0 to 3
     */
    unsigned char getNumber() const { return N; }

private:
    Gpio();//Only static member functions, disallow creating instances
};

} //namespace miosix

#endif	//GPIO_IMPL_H