#ifndef K_CA_VIEWSTATE_H
#define K_CA_VIEWSTATE_H

#include "Message.h"
#include <map>


class Node;

class ViewState
{

	enum state_t
	{
	    REQUESTED,
        PRE_PREPARED,
		PREPARED,
		COMMITTED,
	}_state;

    size_t accepted_prepared = 0;
	size_t accepted_committed = 0;


public:
    ViewState();
    ViewState(const ViewState& vt);
    explicit ViewState(const Message& msg);
	void handle_message(Message msg, Node & node);

};


#endif
