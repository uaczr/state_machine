/**
 * @date 04.12.2016
 * @author christoph
 * @file StateMachine.h
 * 
 *  
 * 
 */

#ifndef STATEMACHINE_STATEMACHINE_H_
#define STATEMACHINE_STATEMACHINE_H_

#include "Arduino.h"
#include "EEPROM.h"
#include "FS.h"


namespace StateMachine {

class StateMachine {
private:


public:
	StateMachine();
	virtual ~StateMachine();
	/**
	 * @brief Loads the Modules Used in the StateMachine
	 *
	 * This function loads the Modules used in the StateMachine
	 * by loading it from a JSON-File or an Headerfile.
	 *
	 */
	void loadModules();
	/**
	 * @brief Sets up the basic StateMachine
	 *
	 * This Function should be called in the Arduino Setup routine.
	 * It loads the Configuration of the StateMachine.
	 */
	void setup(void);
	/**
	 * @brief Loop Function of the StateMachine
	 */
	void loop(void);
};

} /* namespace StateMachine */

#endif /* STATEMACHINE_STATEMACHINE_H_ */
