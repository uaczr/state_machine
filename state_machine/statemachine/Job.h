/**
 * @date 18.11.2016
 * @author christoph
 * @file Job.h
 * 
 *  
 * 
 */

#ifndef JOB_BASE_JOB_H_
#define JOB_BASE_JOB_H_
#include "StateMachine.h"

namespace StateMachine {
/**
 * @brief Enumeration of the JobStates
 */
typedef enum JobState{
	job_stopped,//!< job_stopped
	job_running,//!< job_running
	job_paused, //!< job_paused
	job_fault   //!< job_fault
} JobState;


/**
 * @brief Virtual Class Job
 */
class Job {
private:
	JobState jobState;
	Status error;
protected:
	/**
	 * @brief Pure virtual start method.
	 *
	 * This method is called when the Job is started.
	 * @return Status, status_good if no error occurred.
	 */
	virtual Status _start() 		= 0;
	/**
	 * @brief Pure virtual tick method.
	 *
	 * This method is called when the Job is ticked.
	 * @return Status, status_good if no error occurred.
	 */
	virtual Status _tick() 			= 0;
	/**
	 * @brief Pure virtual start method.
	 *
	 * This method is called when the Job is stopped.
	 * @return Status, status_good if no error occurred.
	 */
	virtual Status _stop() 			= 0;
	/**
	 * @brief Pure virtual start method.
	 *
	 * This method is called when the Job is paused.
	 * @return Status, status_good if no error occurred.
	 */
	virtual Status _pause() 		= 0;
	/**
	 * @brief Pure virtual start method.
	 *
	 * This method is called when the Job is reset.
	 * @return Status, status_good if no error occurred.
	 */
	virtual Status _reset()			= 0;

public:
	/**
	 * @brief Constructs the Job
	 */
	Job();
	/**
	 * @brief Destructs the Job
	 */
	virtual ~Job();
	/**
	 * @brief Method that starts the Job.
	 *
	 * This Method is called by the StateMachine.
	 * @return Status, status_good if no error occurred.
	 */
	Status start();
	/**
	 * @brief Method runs one tick of the Job.
	 *
	 * This Method is called by the StateMachine's main loop.
	 * @return Status, status_good if no error occurred.
	 */
	Status tick();
	/**
	 * @brief Method stops the Job.
	 *
	 * This Method is used to stop the Job. It is called when the
	 * StateMachine is stopped or if the Job is removed from the StateMachine.
	 * @return Status, status_good if no error occurred.
	 */
	Status stop();
	/**
	 * @brief Method that pauses the Job.
	 *
	 * This Method is used to pause the Job. It can be called by
	 * StateFunctions to keep a job from being executed in the
	 * main loop and consequently shorten execution time.
	 * @return Status, status_good if no error occurred.
	 */
	Status pause();
	/**
	 * @brief Method that unpauses the Job.
	 *
	 * This Method is used to unpause a paused Job. It can be called
	 * from StateFunctions to reactivate a paused Job.
	 * @return Status, status_good if no error occurred.
	 */
	Status unpause();
	/**
	 * @brief Method that resets the Job
	 *
	 * This Method is used to reset the Job. It is called by the StateMachine
	 * if the Job has produced an error. The Method should restore
	 * the Job to normal function.
	 * @return
	 */
	Status reset();
	/**
	 * @brief Method that returns the current State of the Job.
	 * @return JobState
	 */
	JobState getJobState();
};

} /* namespace StateMachine */

#endif /* JOB_BASE_JOB_H_ */
