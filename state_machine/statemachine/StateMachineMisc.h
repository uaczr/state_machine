/**
 * @date 07.12.2016
 * @author christoph
 * @file StateMachineMisc.h
 * 
 *  
 * 
 */

#ifndef STATEMACHINE_STATEMACHINEMISC_H_
#define STATEMACHINE_STATEMACHINEMISC_H_

#include <vector>
#include <string>
#include "StateMachineStatus.h"
#include "StateMachineModule.h"

namespace StateMachine{

/*
 * Forwarddeclarations
 */
class StateMachineModule;
enum StateMachineModuleState;

/**
 * @brief Describes transition of a module
 */
typedef struct StateMachineModuleTransition{
	StateMachineModule* module;
	StateMachineModuleState state;
}StateMachineModuleTransition;

/**
 * @brief Struct describes event of the StateMachine
 */
typedef struct StateMachineEvent{
	int32_t 								id;
	bool 									active;
	std::string 							name;
}StateMachineEvent;

/**
 * @brief Struct describes state of the StateMachine
 */
typedef struct StateMachineState{
	int32_t 								id;
	std::string 							name;
}StateMachineState;

/**
 * @brief Struct describes transition of the StateMachine
 */
typedef struct StateMachineTransition{
	StateMachineState* 						currentState;
	StateMachineEvent* 						currentEvent;
	StateMachineState* 						futureState;
}StateMachineTransition;

/**
 * @brief Struct, contains pointers to important data of the StateMachine
 */
typedef struct StateMachineData{
	std::vector<StateMachineModule*>* 		modules;
	std::vector<StateMachineTransition*>* 	transitions;
	std::vector<StateMachineState*>* 		states;
	std::vector<StateMachineEvent*>* 		events;
}StateMachineData;



}




#endif /* STATEMACHINE_STATEMACHINEMISC_H_ */
