/**file serial.h
 * @brief Class prototype for the serial communication driver
 * @author Alex Velásquez Meling
 * @bugs No Known bugs
 */ 


#ifndef SERIAL_H
#define SERIAL_H

/**
 * @class serial
 * @brief this contains the attributs and methods for the serial communication driver
 */


class serial{

	public:
	
	/** @brief Constructor
	 * @return nothing 
	 */

	serial();

	/** @brief USART interface
	 * initialize the interface
	 * @return nothing
	 */

	void init();

	/** @brief Write data into the buffer
	 * @param data data to be sent
	 * @return nothing
	 */

	void write(char& data);

	/**@brief read data from the buffer
	 * @return data read
	 */
	char read();

	/** @brief Verify if the buffer has data to be read
	 * @return true if data is received  or false if it is not.
	 * */
	char data_received();	

};

#endif // SERIAL_H
