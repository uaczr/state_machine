/**
 * @date 06.12.2016
 * @author christoph
 * @file StateMachineModule.h
 * 
 *  
 * 
 */

#ifndef STATEMACHINE_STATEMACHINEMODULE_H_
#define STATEMACHINE_STATEMACHINEMODULE_H_

#include "StateMachineStatus.h"
#include "StateMachineMisc.h"

namespace StateMachine {

/**
 * @brief Possible States of a Module
 */
typedef enum StateMachineModuleState{
	ModuleStopped, //!< ModuleStopped
	ModuleLoading, //!< ModuleLoading
	ModuleStarting,//!< ModuleStarting
	ModuleRunning, //!< ModuleRunning
	ModulePausing  //!< ModulePausing
}ModuleState;


class StateMachineModule {

protected:
	Status status;
	StateMachineModuleState state;

	virtual Status _load(StateMachineData* data)		= 0;
	virtual Status _start(StateMachineData* data)		= 0;
	virtual Status _pause(StateMachineData* data)		= 0;
	virtual Status _stop(StateMachineData* data)		= 0;

public:

	StateMachineModule();
	virtual ~StateMachineModule();

	/**
	 * @brief Loads module's data
	 * @param [in] data					Pointer to a data struct
	 * @return							Returns the Execution-Status of the function
	 */
	Status load(StateMachineData* data);

	/**
	 * @brief Starts the module
	 * @param [in] data					Pointer to a data struct
	 * @return							Returns the Execution-Status of the function
	 */
	Status start(StateMachineData* data);

	/**
	 * @brief Pause the module
	 * @param [in] data					Pointer to a data struct
	 * @return							Returns the Execution-Status of the function
	 */
	Status pause(StateMachineData* data);

	/**
	 * @brief Stop the module
	 * @param [in] data					Pointer to a data struct
	 * @return							Returns the Execution-Status of the function
	 */
	Status stop(StateMachineData* data);

};

} /* namespace StateMachine */

#endif /* STATEMACHINE_STATEMACHINEMODULE_H_ */
