/**
 * @date 18.11.2016
 * @author christoph
 * @file Job.cpp
 * 
 *  
 * 
 */

#include "Job.h"

namespace StateMachine {

Job::Job() {
	this->jobState 	= job_stopped;
	this->error = 0;
}

Job::~Job() {

}

Status Job::start() {
}

Status Job::tick() {
}

Status Job::stop() {
}

Status Job::pause() {
}

Status Job::unpause() {
}

Status Job::reset() {
}

JobState Job::getJobState() {
}

} /* namespace StateMachine */
