#ifndef K_CA_VIEWSTATE_H
#define K_CA_VIEWSTATE_H

#include "Message.h"
#include "Node.h"


class Node;

class ViewState
{

	enum state_t
	{
        Pre_prepare,
		Prepare,
		Commit,
		Reply
	}_state;


public:
    ViewState();
	ViewState(state_t _st);
    void GetState(const Message & msg);
	void handle_message(Message msg, Node & node);

};


#endif
