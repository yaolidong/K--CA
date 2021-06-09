#ifndef K_CA_FINITESTATEMACHINE_H
#define K_CA_FINITESTATEMACHINE_H

#include "Message.h"

class Node;

class ViewState
{

	enum state_t
	{
	    Requested,
        Pre_prepared,
		Prepared,
		Committed,
		Replyed,
	}_state;

	size_t accepeted_prepares = 0;
	size_t accepeted_commits= 0;

public:
    ViewState(state_t _st);
	void handle_message(Message msg, Node & node);
	static state_t SetState(Message msg);
};
#endif
