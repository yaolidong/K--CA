#include "Message.h"

class Node;

class ViewState
{
	enum state_t
	{
		Requested,
		Prepared,
		Committed,
		Replyed,
	}state_;

	unsigned long accepeted_prepares = 0;
	unsigned long accepeted_commits= 0;

public:
	void handle_message(Message msg, Node & node);
};

