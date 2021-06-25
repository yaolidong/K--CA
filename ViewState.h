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
		Reply,
	}_state;

	size_t accepeted_prepares = 0;
	size_t accepeted_commits= 0;

public:
    ViewState();
	ViewState(state_t _st);
    std::string GetState(const Message & msg);
	void handle_message(Message msg, Node & node);

};


#endif
