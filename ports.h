/* code header pour les ports  */

#ifndef PORTS_H
#define PORTS_H


 class port {

	public:
		
		port( volatile uint8_t &nom);
		void set_output(int pin, bool state);

		/*void set_input(int &numero_broche);
		void set_high(int numero_broche);
		void set_low(int &numero_broche);
		int  get_state(int &numero_broche);*/


		
	protected:
		volatile uint8_t port_name;
		bool broche;
		bool output;
		bool input;
		bool high;
		bool low;
		bool state;
		int data_input;

};

#endif // PORTS_H
