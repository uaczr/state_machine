/**
 * @date 17.11.2016
 * @author christoph
 * @file StateMachine.h
 * 
 *  
 * 
 */

#ifndef STATE_MACHINE_STATEMACHINE_H_
#define STATE_MACHINE_STATEMACHINE_H_
#include <cstdint>
#include <queue>
#include <vector>

namespace StateMachine {

class EventData;
class Job;
struct Transition;

typedef struct  Transition 				Transition;				/*!<Typedefition Transition */
typedef Transition* 					TransitionPtr; 			/*!<Typedefition TransitionPtr */
typedef int32_t 						State;					/*!<Typedefition State */
typedef int32_t 						Event;					/*!<Typedefition Event */
typedef int32_t 						Status;					/*!<Typedefition Status */
typedef Job* 							JobPtr;					/*!<Typedefition JobPtr */
typedef std::queue<Event> 				EventQueue;				/*!<Typedefition EventQueue */


typedef Status(*StateFunction)(void);					/*!<Typedefition StateFunction */

/*!
 * @brief Describes a State Transition of the StateMachine
 */
struct Transition{
	State 			currentState;								/*!<Contains the Current State of the StateMachine */
	Event 			occuredEvent;								/*!<Contains the Event that occurred  */
	StateFunction 	stateFunction;								/*!<Contains a Pointer to the StateFunction to execute  */
	State 			futureState;								/*!<Contains the Future State of the StateMachine*/
};

/**
 *	@brief Class StateMachine
 */
class StateMachine {
protected:
	State			currentState;
	EventQueue	 	eventQueue;
	Event			currentEvent;
	JobPtr			jobVector;
	uint32_t		jobVectorSize;
	TransitionPtr	transitionMatrix;
	uint32_t		transitionMatrixSize;
	Status			status;

public:
	/**
	 * @brief Constructs the StateMachine.
	 *
	 * @param [in] startState			StartState for the StateMachine
	 * @param [in] transitionMatrix		TransitionMatrix for the StateMachine
	 * @param [in] transitionMatrixSize	Size of the TransitionMatrix
	 * @param [in] jobVector			JobVector for the StateMachine
	 * @param [in] jobVectorSize		Size of the JobVector
	 */
	StateMachine(State startState, TransitionPtr transitionMatrix, uint32_t transitionMatrixSize, JobPtr jobVector, uint32_t jobVectorSize);

	/**
	 * @brief Destructs the StateMachine
	 */
	virtual ~StateMachine();
	/**
	 * @brief Initializes the StateMachine.
	 *
	 * This Method needs to be called to initialize the StateMachine
	 * and its jobs. It does not change the state of the StateMachine.
	 */
	virtual void init();
	/**
	 * @brief Runs the StateMachine.
	 *
	 * This Method contains the main loop of the StateMachine. It has to
	 * be called as a thread if operations other than the StateMachine
	 * need to be executed during runtime.
	 *
	 */
	virtual void run();

};

} /* namespace StateMachine */

#endif /* STATE_MACHINE_STATEMACHINE_H_ */
