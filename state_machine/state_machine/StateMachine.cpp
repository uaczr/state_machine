/**
 * @date 17.11.2016
 * @author christoph
 * @file StateMachine.cpp
 * 
 *  
 * 
 */

#include "StateMachine.h"
#include "Job.h"
namespace StateMachine {

StateMachine::StateMachine(State startState, TransitionPtr transitionMatrix, uint32_t transitionMatrixSize, JobPtr jobVector, uint32_t jobVectorSize) {
	this->currentState    	 		= startState;
	this->transitionMatrix    		= transitionMatrix;
	this->transitionMatrixSize 		= transitionMatrixSize;
	this->jobVector 				= jobVector;
	this->jobVectorSize				= jobVectorSize;
	this->currentEvent				= 0;
	this->status					= 0;
}

StateMachine::~StateMachine() {

}

void StateMachine::init() {
	//Start all Jobs
	for(uint32_t i = 0; i < jobVectorSize; i++){
		jobVector[i].start();
	}
}

void StateMachine::run() {
	//Main Loop of the State Machine
	while(true){
		//Iterate through JobVector
		for(uint32_t i = 0; i < jobVectorSize; i++){
			//Get the Jobs state
			JobState jobState = jobVector[i].getJobState();
			switch(jobState){
			//Run Job if the Job is marked as Running
			case job_running:
				jobVector[i].tick();
				break;
			//Reset Job if the Job is marked as Faulty
			case job_fault:
				jobVector[i].reset();
				break;
			//Otherwise do nothing
			default:
				break;
			}
		}

		//Get Current Event
		if(status != 0){
			currentEvent = -1;
		}
		if(eventQueue.empty()){
			currentEvent = 0;
		}
		else{
			currentEvent = eventQueue.front();
			eventQueue.pop();
		}

		//Chose right action from the TransitionMatrix
		for(uint32_t i = 0; i < transitionMatrixSize; i++){
			if(
					(transitionMatrix[i].currentState == currentState)
					&&
					(transitionMatrix[i].occuredEvent == currentEvent)){
				//Execute TransitionFunction
				status = transitionMatrix[i].stateFunction();
				//Check Return
				if(status == 0){
					currentState = transitionMatrix[i].futureState;
				}

			}
		}

	}
}

} /* namespace StateMachine */
