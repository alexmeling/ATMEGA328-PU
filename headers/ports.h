/** @file ports.h
 *  @brief Class  prototype for the ports driver
 * 
 *  This contains the class for the ports driver 
 *  and also the attributs and methods you will need
 *
 *  @author Alex velásquez Meling 
 *  @bugs No known bugs
 */

#ifndef PORTS_H
#define PORTS_H

/**
 * @class port
 * @brief this contains the attributs and methods for the port driver
 */


 class port {

	public:
		/** @brief Constructor
		 * creates a new port instance
		 * @param &nom the name of the port (PORTB,PORTC,PORTD)
		 * @return nothing
		 */

		port( volatile uint8_t &nom);

		/** @brief sets the pin in DIGITAL OUTPUT MODE 
		 * @param pin the pin number of the port (PIN0..PIN7)
		 * @param state the pin state (HIGH or LOW)
		 * @return nothing
		 */

		void set_output(int pin, bool state);

		/**
		 * @brief sets the pin as INPUT MODE with pull-up disable
		 * @param pin the pin number of the port (PIN0..PIN7)
		 * @return nothing
		 */

		void set_input(int pin);

		/**
		 * @brief sets the pin as INPUT MODE PULL UP ENABLE
		 * @param pin the pin number of the port
		 * @return nothing
		 */

		void set_input_PUE(int pin);
		
		/**
		 * @brief gives the digital state(HIGH or LOW) of the pin
		 * @param pin the pin number of the port
		 * @return Digital state of the pin (bool)
		 */

		bool get_state(int pin);
		
		/**
		 * @brief inverts the state of the specified PORT (DEFAULT STATE: 10101010)
		 * @param time gives the time between each state (in miliseconds)
		 * @return nothing
		 */
			
		void invert(const int &time);
			
		
		/*void set_input(int &numero_broche);
		void set_high(int numero_broche);
		void set_low(int &numero_broche);
		int  get_state(int &numero_broche);*/




		
	protected:
		volatile uint8_t* port_name; ///< pointer to the io register PORTx (x{B,C,D})
		bool broche; ///< ensure the creation of a port instance 

};

#endif // PORTS_H
